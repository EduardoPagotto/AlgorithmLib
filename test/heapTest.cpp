#include "include/Heap.hpp"
#include "include/HeapQ.hpp"
#include "src/HeapQ.cpp"
#include <iostream>

void teste1() {

    // // typedef HeapQ<int> HeapQQ;

    HeapQ<uint32_t> pq(false);
    pq.push(3);
    pq.push(0);
    pq.push(15);
    pq.push(5);
    pq.push(4);
    pq.push(45);
    pq.push(1);
    pq.push(2);
    pq.push(50);
    pq.push(55);
    pq.push(0);
    pq.push(16);
    pq.push(0);
    pq.push(19);
    pq.push(0);
    pq.push(100);
    pq.push(0);
    pq.push(0);
    pq.push(0);
    pq.push(6);

    std::cout << std::endl << "Size: " << pq.size() << std::endl;
    std::cout << std::endl << "Height: " << pq.height() << std::endl;

    // pq.reBuild();

    std::vector<uint32_t> dados;
    pq.getRaw(dados);

    std::cout << "RAW(" << dados.size() << "):";
    for (const auto& d : dados) {
        std::cout << d << " ";
    }
    std::cout << std::endl;

    dados.clear();
    pq.preOrdem(0, dados);
    std::cout << "Pre(" << dados.size() << "):";
    for (const auto& d : dados) {
        std::cout << d << " ";
    }
    std::cout << std::endl;

    std::cout << "Ord(" << pq.size() << "):";
    while (pq.empty() == false) {
        std::cout << pq.top() << " ";
        pq.pop();
    }

    std::cout << std::endl << std::boolalpha << pq.empty();
}

void teste2() {

    HEAP meuHeap;
    inicializarHeap(&meuHeap, 100);
    inserirForaDeOrdem(&meuHeap, 10);
    inserirForaDeOrdem(&meuHeap, 5);
    inserirForaDeOrdem(&meuHeap, 3);
    inserirForaDeOrdem(&meuHeap, 20);
    inserirForaDeOrdem(&meuHeap, 8);
    inserirForaDeOrdem(&meuHeap, 6);
    inserirForaDeOrdem(&meuHeap, 15);
    inserirForaDeOrdem(&meuHeap, 1);
    inserirForaDeOrdem(&meuHeap, 18);
    inserirForaDeOrdem(&meuHeap, 40);
    inserirForaDeOrdem(&meuHeap, 17);
    inserirForaDeOrdem(&meuHeap, 12);
    imprimirArranjo(meuHeap);
    construirHeapMaximo(&meuHeap);
    imprimirArranjo(meuHeap);
    percursoPreOrdem(&meuHeap, 1);
    printf("\n");
    heapSort(&meuHeap);
    imprimirArranjo(meuHeap);
    destruirHeap(&meuHeap);

    printf("\nTestes parte 2\n");
    inicializarHeap(&meuHeap, 50);
    inserirHeap(&meuHeap, 10);
    printf("Altura heap: %i\n", alturaHeap(&meuHeap));
    inserirHeap(&meuHeap, 5);
    printf("Altura heap: %i\n", alturaHeap(&meuHeap));
    inserirHeap(&meuHeap, 3);
    printf("Altura heap: %i\n", alturaHeap(&meuHeap));
    inserirHeap(&meuHeap, 20);
    printf("Altura heap: %i\n", alturaHeap(&meuHeap));
    inserirHeap(&meuHeap, 8);
    printf("Altura heap: %i\n", alturaHeap(&meuHeap));
    inserirHeap(&meuHeap, 6);
    printf("Altura heap: %i\n", alturaHeap(&meuHeap));
    inserirHeap(&meuHeap, 15);
    printf("Altura heap: %i\n", alturaHeap(&meuHeap));
    inserirHeap(&meuHeap, 1);
    printf("Altura heap: %i\n", alturaHeap(&meuHeap));
    inserirHeap(&meuHeap, 18);
    printf("Altura heap: %i\n", alturaHeap(&meuHeap));
    inserirHeap(&meuHeap, 40);
    printf("Altura heap: %i\n", alturaHeap(&meuHeap));
    inserirHeap(&meuHeap, 17);
    printf("Altura heap: %i\n", alturaHeap(&meuHeap));
    inserirHeap(&meuHeap, 12);
    imprimirArranjo(meuHeap);
    /*o Heap ja esta corretamente montado, o comando a seguir nao alterara nada*/
    construirHeapMaximo(&meuHeap);
    imprimirArranjo(meuHeap);
    percursoPreOrdem(&meuHeap, 1);
    printf("\n");
    heapSort(&meuHeap);
    imprimirArranjo(meuHeap);
    destruirHeap(&meuHeap);
}

int main() {
    // teste2();
    teste1();

    return 0;
}