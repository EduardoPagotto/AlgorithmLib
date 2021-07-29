#include "include/HeapQ.hpp"

#include <iostream>
#include <stdexcept>

HeapQ::HeapQ() {}
HeapQ::~HeapQ() {}

void HeapQ::swap(const int& indiceA, const int& indiceB) {
    int temp = heap[indiceA];
    heap[indiceA] = heap[indiceB];
    heap[indiceB] = temp;
}

void HeapQ::heapify_down(const int& indice) {
    // get leftIndex and rightIndex child of node at index `i`
    int leftIndex = this->leftChildIndex(indice);
    int rightIndex = this->rightChildIndex(indice);
    int newIndex = indice;

    // compare `heap[i]` with its leftIndex and rightIndex child
    // and find the newIndex value
    if (leftIndex < this->size() && heap[leftIndex] > heap[indice]) {
        newIndex = leftIndex;
    }

    if (rightIndex < size() && heap[rightIndex] > heap[newIndex]) {
        newIndex = rightIndex;
    }

    // swap with a child having greater value and
    // call heapify-down on the child
    if (newIndex != indice) {
        swap(indice, newIndex);
        heapify_down(newIndex);
    }
}

// Recursive heapify-up algorithm
void HeapQ::heapify_up(const int& indice) {
    // check if the node at index `i` and its parent violate the heap property
    if (indice && heap[this->parentIndex(indice)] < heap[indice]) {
        // swap the two if heap property is violated
        swap(indice, this->parentIndex(indice));

        // call heapify-up on the parent
        heapify_up(this->parentIndex(indice));
    }
}

// TODO: implementar para o minimo
// void HeapQ::heapify_down(const int& indice) {
//     // get leftIndex and rightIndex child of node at index `i`
//     int leftIndex = this->leftChildIndex(indice);
//     int rightIndex = this->rightChildIndex(indice);
//     int newIndex = indice;

//     // compare `heap[i]` with its leftIndex and rightIndex child
//     // and find the newIndex value
//     if (leftIndex < this->size() && heap[leftIndex] < heap[indice]) {
//         newIndex = leftIndex;
//     }

//     if (rightIndex < size() && heap[rightIndex] < heap[newIndex]) {
//         newIndex = rightIndex;
//     }

//     // swap with a child having greater value and
//     // call heapify-down on the child
//     if (newIndex != indice) {
//         swap(heap[indice], heap[newIndex]);
//         heapify_down(newIndex);
//     }
// }

// TODO: implementar para minimo
// // Recursive heapify-up algorithm
// void HeapQ::heapify_up(const int& indice) {
//     // check if the node at index `i` and its parent violate the heap property
//     if (indice && heap[this->parentIndex(indice)] > heap[indice]) {
//         // swap the two if heap property is violated
//         swap(heap[indice], heap[this->parentIndex(indice)]);

//         // call heapify-up on the parent
//         heapify_up(this->parentIndex(indice));
//     }
// }

// insert key into the heap
void HeapQ::push(int key) {
    // insert a new element at the end of the vector
    heap.push_back(key);

    // get element index and call heapify-up procedure
    int index = this->size() - 1;
    heapify_up(index);
}

// Function to remove an element with the highest priority (present at the root)
void HeapQ::pop() {
    try {
        // if the heap has no elements, throw an exception
        if (size() == 0) {
            throw std::out_of_range("Vector<X>::at() : "
                                    "index is out of range(Heap underflow)");
        }

        // replace the root of the heap with the last element
        // of the vector
        heap[0] = heap.back();
        heap.pop_back();

        // call heapify-down on the root node
        heapify_down(0);
    }
    // catch and print the exception
    catch (const std::out_of_range& oor) {
        std::cout << std::endl << oor.what();
    }
}

// Function to return an element with the highest priority (present at the root)
int HeapQ::top() {
    try {
        // if the heap has no elements, throw an exception
        if (size() == 0) {
            throw std::out_of_range("Vector<X>::at() : "
                                    "index is out of range(Heap underflow)");
        }

        // otherwise, return the top (first) element
        return heap.at(0); // or return heap[0];
    }
    // catch and print the exception
    catch (const std::out_of_range& oor) {
        std::cout << std::endl << oor.what();
    }

    return 0;
}

void HeapQ::reBuild() {

    // TODO: Testar

    int halfSize = heap.size() / 2;
    for (int index = halfSize; index > 0; index--)
        heapify_down(index);
}

// rem main: https://www.techiedelight.com/min-heap-max-heap-implementation-c/
// ref cpp: http://neutrofoton.github.io/blog/2016/12/29/c-plus-plus-priority-queue-with-comparator/
// ref: http://each.uspnet.usp.br/digiampietri/ACH2023/javaec/Heap/heap.c
void HeapQ::debugData() {

    // TODO: Testar

    int tamanho = this->heap.size();
    for (int index = 1; index <= tamanho; index++)
        printf("%d ", this->heap[index]);

    printf("\n");
}

int HeapQ::alturaHeap() {

    // TODO: Testar

    int altura = -1;
    int indice = 1;
    while (indice <= this->heap.size()) {
        indice = this->leftChildIndex(indice);
        altura++;
    }
    return altura;
}

void HeapQ::preOrdem(int atual) {

    // TODO: Testar

    if (atual <= this->heap.size()) {
        printf("%i ", this->heap[atual]);
        this->preOrdem(this->leftChildIndex(atual));
        this->preOrdem(this->rightChildIndex(atual));
    }
}