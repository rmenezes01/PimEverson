#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include "../header/comum.h"
#include "../header/login.h"

bool loginSistema(){
    stUsuario usuarioSistema, usuarioSistema_comp = {0};

    chamaTelaLogin();
    usuarioSistema = trataInputLogin();

    return memcmp(usuarioSistema.codusu, usuarioSistema_comp.codusu, sizeof(usuarioSistema.codusu)) == 0;

}

void chamaTelaLogin(){
    consoleTela();
    desenhaTelaPadrao();
    desenhaTelaLogin();
}

stUsuario validaUsuario(stUsuLogin usuInput){
   // Valida se os usuario e senha estão prreenchidos
   FILE *tabelaUsuario;
   stUsuario UsuarioSystem;
   int c;

   // Validar se o usuario e senha estão preenchidos
  memset(&UsuarioSystem, '\0' , sizeof(UsuarioSystem));
  if((tabelaUsuario = fopen("./BancoDados/T_usuario.dat","rb"))==NULL)
  {
    exibeMensagemSistema("Arquivo nao pode ser aberto.\n");
  }

   while(fread(&UsuarioSystem, sizeof(UsuarioSystem), 1, tabelaUsuario))
   {
     if ( strcmp(UsuarioSystem.codusu,usuInput.codusu) == 0 &&
          strcmp(UsuarioSystem.senhausu,usuInput.senhausu) != 0 ){
        exibeMensagemSistema("Senha incorreta!");
        memset(&UsuarioSystem, '\0' , sizeof(UsuarioSystem));
        fclose(tabelaUsuario);
        return UsuarioSystem;
     }
     else if ( strcmp(UsuarioSystem.codusu,usuInput.codusu) == 0 &&
               strcmp(UsuarioSystem.senhausu,usuInput.senhausu) == 0 ){
        exibeMensagemSistema("Usuario Logado!");
        fclose(tabelaUsuario);
        return UsuarioSystem;
     }
   }

   memset(&UsuarioSystem, '\0' , sizeof(UsuarioSystem));
   exibeMensagemSistema("Usuario nao encontrado!");
   fclose(tabelaUsuario);
   return UsuarioSystem;
};

stUsuLogin inputUsuarioLogin(){
 char cInput;
 int i = 0;
 stUsuLogin retunrUsuLogin;

 // Posiciona a entrada do usuário
 memset(retunrUsuLogin.codusu, '\0' , sizeof(retunrUsuLogin.codusu));
 memset(retunrUsuLogin.senhausu, '\0' , sizeof(retunrUsuLogin.senhausu));
 setCursorXY(40,11);
 do{
      cInput = getch();
      if (cInput == BACKSPACE && i > 0){
        retunrUsuLogin.codusu[i] = '\0';
        printf("\b \b");
        i--;
      }
      else if(cInput != BACKSPACE &&
              cInput != ENTER &&
              cInput != SPACE &&
              i != S_CODUSU) {
        //printf("%c",cInput);
        putch(cInput);
        retunrUsuLogin.codusu[i] = cInput;
        i++;
      };
 }while (cInput != ENTER); // Verificar se o usuario apertar enter primeiro

 // Posiciona a entrada do Senha
  i = 0;
  setCursorXY(40,12);
 do{
      cInput = getch();

      if (cInput == BACKSPACE && i > 0){
        retunrUsuLogin.senhausu[i] = '\0';
        printf("\b \b");
        i--;
      }
      else if(cInput != BACKSPACE &&
              cInput != ENTER &&
              cInput != SPACE &&
              i != S_SENHAUSU) {
        putch('*');
        retunrUsuLogin.senhausu[i] = cInput;
        i++;
      };
 }while (cInput != ENTER); // Verificar se o usuario apertar enter primeiro

 return retunrUsuLogin;
};

stUsuario trataInputLogin(){
 stUsuario returnUsuario = {0};
 memset(&returnUsuario,'\0',sizeof(returnUsuario));
 returnUsuario = validaUsuario(inputUsuarioLogin());
 return returnUsuario;
};

void desenhaTelaLogin(){
 stUsuLogin usuLogin;
 stUsuario usuarioSistema;
 memset(&usuLogin, '\0', sizeof(usuLogin));

 // Entrada de textos do login
 setCursorXY(30,11);
 printf("Usuario :");
 setCursorXY(30,12);
 printf("Senha   :");

  // Apaga dados de entrada Usuario e Senha
 setCursorXY(40,11);
 char clearUsuario[S_CODUSU + 1];
 memset( clearUsuario, ' ', sizeof clearUsuario - 1 );
 clearUsuario[sizeof clearUsuario] = '\0';
 printf(clearUsuario);

  setCursorXY(40,12);
 char clearSenha[S_SENHAUSU + 1];
 memset( clearSenha, ' ', sizeof clearSenha - 1 );
 clearSenha[sizeof clearSenha] = '\0';
 printf(clearSenha);

}
