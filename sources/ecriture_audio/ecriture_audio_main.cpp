#include "parametre_audio.h"


void ecriture_audio(double ti, double tf){
    FILE *fichier_wav = fopen("morse.wav", "wb");
    ecrire_entete_WAV(fichier_wav);

    mon_signal(ti, tf, 440.0, 1.0);
    ecrire_donnees_normalisees_WAV(fichier_wav);
    fclose(fichier_wav);

    free(gauche);
    free(droite);
}
