#include "include/Heap.hpp"
#include <cstdio>
#include <cstdlib>

void inicializarHeap(HEAP* heap, int tamanhoMax) {
    heap->A = (int*)malloc(sizeof(int) * (tamanhoMax + 1));
    heap->tamanhoAtual = 0;
    heap->tamanhoMaximo = tamanhoMax;
}

void destruirHeap(HEAP* heap) {
    int tamanho = heap->tamanhoMaximo;
    free(heap->A);
    heap->tamanhoMaximo = 0;
    heap->tamanhoAtual = 0;
}

int pai(int i) { return i / 2; }

int filhoEsquerda(int i) { return 2 * i; }

int filhoDireita(int i) { return 2 * i + 1; }

/* metodo auxiliar que pressupoe que o heap para qualquer j>i estah ordenado
   porem o elemento i nao eh necessariamente maior que seus filhos           */
void maxHeapify(HEAP* heap, int i) {
    int esq = filhoEsquerda(i);
    int dir = filhoDireita(i);
    int temp;
    int maior = i;

    if ((esq <= heap->tamanhoAtual) && (heap->A[esq] > heap->A[i]))
        maior = esq;

    if ((dir <= heap->tamanhoAtual) && (heap->A[dir] > heap->A[maior]))
        maior = dir;

    if (maior != i) {
        temp = heap->A[i];
        heap->A[i] = heap->A[maior];
        heap->A[maior] = temp;
        maxHeapify(heap, maior);
    }
}

// Constroi heap a partir do arranjo usando o metodo maxHeapify
void construirHeapMaximo(HEAP* heap) {
    int metadeTamanho = heap->tamanhoAtual / 2;
    for (int i = metadeTamanho; i > 0; i--)
        maxHeapify(heap, i);
}

// Insere no final do arranjo do heap
bool inserirForaDeOrdem(HEAP* heap, int valor) {
    if (heap->tamanhoAtual < heap->tamanhoMaximo) {
        (heap->tamanhoAtual)++;
        heap->A[heap->tamanhoAtual] = valor;
        return true;
    }
    return false;
}

// Imprime o arranjo (na ordem que estiver)
void imprimirArranjo(HEAP h) {
    int tamanho = h.tamanhoAtual;
    for (int i = 1; i <= tamanho; i++)
        printf("%d ", h.A[i]);
    printf("\n");
}

// Imprime elementos em ordem decrescente e esvazia o heap
void heapSort(HEAP* heap) {
    int tamanho = heap->tamanhoAtual;
    int temp;
    construirHeapMaximo(heap); // se o arranjo jah for um heap, nao precisa desta linha
    for (int i = tamanho; i > 1; i--) {
        temp = heap->A[1];
        heap->A[1] = heap->A[i];
        heap->A[i] = temp;
        // printf("%d ",temp);
        (heap->tamanhoAtual)--;
        maxHeapify(heap, 1);
    }
    // printf("\n");
    heap->tamanhoAtual = tamanho;
    ;
}

bool inserirHeap(HEAP* heap, int chave) {
    int i, temp;
    if (heap->tamanhoAtual == heap->tamanhoMaximo)
        return false;

    (heap->tamanhoAtual)++;
    i = heap->tamanhoAtual;
    heap->A[i] = chave;
    while ((i > 1) && (heap->A[pai(i)] < heap->A[i])) {
        temp = heap->A[i];
        heap->A[i] = heap->A[pai(i)];
        heap->A[pai(i)] = temp;
        i = pai(i);
    }
    return true;
}

void percursoPreOrdem(HEAP* heap, int atual) {
    if (atual <= heap->tamanhoAtual) {
        printf("%i ", heap->A[atual]);
        percursoPreOrdem(heap, filhoEsquerda(atual));
        percursoPreOrdem(heap, filhoDireita(atual));
    }
}

int alturaHeap(HEAP* heap) {
    int altura = -1;
    int i = 1;
    while (i <= heap->tamanhoAtual) {
        i = filhoEsquerda(i);
        altura++;
    }
    return altura;
}