
#ifndef ORDENA_H
#define ORDENA_H


typedef int ordena;

typedef  struct {
    ordena chave;
}Item;

void bolha( Item* v, int n, long long* atribuicoes, long long* comparacoes );
void bolhaO(Item* v, int n,long long* atribuicoes, long long* comparacoes);
void selecaoO(Item* v, int n, long long* atribuicoes, long long* comparacoes);
void selecao(Item* v, int n, long long* atribuicoes, long long* comparacoes);
void insertO(Item* v , int n, long long* atribuicoes, long long* comparacoes );
void insert(Item* v, int n, long long* atribuicoes, long long* comparacoes );

/*para o quick*/
void particao(Item* v, int esq, int dir,int *i, int *j, long long* atribuicoes, long long* comparacoes);
void quickSort(Item *v, int n, long long* atribuicoes, long long* comparacoes);
void ordenar(Item *v, int esq, int dir, long long* atribuicoes, long long* comparacoes);


void mergesort(Item* v,int ini,int fim, long long* atribuicoes, long long* comparacoes);
void intercala(Item* v, int ini, int meio, int fim, long long* atribuicoes, long long* comparacoes);


/*heapsort*/
void refaz(Item* A, int esq, int dir, long long* atribuicoes, long long* comparacoes);
void constroi(Item *A, int *n,long long* atribuicoes, long long* comparacoes);
Item retiraMax(Item *A, int *n,long long* atribuicoes, long long* comparacoes);
void aumentaChave(Item* A, int i, Item novo,long long* atribuicoes, long long* comparacoes);
void insere(Item* A, int* n, Item* x,long long* atribuicoes, long long* comparacoes);
void heapsort(Item *v, int *n,long long* atribuicoes, long long* comparacoes);


#endif
