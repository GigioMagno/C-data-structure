#include <stdio.h>
void motoparabolico(double v[], double r, double g, double m, double dt, double tf) {
     double x=0, y=0, t;

     for(t=0; t < tf; t+= dt) {
	printf("%lf %lf\n", x, y);
        x += v[0]*dt;
        y += v[1]*dt;
        v[1] -= g*dt;
        v[0] -= v[0]*r*dt/m;
        v[1] -= v[1]*r*dt/m;
     }
}


main() {
   double v[] = {30,60};
   double tf=10, dt=0.05, g=9.8, r=0.1, m=1;
   motoparabolico(v, r, g, m, dt, tf);

}
