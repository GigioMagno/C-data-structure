

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "qfun.h"

#define NP 50  /*NP = Numero particelle*/
#define HSTEPS 10 /*numero di step tra due output delle coordinate*/
#define TOTALTIME 100
#define DT 1e-3

#define _V 0
#define _Q 1
/*posizione, momento angolare e forza sulle particelle*/
double _pos[NP][4], _omega[NP][4], _newomega[NP][4],_forces[NP][4];
double _omegah[NP][4], _posh[NP][4], _tau[NP][4];

char *blnames[2][4] = { { "_X", "_Y", "_Z", "_I" }, { "YZ", "XZ", "XY", "_S" } };
/*inizializza la posizione e il momento delle particelle*/

/****************************/

void printv(int q, double *v, int dim) {
	int i;
	for (i = 0; i < dim; i++)
		printf("%s:%+lf ", blnames[q][i], v[i]);
	//putchar('\n');
	printf("(%lf)\n", sqrt(mod2(v, dim)));
}

double edist2(double *v1, double *v2, double *diff, int dim) {
	double dist = 0;
	int i;
	for (i = 0; i < dim; i++) {
		diff[i] = v2[i] - v1[i];
		dist += diff[i] * diff[i];
	}

	return dist;
}

/****************************/

void stinitialize() {
	int i, j;
	double phi = 0, dphi;
	FILE *fp;


           
#if (NP > 1)
	dphi = (2 * M_PI) / (NP - 1);
	double v[4];
	v[0] = 0;
	v[1] = 0;
	v[2] = 0.1;
	v[3] = 0;
#if 0
	for(i=0; i < NP; i++, phi += dphi) {
		_pos[i][2] = 0;
		_pos[i][3] = 0;
		_pos[i][0] = cos(phi);
		_pos[i][1] = sin(phi);
		wpVV(_pos[i], v, _omega[i]);
		for(j=0; j < 4; j++)
		_forces[i][j] = 0;
	}
#else
        if ((fp=fopen("primepos.txt","w"))==NULL) {
            perror("");
	    exit(-1);
         }

	for (i = 0; i < NP; i++) {
	    rndv(_omega[i], 3);
	    normalizev(_omega[i], 1.0, 3);
		rndv(_pos[i], 3);		
		normalizev(_pos[i], 1.0, 3);
	        fprintf(fp,"%lf %lf %lf\n", _pos[i][0], _pos[i][1], _pos[i][2]);
		_pos[i][3] = 0;

		wpVV(v, _pos[i], _omega[i]);
		normalizev(_omega[i], M_PI / 4.0, 3);
		_omega[i][3] = 0;
	}
       fclose(fp);
     
#endif

#else
	for (i = 0; i < NP; i++)
	for (j = 0; j < 4; j++) {
		_forces[i][j] = 0;
		_omega[i][j] = 0;
		_pos[i][j] = 0;
	}

	//_forces[0][2] = -1;

	_pos[0][0] = 0.1;
	_pos[0][1] = 0;
	_pos[0][2] = 0.0;

	normalizev(_pos[0], 1.0, 3);

	_omega[0][0] = 0;
	_omega[0][1] = 0.9;
	_omega[0][2] = sqrt(1-(_omega[0][1]*_omega[0][1]));;
#endif

#if 0
	for (i = 0; i < NP; i++) {
		printv(_V, _pos[i], 4);
		printv(_Q, _omega[i], 4);
	}

	exit(0);
#endif
}

#define MODF 1.0

double getPotential(double *p1, double *p2, double *force) {
	double potential, edist, mf;

	edist = sqrt(edist2(p1, p2, force, 3));
	potential = MODF * exp(-edist * edist);
	mf = MODF * 2 * edist * potential;
	normalizev(force, fabs(mf), 3);
	force[3] = 0;
	return potential;
}

double getPotential2(double *p1, double *p2, double *force) {
	double potential, edist, mf;

	edist = sqrt(edist2(p1, p2, force, 3));
	potential = -MODF / edist;
	mf = MODF / (edist * edist);
	normalizev(force, fabs(mf), 3);
	force[3] = 0;
	return potential;
}

double getTau(double pos[][4], double tau[][4]) {
	int i, j, k;
	double d, potential = 0;
	double force[4];
	double z;

#if (NP > 1)
	for (i = 0; i < NP; i++)
		for (k = 0; k < 4; k++)
			_forces[i][k] = 0;

	for (i = 0; i < NP; i++) {
		for (j = i + 1; j < NP; j++) {
			potential += getPotential(pos[i], pos[j], force);

			for (k = 0; k < 3; k++) {
				_forces[i][k] += force[k];
				_forces[j][k] -= force[k];
			}
		}
	}
#else
	z = pos[0][2];
	potential = z*z*exp(-z*z); /*xxxxxxxxxxxxxxxxxxxx*/
	_forces[0][2] = 2*z*exp(-z*z)*(z*z -1);
#endif
	for (i = 0; i < NP; i++) {
		wpVV(_forces[i], pos[i], tau[i]);
		//printv(_V, _forces[i], 3);
	}
	return potential;
}

void printinfo(int i) {
	fprintf(stderr, "pos[%d] = ", i);
	printv(_V, _pos[0], 3);
	fprintf(stderr, "tdt[%d] = ", i);
	printv(_Q, _tau[0], 3);
	fprintf(stderr, "mom[%d] = ", i);
	printv(_Q, _omega[0], 3);
	fprintf(stderr, "\n");
}

void printall(double v[][4], int nrows, int dim) {
	int i, j;
	for (i = 0; i < nrows; i++) {
		for (j = 0; j < dim; j++)
			printf("%f ", v[i][j]);
		putchar('\n');
	}
}

void gettmom(double *tmom) {
	int i, k;
	for (k = 0; k < 4; k++)
		tmom[k] = 0;
	for (i = 0; i < NP; i++)
		for (k = 0; k < 4; k++)
			tmom[k] += _omega[i][k];

}

void getNewPos(double dt, double omega[][4], double oldpos[][4], double newpos[][4]) {
	double q[4], theta, m2;
	int i, j;

	for (i = 0; i < NP; i++) {

		/*
		 * calcolo theta, l'angolo di rotazione nel piano identificato dai
		 * momenti precedentemente calcolati
		 */
		copyv(omega[i], q, 1, 4);
		m2 = mod2(omega[i], 3);
		theta = m2 > 0 ? sqrt(m2) : 0;
		theta *= dt;
		/*
		 * costruisco il quaternione per la rotazione di un angolo theta nel
		 * piano identificato dal momento angolare
		 */
		getquaternion(theta, q);
		/*aggiorno le posizioni*/
		rotate(q, oldpos[i], newpos[i]);
	}
}

double getNewOmega(double dt, double tau[][4], double omega[][4]) {
	int i, j;
	double energy = 0;

	for (i = 0; i < NP; i++)
		for (j = 0; j < 3; j++) {
			energy += omega[i][j] * omega[i][j];
			omega[i][j] += tau[i][j] * dt;
		}
	energy /= 2;
	return (energy);
}

#if 0
/*Half Verlet*/
void step(double dt, double *potential, double *energy) {

	*energy = getNewOmega(dt/2.0, _tau, _omega, _omegah);
	getNewPos(dt, _omegah, _pos, _posfinale);
	*potential = getTau(_posfinale, _tau);

	*energy = getNewOmega(dt/2, _tau, _omegah, _omega);

}

#else
void step(double dt, double *potential, double *energy) {

	*potential = getTau(_pos, _tau);

	*energy = getNewOmega(dt, _tau, _omega);

	getNewPos(dt, _omega, _pos, _pos);
}
#endif

void testx() {
	double p[4] = { 1, 0, 1, 0 };
	double f[4] = { 0, 0, 1, 0 };
	double r[4];
	wpVV(p, f, r);
	printv(_V, r, 3);
	exit(0);
}

int main(int argc, char **argv) {
	int i, k, niters;
	double tmom[4];
	double potential, cenergy;
	srand(0*time(NULL));
	stinitialize();
	double totalTime = TOTALTIME;
	double dt=DT;

	niters = (int) floor((totalTime / dt) + 0.5);

	step(0, &potential, &cenergy);

	for (i = 0; i < niters; i++) {
		step(dt, &potential, &cenergy);

		if ((i % HSTEPS) == 0) {
			printall(_pos, NP, 3);
			//printinfo(0);
			fprintf(stderr,"%lf %lf %lf\n", potential, cenergy, (cenergy + potential));
		}

	}

	return 0;
}
