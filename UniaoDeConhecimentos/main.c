#include "InterfaceLinhaComando.c"

int main()
{
    No *listaCadastros = NULL;
    menu(listaCadastros);

    noLiberarEspacoMemoria(listaCadastros);
    return 0;
}