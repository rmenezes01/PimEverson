#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED

#define S_CODUSU 15
#define S_SENHAUSU 15
#define S_NOMEUSU 60


#endif // LOGIN_H_INCLUDED

typedef struct {
    char codusu[S_CODUSU];
    char senhausu[S_SENHAUSU];
}stUsuLogin;

typedef struct {
    char codusu[S_CODUSU];
    char senhausu[S_SENHAUSU];
    char nome[S_NOMEUSU]
}stUsuario;

bool loginSistema();
void chamaTelaLogin();
stUsuario trataInputLogin();
stUsuario validaUsuario(stUsuLogin stUsuLogin);
stUsuLogin inputUsuario();
