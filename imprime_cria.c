#include "imprime_cria.h"
#include <time.h>
/*funciona para todos, menos para o heap*/
void imprimeV(Item* v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
}


Item* aleatorio(int tamanho) {
    Item* v = malloc(tamanho * sizeof(Item));
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        v[i].chave = rand();
    }
    return v;
}

Item* ordenado(int tamanho) {
    Item* v = malloc(tamanho * sizeof(Item));
    for (int i = 0; i < tamanho; i++) {
        v[i].chave = i ;
    }
    return v;
}

Item* ordenadoInverso(int tamanho) {
    Item* v = malloc(tamanho * sizeof(Item));
    for (int i = 0; i < tamanho; i++) {
        v[i].chave = tamanho -1 -i ;
    }
    return v;
}

Item* umdeso(int tamanho) {
    Item* v = malloc(tamanho * sizeof(Item));
    for (int i = 0; i < tamanho; i++) {
        v[i].chave = i ;
    }
    int umporcem = (tamanho/100);
    srand(time(NULL));
    for (int i = 0; i < umporcem; i++) {
        int a = rand() % tamanho;
        int na = rand() % tamanho;
        v[a].chave = na;
    }

    return v;
}



/*heap*/

void imprimeV_heap(Item* v, int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", v[i].chave);
    }
}

Item* aleatorio_heap(int tamanho) {
    Item* v = malloc((tamanho + 1) * sizeof(Item));
    srand(time(NULL));
    for (int i = 1; i <= tamanho; i++) {
        v[i].chave = rand();
    }
    return v;
}

Item* ordenado_heap(int tamanho) {
    Item* v = malloc((tamanho + 1) * sizeof(Item));
    for (int i = 1; i <= tamanho; i++) {
        v[i].chave = i;
    }
    return v;
}

Item* ordenadoInverso_heap(int tamanho) {
    Item* v = malloc((tamanho + 1) * sizeof(Item));
    for (int i = 1; i <= tamanho; i++) {
        v[i].chave = tamanho - i + 1;
    }
    return v;
}

Item* umdesoH(int tamanho) {
    Item* v = malloc((tamanho+ 1) * sizeof(Item));
    for (int i = 1; i <= tamanho; i++) {
        v[i].chave = i ;
    }
    int umporcem = (tamanho/100);
    srand(time(NULL));
    for (int i = 0; i < umporcem; i++) {
        int a = (rand() % tamanho) + 1;
        int na = rand() % tamanho;
        v[a].chave = na;
    }

    return v;
}

Item* aleatorioI(int tamanho) {
    Item* v = malloc((tamanho + 1) * sizeof(Item));
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        v[i].chave = rand();
    }
    return v;
}

Item* ordenadoI(int tamanho) {
    Item* v = malloc((tamanho + 1) * sizeof(Item));
    for (int i = 0; i < tamanho; i++) {
        v[i].chave = i ;
    }
    return v;
}

Item* ordenadoInversoI(int tamanho) {
    Item* v = malloc((tamanho + 1) * sizeof(Item));
    for (int i = 0; i < tamanho; i++) {
        v[i].chave = tamanho -1 -i ;
    }
    return v;
}

Item* umdesoI(int tamanho) {
    Item* v = malloc((tamanho + 1) * sizeof(Item));
    for (int i = 0; i < tamanho; i++) {
        v[i].chave = i ;
    }
    int umporcem = (tamanho/100);
    srand(time(NULL));
    for (int i = 0; i < umporcem; i++) {
        int a = rand() % tamanho;
        int na = rand() % tamanho;
        v[a].chave = na;
    }

    return v;
}