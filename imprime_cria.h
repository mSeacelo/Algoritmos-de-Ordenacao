
#ifndef IMPRIME_CRIA_H
#define IMPRIME_CRIA_H
#include "ordena.h"
#include <stdlib.h>
#include <stdio.h>




void imprimeV(Item* v, int n);
Item* aleatorio(int tamanho);
Item* ordenado(int tamanho);
Item* ordenadoInverso(int tamanho);
Item* umdeso(int tamanho);

/*heap*/

void imprimeV_heap(Item* v, int n);
Item* aleatorio_heap(int tamanho);
Item* ordenado_heap(int tamanho);
Item* ordenadoInverso_heap(int tamanho);
Item* umdesoH(int tamanho);

/*insertO*/
Item* aleatorioI(int tamanho);
Item* ordenadoI(int tamanho);
Item* ordenadoInversoI(int tamanho);
Item* ordenadoInversoI(int tamanho);
Item* umdesoI(int tamanho);
#endif //IMPRIME_CRIA_H
