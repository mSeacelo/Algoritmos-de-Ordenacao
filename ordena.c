#include "ordena.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void bolha( Item* v, int n, long long* atribuicoes, long long* comparacoes ){
    int i, j;
    Item aux;
    for( i = 0; i < n-1; i++ ){
        for( j = 1; j < n-i; j++ ){
            (*comparacoes)++;
            if( v[j].chave < v[j-1].chave ){
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
                *atribuicoes+= 3;
            }
        }
    }
}




void bolhaO(Item* v, int n, long long* atribuicoes, long long* comparacoes){
    int i, j, troca;
    Item aux;
    for (i = 0; i < n-1; i++) {
        troca = 0;
        for (j = 0; j < n - 1 -i; j++){
            (*comparacoes)++;
            if (v[j].chave > v[j+1].chave) {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            *atribuicoes+=3;
                troca = 1;
            }
        }
        if (troca == 0) break;
    }
}
void selecao( Item* v, int n, long long* atribuicoes, long long* comparacoes ){
    int i, j, min;
    Item aux;
    for(i = 0; i < n - 1; i++){
        min = i;
        for(j = i+1; j < n; j++) {
            (*comparacoes)++;
            if( v[j].chave < v[min].chave){
                min = j;
            }
        }
        (*atribuicoes)++;
        aux = v[min];
        v[min] = v[i];
        v[i] = aux;
        (*atribuicoes) += 3;
    }
}

void selecaoO(Item* v, int n, long long* atribuicoes, long long* comparacoes){
    int i, j, min;
    Item aux;
    for( i = 0; i < n-1; i++ ){
        min = i;
        (*atribuicoes)++;
        for( j = i+1; j < n; j++) {
            (*comparacoes)++;
            if( v[j].chave < v[min].chave) {
                min = j;
                (*atribuicoes)++;
            }
        }
        if( i != min ){
            aux = v[min];
            v[min] = v[i];
            v[i] = aux;
            (*atribuicoes) += 3;
        }
    }
}

void insert(Item* v, int n, long long* atribuicoes, long long* comparacoes ){
    int i, j;
    Item aux;
    for( i = 1; i < n; i++ ){
        aux = v[i];
        (*atribuicoes)++;
        j = i - 1;
        while( (j >= 0) && ((*comparacoes)++, aux.chave < v[j].chave) ){
            v[j+1] = v[j];
            (*atribuicoes)++;
            j--;
        }
        v[j+1] = aux;
        (*atribuicoes)++;
    }
}

void insertO( Item* v , int n, long long* atribuicoes, long long* comparacoes ) {
    int i , j;
     for (i = n - 2; i >= 0; i--) {
         v[n] = v [i];
         (*atribuicoes)++;
         j = i + 1;
         while (((*comparacoes)++, v[n].chave > v [j].chave) ) {
             v[ j - 1] = v[ j ];
             (*atribuicoes)++;
             j++;
             }
         v[j - 1] = v[n];
         (*atribuicoes)++;
         }
     }


/*particao para o quickysort*/

void particao(Item* A, int esq, int dir, int *i, int *j, long long* atribuicoes, long long* comparacoes){
    Item x, aux;
    *i = esq; *j = dir;
    x = A[(*i + *j)/2];
    (*atribuicoes)++;
    do{
        while(x.chave > A[*i].chave){

            (*i)++;
            (*comparacoes)++;
        }
            (*comparacoes)++;
        while(x.chave < A[*j].chave) {
            (*j)--;
            (*comparacoes)++;
        }
        if(*i <= *j){
            aux = A[*i]; A[*i] = A[*j]; A[*j] = aux;
            (*atribuicoes) += 3;
            (*i)++;
            (*j)--;
        }
    }while(*i <= *j);
}

void quickSort(Item *A, int n, long long* atribuicoes, long long* comparacoes){
    *atribuicoes = 0;
    *comparacoes = 0;
    ordenar(A, 0, n-1,atribuicoes, comparacoes);
}
void ordenar(Item *A, int esq, int dir, long long* atribuicoes, long long* comparacoes){
    int i,j;
    particao(A, esq, dir, &i, &j,atribuicoes, comparacoes);
    if(esq < j ) ordenar( A, esq, j,atribuicoes, comparacoes );
    if(i < dir) ordenar( A, i, dir,atribuicoes, comparacoes );
}
/*merge*/
void mergesort(Item* A,int ini,int fim, long long* atribuicoes, long long* comparacoes){
    int meio;
    if(fim == ini) return;

    meio = (ini+fim)/2;
    mergesort( A, ini, meio, atribuicoes, comparacoes );
    mergesort( A, meio+1, fim, atribuicoes, comparacoes );
    intercala( A, ini, meio, fim, atribuicoes, comparacoes );
    return;
}


void intercala(Item* A, int ini, int meio, int fim, long long* atribuicoes, long long* comparacoes){
    int i, j, k;
    Item* C = (Item*) malloc((fim-ini+1)*sizeof(Item));
    for(i = ini, j = meio+1, k = 0; k <= fim-ini; k++) {
        if( i == meio+1 ) { C[k] = A[j++]; (*atribuicoes)++; continue; }
        if( j == fim+1 ) { C[k] = A[i++]; (*atribuicoes)++;continue; }
        (*comparacoes)++;
        if( A[i].chave < A[j].chave ){ C[k] = A[i++]; (*atribuicoes)++;}
        else{ C[k] = A[j++]; (*atribuicoes)++;}
    }

    for(i = ini, k = 0; i <= fim; i++, k++) {
        A[i] = C[k];
        (*atribuicoes)++;
    }
    free(C);
}

/*heap*/

void refaz(Item* A, int esq, int dir, long long* atribuicoes, long long* comparacoes){
    int i = esq, j = i*2;
    Item aux = A[i];
    (*atribuicoes)++;


    while( j <= dir ){

        if( j < dir ) {
            (*comparacoes)++;
            if( A[j].chave < A[j+1].chave ) {
                j++;
            }
        }

        (*comparacoes)++;
        if( aux.chave >= A[j].chave ) {
            break;
        }
        A[i] = A[j];
        (*atribuicoes)++;
        i = j; j = i*2;
    }
    A[i] = aux;
    (*atribuicoes)++;
}

void constroi(Item *A, int *n,long long* atribuicoes, long long* comparacoes){
    int esq = *n / 2;
    while(esq > 0){
        refaz(A, esq, *n, atribuicoes, comparacoes);
        esq--;
    }
}

void heapsort(Item *A, int *n,long long* atribuicoes, long long* comparacoes){
    int esq, dir;
    Item x;
    constroi(A, n,atribuicoes, comparacoes);
    esq = 1;
    dir = *n;
    while(dir > 1){
        x = A[1]; A[1] = A[dir]; A[dir] = x;
        (*atribuicoes) += 3;
        dir--;
        refaz(A, esq, dir,atribuicoes, comparacoes);
    }
}

Item retiraMax(Item *A, int *n,long long* atribuicoes, long long* comparacoes){
    Item max;
    if (*n < 1) printf("Erro: heap vazio\n");
    else{
        max = A[1];
        A[1] = A[*n];
        (*atribuicoes) += 2;
        (*n)--;
        refaz(A, 1, *n, atribuicoes, comparacoes);
    }
    return max;
}

void aumentaChave(Item* A, int i, Item novo,long long* atribuicoes, long long* comparacoes){
    Item aux;
    (*comparacoes)++;
    if(novo.chave < A[i].chave){
        printf("Erro: Chave Nova menor que a chave atual");
        return;
    }
    A[i].chave = novo.chave;
    (*comparacoes)++;
    while( i > 1 && A[i/2].chave < A[i].chave ){
        aux = A[i/2]; A[i/2] = A[i]; A[i] = aux;
        (*atribuicoes) += 3;
        i /= 2;
        (*comparacoes)++;
    }
}

void insere(Item* A, int* n, Item* x,long long* atribuicoes, long long* comparacoes){
    (*n)++;
    A[*n] = *x;
    A[*n].chave = INT_MIN;
    (*atribuicoes) += 2;
    aumentaChave(A, *n, *x,atribuicoes, comparacoes);
}