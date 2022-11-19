#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include "../header/comum.h"
#include "../header/menuSistema.h"

int menuSistema(){
   chamaTelaMenu();

    setCursorXY(10,20);
    printf("Digitar opção do menu: ");
    int i;
    scanf("%i", &i);
    printf("%i\n", i);
    return i;

};

void desenhaTelaMenu(){
 // Tela de Menu
 setCursorXY(30,4);
 printf("1 - Cadastro de usuario");
 setCursorXY(30,5);
 printf("0 - Finalizar");
};

void chamaTelaMenu(){
  consoleTela();
  desenhaTelaPadrao();
  desenhaTelaMenu();
}
