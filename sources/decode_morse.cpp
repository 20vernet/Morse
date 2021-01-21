#include <iostream>
#include <fstream>
#include "pre_decodage.h"



void decode_morse(){
    // On récupére l'emplacement du fichier audio à lire
    std::string empl = lecture();
    
    // empl est l'adresse du fichier texte en morse pour le décodeur
    // Il est générer par la fonction lecture à partir d'un fichier audio
    
    // Ouverture du fichier
    std::ifstream fichier_lu (empl);

    // Lecture du fichier texte en morse
    std::string contenu;
    std::getline(fichier_lu, contenu);

    // Longueur du code morse écrit
    int lon = contenu.length();

    // Séparation de contenu en tableau de string avec une lettre morse = une string
    std::string separe[lon];
    int lon_message = separe_lettre(contenu, separe);

    // Ecriture de chaque caractère dans un fichier .txt
    ecrire_fichier(separe, lon_message);


    // Fermeture du fichier
    fichier_lu.close();
}
