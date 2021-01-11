#include <parametre_audio.h>

void ecrire_entete_WAV(FILE *fichier) {
    unsigned short int nb_canaux = 2 ;
    unsigned short int nb_bits = 16 ;
    taux = 44100 ; // En Hz
    duree = 60 ; // En secondes
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