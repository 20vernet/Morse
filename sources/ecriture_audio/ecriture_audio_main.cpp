#include <parametre_audio.h>


int main(){
    FILE *fichier_wav = fopen("morse.wav", "wb");
    ecrire_entete_WAV(fichier_wav);

    mon_signal(0.0, 5.0, 440.0, 1.0);
    ecrire_donnees_normalisees_WAV(fichier_wav);
    fclose(fichier_wav);

    free(gauche);
    free(droite);
}