#include "parametre_audio.h"


void mon_signal(double t1, double t2, double f, double Amp) {
    unsigned int i;
    double omega = 2 * PI * f ;
    double t = 0 ;
    double dt = 1.0 / taux ;
    double phi = 0 ;

    for (i=(unsigned int)(t1*taux) ; i<(unsigned int)(t2*taux) ; i=i+1) {
        gauche[i] = gauche[i] + Amp * sin(omega*t + phi) ;
        droite[i] = droite[i] + Amp * sin(omega*t + phi) ;
        t = t + dt ;
    }
}