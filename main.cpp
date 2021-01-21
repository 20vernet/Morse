#include <iostream>
#include "code_morse.h"
#include "decode_morse.h"

int main(){
    int quoi;

    // On demande à l'utilisateur ce qu'il souhaite faire

    std::cout<<"Que voulez-vous faire ?"<<std::endl;
    std::cin>>quoi;

    // Selon la réponse de l'utilisateur, on lance le codeur ou le décodeur

    if(quoi == 1){
        code_morse();
    }
    if(quoi == 2){
        decode_morse();
    }

}