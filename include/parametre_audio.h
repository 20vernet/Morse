#pragma once

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define PI 3.14159265358979323846264338327
#define AMPLITUDE_MAXI 32767

unsigned int taux ;
unsigned long int taille ;
double *gauche, *droite ;
double duree ;

void ecrire_little_endian(unsigned int octets, int taille, FILE *fichier) {
    unsigned char faible ;

    while(taille > 0) {
        faible = octets & 0x000000FF ;
        fwrite(&faible, 1, 1, fichier) ;
        octets = octets >> 8 ;
        taille = taille - 1 ;
    }
}

void ecrire_donnees_normalisees_WAV(FILE *fichier) {
    unsigned int i ;
    double maxi = 1e-16 ;

    for (i = 0 ; i < taille ; i=i+1) {
        if (fabs(gauche[i]) > maxi) maxi = fabs(gauche[i]) ;
        if (fabs(droite[i]) > maxi) maxi = fabs(droite[i]) ;
    }

    for (i = 0 ; i < taille ; i=i+1) {
        ecrire_little_endian((int)(gauche[i]/maxi*AMPLITUDE_MAXI), 2, fichier) ;
        ecrire_little_endian((int)(droite[i]/maxi*AMPLITUDE_MAXI), 2, fichier) ;
    }
}


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

void ecrire_entete_WAV(FILE *fichier) {
    unsigned short int nb_canaux = 2 ;
    unsigned short int nb_bits = 16 ;
    taux = 44100 ; // En Hz
    //duree est définie après la génération des tableaux gauche et droit dans son (codage)
    taille = taux * duree ;
    unsigned long int nb_octets_donnees = (nb_bits / 8) * nb_canaux * taille ;

    gauche = (double*) calloc(taille, sizeof(double)) ;
    droite = (double*) calloc(taille, sizeof(double)) ;

    fwrite("RIFF", 4, 1, fichier) ;
    ecrire_little_endian(36 + nb_octets_donnees, 4, fichier) ;
    fwrite("WAVE", 4, 1, fichier) ;

    fwrite("fmt ", 4, 1, fichier) ;
    ecrire_little_endian(16, 4, fichier) ;
    ecrire_little_endian(1, 2, fichier) ;
    ecrire_little_endian(nb_canaux, 2, fichier) ;
    ecrire_little_endian(taux, 4, fichier) ;
    ecrire_little_endian(taux * nb_canaux * (nb_bits / 8), 4, fichier) ;
    ecrire_little_endian(nb_canaux * (nb_bits / 8), 2, fichier) ;
    ecrire_little_endian(nb_bits, 2, fichier) ;

    fwrite("data", 4, 1, fichier) ;
    ecrire_little_endian(taille * nb_canaux * (nb_bits / 8), 4, fichier) ;
}
