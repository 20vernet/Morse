#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define PI 3.14159265358979323846264338327
#define AMPLITUDE_MAXI 32767

unsigned int taux ;
unsigned long int taille ;
double *gauche, *droite ;
double duree ;

void ecrire_little_endian(unsigned int octets, int taille, FILE *fichier);
void ecrire_donnees_normalisees_WAV(FILE *fichier);
void mon_signal(double t1, double t2, double f, double Amp);
void ecrire_entete_WAV(FILE *fichier);
void ecriture_audio(double ti, double tf);