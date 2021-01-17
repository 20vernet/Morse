#include <iostream>
#include "parametre_audio.h"
#include "pre_codage.h"



//ecriture du son
void son(int*code, int length, double dt){
    
    double ti = 0;
    

    for(int i = 0; i < length; i+=1){
        
        if(code[i]>0){
            int val = code[i];
            double tf = ti + dt*val;

            mon_signal(ti, tf, 440, 1.0);

            ti = ti + (val+1)*dt; //on ajoute le blanc après chaque point ou trait d'un même caractère
        }

        if(code[i]<0){
            ti = ti - code[i]*dt;
        }
        
    }
    
}




void code_morse(){
    std::string text;
    std::cout<<"Votre texte : "<<std::endl;
    std::cin>>text;
    int length = text.length();

    int code[length*4] = {0};
    //transformadureon chaine de caractère en tableau d'entier avec le dico

   
    transform_int(text, code, length);

    double dt = 0.2; //durée d'un pas de temps en seconde (de la taille d'un point)

    //calcul de la durée du signal audio

    duree = calcul_duree(code, length*4, dt);
        
    //écriture de l'audio
    FILE *fichier_wav = fopen("morse.wav", "wb");
    ecrire_entete_WAV(fichier_wav);

    son(code, length*4, dt);

    ecrire_donnees_normalisees_WAV(fichier_wav);
    fclose(fichier_wav);

    free(gauche);
    free(droite);
}

