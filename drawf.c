

#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include "netpbm.h"


typedef struct  {
   double v[2], g, dt, tf;
} PARAMETERS;


void motoparabolico(PARAMETERS p, GRAYMAP gm) {
    double x=0, y=0, vx, vy, t;
    int ix, iy;
     vx = p.v[0];
     vy = p.v[1];
     for(t=0; t < p.tf; t+= p.dt) {
	ix = round(x);
        iy = gm.nrows - round(y);
        if (((ix >=0) && (ix < gm.ncols)) && ((iy >=0) && (iy < gm.nrows)))
            gm.mat[iy][ix] = 250;
        x += vx*p.dt;
        y += vy*p.dt;
        vy -= p.g*p.dt;
     }
}


int main() {
	PARAMETERS p;
        GRAYMAP gm;
        gm.nrows=gm.ncols=256;
	gm.mat = (unsigned char**) mymatalloc(gm.nrows, gm.ncols, sizeof(unsigned char));
        p.g = 9.8;
        p.v[0] = 30;
        p.v[1] = 60;
        p.tf = 10;
        p.dt = 0.05;
	motoparabolico(p, gm);
	writePGM(gm.mat, gm.nrows, gm.ncols);

}

