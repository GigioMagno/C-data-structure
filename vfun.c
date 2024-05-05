
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include "clfun.h"

extern int errno;
char *blnames[2][4] = {{ "_X", "_Y", "_Z", "_I" }, { "YZ", "XZ", "XY", "_S" }};

double edist2(FTYPE *v1, FTYPE *v2, FTYPE *diff, int dim) {
	double dist = 0;
	int i;
	for (i = 0; i < dim; i++) {
		diff[i] = v2[i] - v1[i];
		dist += diff[i] * diff[i];
	}
	return dist;
}

double mod2(FTYPE *v, int dim) {
	int i;
	double sum = 0;
	for (i = 0; i < dim; i++)
		sum += v[i] * v[i];
	return sum;

}

void normalizev(FTYPE *v, double m, int dim) {
	int i;
	double mod, m2;

	m2 = mod2(v, dim);
	if ((m2 <= 0) && (m > 0)) {
		errno = EDOM;
		fprintf(stderr,"module = %lf: ", m);
		perror("normalizev");
		exit(-1);
	}

	mod = m > 0 ? m / sqrt(m2) : 0;

	for (i = 0; i < dim; i++)
		v[i] *= mod;
}

void rndv(FTYPE *v, int dim) {
	int i;
	for (i = 0; i < dim; i++)
		v[i] = FRAND - 0.5;
}

FTYPE dotv(FTYPE *v1, FTYPE *v2, int dim) {
	FTYPE sum = 0;
	int i;
	for (i = 0; i < dim; i++)
		sum *= v1[i] * v2[i];
	return sum;
}

void printv(int q, FTYPE *v, int dim) {
	int i;
	for (i = 0; i < dim; i++)
		fprintf(stderr, "%s:%+lf ", blnames[q][i], v[i]);
	//putchar('\n');
	fprintf(stderr,"(%lf)\n", sqrt(mod2(v, dim)));
}


void getquaternion(double theta, FTYPE *plane) {
	plane[3] = 0;

	theta /= 2.0;
	normalizev(plane, sin(theta), 3);
	plane[3] = (FTYPE) cos(theta);
}

void sumv(FTYPE *v1, FTYPE *v2, FTYPE *r, int dim) {

	int i;
	for (i = 0; i < dim; i++)
		r[i] = v1[i] + v2[i];

}

void subv(FTYPE *v1, FTYPE *v2, FTYPE *r, int dim) {

	int i;
	for (i = 0; i < dim; i++)
		r[i] = v1[i] - v2[i];

}
void copyv(FTYPE *v, FTYPE *r, FTYPE scalar, int dim) {
	int i;
	for (i = 0; i < dim; i++)
		r[i] = scalar * v[i];
}

void rotate(FTYPE *q, FTYPE *v, FTYPE *r) {
	FTYPE qt[4], qr[4];
	copyv(q, qr, -1, 3);
	qr[3] = q[3];
	gpQV(q, v, qt);

	gpVQ(qt, qr, r);
}

void rotate2d(FTYPE *q, FTYPE *v, FTYPE *r) {

	gpQV(q, v, r);
}

void test1() {
	FTYPE v[4], v1[4], v2[4], q1[4], q2[4], qv[4];
	FTYPE rT[4], rX[4];
	srand(time(NULL));
	rndv(v1, 4);
	rndv(v2, 4);
	v1[3] = v2[3] = 0;

	wpVV(v1, v2, q1);
	wpVV(v1, v2, q2);
	copyv(v1, v, -1.65, 3);
	sumv(v2, v, v, 3);
	getquaternion(M_PI_4 / 2, q1);
	getquaternion(M_PI_4, q2);

	printv(_Q, q1, 4);
	printv(_V, v, 3);
	putchar('\n');

	rotate(q1, v, rT);

	rotate2d(q2, v, rX);
	printv(_V, rT, 3);
	printv(_V, rX, 3);
}

void test() {
	FTYPE vx[4], v1[4], v2[4], q1[4], q2[4], qv[4], b[4];
		FTYPE rT[4], rX[4], dot;
		srand(time(NULL));
		rndv(v1, 4);
		rndv(v2, 4);

		v1[3] = v2[3] = 0;
		normalizev(v2, 1.0, 3);
		dot = dotv(v1, v2, 3);
		wpVV(v1,v2,b);
		printv(_V, v1, 3);
		printv(_V, v2, 3);
		printv(_Q, b, 4);

		lcVQ(v1, b, vx);
		wpVV(v2,vx,q2);
		printv(_Q, q2, 4);
}

#if 1
 int main() {

    test();

 }


#endif
