#include "lista-encadeada.c"

int main()
{
  No *lista = inicializarNo(1);
  adicionarNo(lista, 3);
  adicionarNo(lista, 5);
  adicionarNo(lista, 7);
  imprimirNo(lista);

  // removerNoByValor(lista, 3);
  // imprimirNo(lista);

  liberarNo(lista);
  return (0);
}