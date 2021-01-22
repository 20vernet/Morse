#include <iostream>
#include <fstream>
#include "parametre_audio.h"
#include "pre_codage.h"



// Ecriture du son
void son(int*code, int length, double dt){
    
    // Définition du temps initial
    double ti = 0;
    

    for(int i = 0; i < length; i+=1){
        
        if(code[i]>0){
            // Dans ce cas, on a la durée du son (1 pour un . et 3 pour un -)
            int val = code[i];
            double tf = ti + dt*val;

            // On écrit une sinusoïde de durée dt ou 3*dt
            mon_signal(ti, tf, 440, 1.0);

            // On ajoute le blanc après chaque point ou trait d'un même caractère
            ti = ti + (val+1)*dt; 
        }

        if(code[i]<0){
            // Dans ce cas, on a un blanc.
            // On incrémente juste la position du temps initial en fonction de la durée du blanc
            ti = ti - code[i]*dt;
        }
        
    }
    
}




void code_morse(){

    // On demande à l'utilisateur l'adresse du fichier texte à coder

    std::string chemin;
    std::cout<<"Chemin du texte à coder : "<<std::endl;
    std::cin>>chemin;
    

    // Ouverture du fichier
    std::ifstream fichier_lu (chemin);

    if(fichier_lu.is_open()){

        // Lecture du fichier
        std::string text;
        std::getline(fichier_lu, text);

        // Longueur de la chaîne de caractère à coder
        int lon = text.length();
    
        // Fermeture du fichier
        fichier_lu.close();

        // Transformation de la chaine de caractère en tableau d'entiers avec le dictionnaire fr_to_morse
        int code[lon*4] = {0};
   
        transform_int(text, code, lon);

        // Durée d'un pas de temps en seconde (de la taille d'un point)
        double dt = 0.2; 

        // Calcul de la durée du signal audio

        duree = calcul_duree(code, lon*4, dt);
        
        // Ecriture de l'audio
        FILE *fichier_wav = fopen("morse.wav", "wb");
        ecrire_entete_WAV(fichier_wav);

        son(code, lon*4, dt);

        ecrire_donnees_normalisees_WAV(fichier_wav);
        fclose(fichier_wav);

        free(gauche);
    }

    else{
        std::cout<<"Le fichier texte n'existe pas"<<std::endl;
    }
}

