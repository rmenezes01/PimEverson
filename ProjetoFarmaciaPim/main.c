#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

// Vari�veis globais
bool exitLoop = false;
void main()
{
    while( exitLoop == false){
        if ( loginSistema() == 0){
            exitLoop = true;
        };
    };
    exitLoop = false;
    while(exitLoop==false){
       if ( menuSistema() == 0){exitLoop = true;}

    }
}
