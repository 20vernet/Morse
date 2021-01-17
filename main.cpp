#include <iostream>
#include "code_morse.h"
//#include "decode_morse.h"

int main(){
    int quoi;
    std::cout<<"Que voulez-vous faire ?"<<std::endl;
    std::cin>>quoi;
    if(quoi == 1){
        code_morse();
    }
    //if(quoi == 2){
    //    decode_morse();
    //}

}