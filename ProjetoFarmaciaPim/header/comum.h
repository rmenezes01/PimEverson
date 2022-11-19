#include <stdio.h>
#include <windows.h>
#include <conio.h>

#ifndef COMUM_H_INCLUDED
#define COMUM_H_INCLUDED

    #define SCREEN_WIDTH 80   // TAMANHO GERAL DA TELA CONSOLE
    #define LIMITMOD 79       // LIITE PARA O PRINT DA TELA
    #define SCREEN_HEIGHT 30  // ALTURA DA TELA
    #define SIZE_LIMITE_MESSAGE 70 // LIMITE DO TAMANHO DAS MENSAGENS DE RODAPÉ
    #define ENTER 13    // CÓDIGO ASCII DA TECLA ENTER
    #define BACKSPACE 8 // CÓDIGO ASCII DA TECLA BACKSPACE
    #define SPACE 32    // CÓDIGO ASCII DA TECLA BARRA DE ESPACO

#endif // COMUM_H_INCLUDED

void consoleTela();
void desenhaTelaPadrao();
void exibeMensagemSistema();
