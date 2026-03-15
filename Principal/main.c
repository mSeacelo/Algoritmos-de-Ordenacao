#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "ordena.h"
#include "imprime_cria.h"
#include <string.h>
#include<limits.h>


int main(int argc, char* argv[]) {
    char* alg = argv[1];
    int   tamanho = atoi(argv[2]);
    char* ordem = argv[3];
    int print = (argc == 5);
    Item* v = NULL;
    long long int comparacoes = 0;
    long long int atribuicoes = 0;
    clock_t inicio, fim;
    double tempo_gasto;
    printf("%*s: %d\n",  14, "INT_MAX", INT_MAX);
    printf("%*s: %d\n",  14, "RAND_MAX", RAND_MAX);
    printf("%*s: %ld\n", 14, "LONG_MAX", LONG_MAX);
    printf("%*s: %ld\n", 14, "CLOCKS_PER_SEC", CLOCKS_PER_SEC);
    printf("\n* * *\n\n");

    printf("\n\ncriando vetor de tamanho = %d e de ordem = %s\n", tamanho, ordem);

    if (strcmp(alg, "heapsort") == 0) {
        if (strcmp(ordem, "ale") == 0) {
            v = aleatorio_heap(tamanho);
        } else if (strcmp(ordem, "ordc") == 0) {
            v = ordenado_heap(tamanho);
        } else if (strcmp(ordem, "ordi") == 0) {
            v = ordenadoInverso_heap(tamanho);
        } else if (strcmp(ordem, "gord") == 0) {
            v = umdesoH(tamanho);
        } } else if (strcmp(alg, "inso") == 0) {
            if (strcmp(ordem, "ale") == 0) {
                v = aleatorioI(tamanho);
            } else if (strcmp(ordem, "ordc") == 0) {
                v = ordenadoI(tamanho);
            } else if (strcmp(ordem, "ordi") == 0) {
                v = ordenadoInversoI(tamanho);
            } else if (strcmp(ordem, "gord") == 0) {
                v = umdesoI(tamanho);
            }
        } else {
        if (strcmp(ordem, "ale") == 0) {
            v = aleatorio(tamanho);
        } else if (strcmp(ordem, "ordc") == 0) {
            v = ordenado(tamanho);
        } else if (strcmp(ordem, "ordi") == 0) {
            v = ordenadoInverso(tamanho);
        } else if (strcmp(ordem, "gord") == 0) {
            v = umdeso(tamanho);
        }
    }
    printf("vetor criado\n");

    if (print) {
        if (strcmp(alg, "heapsort") == 0) {
            imprimeV_heap(v, tamanho);
        } else {
            imprimeV(v, tamanho);
        }
        printf("\n");
    }

    printf("algoritmo '%s'...\n", alg);


    if (strcmp(alg, "bubo") == 0) {
        inicio = clock();
        bolhaO(v, tamanho, &atribuicoes, &comparacoes);
        fim = clock();
        printf("Comparacoes: %lld\n", comparacoes);
        printf("Atribuicoes: %lld\n", atribuicoes);
    } else if(strcmp(alg, "bub") == 0) {
        inicio = clock();
        bolha(v, tamanho, &atribuicoes, &comparacoes);
        fim = clock();
        printf("Comparacoes: %lld\n", comparacoes);
        printf("Atribuicoes: %lld\n", atribuicoes);
    }   else if (strcmp(alg, "selo") == 0)  {
        inicio = clock();
        selecaoO(v, tamanho, &atribuicoes, &comparacoes);
        fim = clock();
        printf("Comparacoes: %lld\n", comparacoes);
        printf("Atribuicoes: %lld\n", atribuicoes);
    } else if (strcmp(alg, "sel") == 0) {
        inicio = clock();
        selecao(v, tamanho, &atribuicoes, &comparacoes);
        fim = clock();
        printf("Comparacoes: %lld\n", comparacoes);
        printf("Atribuicoes: %lld\n", atribuicoes);
    }   else if (strcmp(alg, "ins") == 0) {
        inicio = clock();
        insert(v, tamanho, &atribuicoes, &comparacoes);
        fim = clock();
        printf("Comparacoes: %lld\n", comparacoes);
        printf("Atribuicoes: %lld\n", atribuicoes);
    }   else if (strcmp(alg, "inso") == 0) {
        inicio = clock();
        insertO(v, tamanho, &atribuicoes, &comparacoes);
        fim = clock();
        printf("Comparacoes: %lld\n", comparacoes);
        printf("Atribuicoes: %lld\n", atribuicoes);
    } else if (strcmp(alg, "qui") == 0) {
        inicio = clock();
        quickSort(v, tamanho, &atribuicoes, &comparacoes);
        fim = clock();
        printf("Comparacoes: %lld\n", comparacoes);
        printf("Atribuicoes: %lld\n", atribuicoes);
    } else if (strcmp(alg, "merge") == 0) {
        inicio = clock();
        mergesort(v, 0, tamanho - 1, &atribuicoes, &comparacoes);
        fim = clock();
        printf("Comparacoes: %lld\n", comparacoes);
        printf("Atribuicoes: %lld\n", atribuicoes);
    } else if (strcmp(alg, "heap") == 0) {
        inicio = clock();
        heapsort(v, &tamanho,&atribuicoes, &comparacoes);
        printf("Comparacoes: %lld\n", comparacoes);
        printf("Atribuicoes: %lld\n", atribuicoes);
        fim = clock();
    } else {
        printf("algoritmo '%s' não faz parte do programa.\n", alg);
        free(v); //
        exit(1);
    }
    if (print) {
        printf("vetor ordenado:\n");
        if (strcmp(alg, "heap") == 0) {
            imprimeV_heap(v, tamanho);
        } else {
            imprimeV(v, tamanho);
        }
        printf("\n");
    }


    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("TEMPO GASTO %f segundos\n", tempo_gasto);




    free(v);

    return 0;
}



    /*int TAMANHO;
    int comparacoes=0, atribuicoes=0;
    int TAMANHO =   0;
    scanf("%d", &TAMANHO);
    clock_t inicio, fim;
    double tempo_gasto;



    printf("Criando vetor de %d elementos\n", TAMANHO);
    Item* v = ordenado(TAMANHO);
    imprimeV(v, TAMANHO);
    printf("\nVetor criado. \nIniciando ordenacao\n");



    inicio = clock();
    bolha(v, TAMANHO,&atribuicoes,&comparacoes);
    mergesort(v,0,TAMANHO-1);
    fim = clock();
    imprimeV(v, TAMANHO);

    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf(" \nOrdenacao concluida!\n");
    printf(" \nTempo gasto: %f segundos\n", tempo_gasto);


    return 0;
}
    free(v)
*/

