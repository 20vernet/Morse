#include <iostream>
#include "parametre_audio.h"
#include <map>
#include <string>

std::map<char, std::string> fr_to_morse;

//à mettre autre part
void transform_int(std::string text, int* code, int length){
    int ind_int = 0;
    
     
    for(int i = 0; i < length; i+=1){
        
        char let = text[i];
        std::string letter = fr_to_morse[let];

        int lon = letter.length();

      
        for(int k = 0; k < lon; k+=1){
        
            if(letter[k] == ' '){
                code[ind_int + k] = -4; //normalment -7, mais on mais -3 après chaque lettre
            }
            else if(letter[k] == '.'){
                code[ind_int + k] = 1;
            }
            else if(letter[k] == '-'){
                code[ind_int + k] = 3;
            }
        

        }
        //on a mis une lettre, on ajoute l'espace de -1-2 pour signifier la fin de la lettre (car on ajoute -1
        //à chaque symbole mis en audio)
        code[ind_int + lon] = -2;

        //on passe à la lettre suivante
        ind_int = ind_int + lon + 1;
    }
}


double calcul_duree(int*code, int length){
    double dt = 0.2; //durée d'un pas de temps en seconde (de la taille d'un point)
    //calculer la durée du signal max
    double dure = 0;
    

    for(int i = 0; i < length; i+=1){
        
        if(code[i]>0){
            int val = code[i];

            dure = dure + (val+1)*dt; //on ajoute le blanc après chaque point ou trait d'un même caractère
        }

        if(code[i]<0){
            dure = dure - code[i]*dt;
        }
       
    }
    return(dure);
}

//ecriture du son
void son(int*code, int length){
    double dt = 0.2; //durée d'un pas de temps en seconde (de la taille d'un point)
    //calculer la durée du signal max
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
    //transformadureon chaine de caractère en tableau d'endureers avec le dico

    //dico
    fr_to_morse[','] = " ";
    fr_to_morse['A'] = ".-";
    fr_to_morse['B'] = "-...";
    fr_to_morse['C'] = "-.-.";
    fr_to_morse['D'] = "-..";
    fr_to_morse['E'] = ".";
    fr_to_morse['F'] = "..-.";
    fr_to_morse['G'] = "--.";
    fr_to_morse['H'] = "....";
    fr_to_morse['I'] = "..";
    fr_to_morse['J'] = ".---";
    fr_to_morse['K'] = "-.-";
    fr_to_morse['L'] = ".-..";
    fr_to_morse['M'] = "--";
    fr_to_morse['N'] = "-.";
    fr_to_morse['O'] = "---";
    fr_to_morse['P'] = ".--.";
    fr_to_morse['Q'] = "--.-";
    fr_to_morse['R'] = ".-.";
    fr_to_morse['S'] = "...";
    fr_to_morse['T'] = "-";
    fr_to_morse['U'] = "..-";
    fr_to_morse['V'] = "...-";
    fr_to_morse['W'] = ".--";
    fr_to_morse['X'] = "-..-";
    fr_to_morse['Y'] = "-.--";
    fr_to_morse['Z'] = "--..";
    
    //fin dico
    transform_int(text, code, length);


    //udurelisadureon de mon_signal en boucle sur le tableau d'endureers code
    //comme ça on connait la durée totale du signal

    duree = calcul_duree(code, length*4);
        
    //écriture de l'audio
    FILE *fichier_wav = fopen("morse.wav", "wb");
    ecrire_entete_WAV(fichier_wav);

    son(code, length*4);

    ecrire_donnees_normalisees_WAV(fichier_wav);
    fclose(fichier_wav);

    free(gauche);
    free(droite);
}


//nettoyer un peu : transfirm_int et calcul_duree dans un autre fichier
