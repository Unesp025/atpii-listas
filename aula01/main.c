#ifndef _ESTRUTURASC_
#define _ESTRUTURASC_
#include "menu.c"

int main()
{
  No *lista = NULL;
  menu(lista);
  if (lista != NULL) liberarNo(lista);
  printf("\n\nPrograma finalizado.");
  return 0;
}
#endif