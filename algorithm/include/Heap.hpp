#pragma once
typedef struct {
    int* A;
    int tamanhoAtual;
    int tamanhoMaximo;
} HEAP;

void inicializarHeap(HEAP* heap, int tamanhoMax);
void destruirHeap(HEAP* heap);
bool inserirForaDeOrdem(HEAP* heap, int valor);
void imprimirArranjo(HEAP h);
void construirHeapMaximo(HEAP* heap);
void percursoPreOrdem(HEAP* heap, int atual);
int alturaHeap(HEAP* heap);
void heapSort(HEAP* heap);
bool inserirHeap(HEAP* heap, int chave);
