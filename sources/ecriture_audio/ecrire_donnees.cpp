#include <parametre_audio.h>


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