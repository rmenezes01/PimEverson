#include "../header/comum.h"
#include <windows.h>
#include <conio.h>
#include <unistd.h>
#include "string.h"
#include <stdio.h>

struct moldura {
            unsigned char vertical       ;
            unsigned char horizontal     ;
            unsigned char up_corner_left ;
            unsigned char up_corner_right;
            unsigned char dw_corner_left ;
            unsigned char dw_corner_right;
            unsigned char dw_double_corner_left;
            unsigned char dw_double_corner_right;
            } moldura = {186,205,201,187,200,188,204,185};

// Define tela titulo e tamanho da tela do sistema
void consoleTela() {
    // Define tamanho da tela do sistema
    SMALL_RECT windowSize = {0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1};
    COORD bufferSize = { SCREEN_WIDTH , SCREEN_HEIGHT };
    HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);

    // Título tela do sistema
    SetConsoleTitle("Sistema de Farmacia");
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    SetConsoleScreenBufferSize(wHnd, bufferSize);

    //
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(wHnd, &info);
    COORD new_size =
    {
        info.srWindow.Right - info.srWindow.Left,
        info.srWindow.Bottom - info.srWindow.Top
    };
    SetConsoleScreenBufferSize(wHnd, new_size);

    HWND consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}

// Seta cursor
void setCursorXY(int x, int y)
{
  COORD c;
  c.X = x;
  c.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// Desenha tela padrao do sistema
void desenhaTelaPadrao()
{
 int linha,coluna;
 system("cls");
 setCursorXY(0,0);
 putchar(moldura.up_corner_left);
 setCursorXY(LIMITMOD,0);
 putchar(moldura.up_corner_right);
 setCursorXY(LIMITMOD,24);
 putchar(moldura.dw_corner_right);
 setCursorXY(0,24);
 putchar(moldura.dw_corner_left);

 for(coluna=1;coluna<=LIMITMOD-1;coluna++)
 {
   setCursorXY(coluna,0);
   putchar(moldura.horizontal);
   setCursorXY(coluna,24);
   putchar(moldura.horizontal);
   setCursorXY(coluna,22);
   putchar(moldura.horizontal);
 }

 for(linha=1;linha<=23;linha++)
 {
   setCursorXY(LIMITMOD,linha);
   putchar(moldura.vertical);
   setCursorXY(0,linha);
   putchar(moldura.vertical);
 }
 setCursorXY(0,22);
 putchar(moldura.dw_double_corner_left);
 setCursorXY(LIMITMOD,22);
 putchar(moldura.dw_double_corner_right);

 setCursorXY(22,23);
 printf("Sistema Farmacia PIM - V.1.0");
 setCursorXY(20,11);
}

void exibeMensagemSistema( char itext[SIZE_LIMITE_MESSAGE] ){
 char clearLine[SCREEN_WIDTH];
 memset( clearLine, ' ', sizeof clearLine - 1 );
 clearLine[sizeof clearLine - 1] = '\0';

 setCursorXY(1,25);
 printf(itext);

 setCursorXY(1,26);
 system("PAUSE");

 // Apagar linha da mensagem
 setCursorXY(1,25);
 printf(clearLine);

  // Apagar linha da confirmação do pause
 setCursorXY(1,26);
 printf(clearLine);
}
