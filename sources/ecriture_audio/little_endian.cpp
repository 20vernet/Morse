#include "parametre_audio.h"

void ecrire_little_endian(unsigned int octets, int taille, FILE *fichier) {
    unsigned char faible ;

    while(taille > 0) {
        faible = octets & 0x000000FF ;
        fwrite(&faible, 1, 1, fichier) ;
        octets = octets >> 8 ;
        taille = taille - 1 ;
    }
}
