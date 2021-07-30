#include "include/HeapQ.hpp"

#include <iostream>
#include <stdexcept>

HeapQ::HeapQ(bool max) : max(max) {}
HeapQ::~HeapQ() { heap.clear(); }

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

    if (this->max) {
        // compare `heap[i]` with its leftIndex and rightIndex child
        // and find the newIndex value
        if (leftIndex < heap.size() && heap[leftIndex] > heap[indice]) {
            newIndex = leftIndex;
        }

        if (rightIndex < heap.size() && heap[rightIndex] > heap[newIndex]) {
            newIndex = rightIndex;
        }
    } else {
        // compare `heap[i]` with its leftIndex and rightIndex child
        // and find the newIndex value
        if (leftIndex < heap.size() && heap[leftIndex] < heap[indice]) {
            newIndex = leftIndex;
        }

        if (rightIndex < heap.size() && heap[rightIndex] < heap[newIndex]) {
            newIndex = rightIndex;
        }
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
    int t1 = heap[this->parentIndex(indice)];
    int t2 = heap[indice];

    // check if the node at index `i` and its parent violate the heap property
    bool doSwap = this->max ? (t1 < t2) : (t1 > t2);
    if (indice && doSwap) {
        // swap the two if heap property is violated
        swap(indice, this->parentIndex(indice));

        // call heapify-up on the parent
        heapify_up(this->parentIndex(indice));
    }
}

// insert key into the heap
void HeapQ::push(int key) {
    // insert a new element at the end of the vector
    heap.push_back(key);

    // get element index and call heapify-up procedure
    int index = heap.size() - 1;
    heapify_up(index);
}

// Function to remove an element with the highest priority (present at the root)
void HeapQ::pop() {
    try {
        // if the heap has no elements, throw an exception
        if (heap.size() == 0) {
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
        if (heap.size() == 0) {
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

void HeapQ::showRaw() {

    int tamanho = heap.size();
    for (int index = 1; index <= tamanho; index++)
        printf("%d ", heap[index]);

    printf("\n");
}

int HeapQ::height() {

    int altura = -1;
    int indice = 1;
    while (indice <= heap.size()) {
        indice = this->leftChildIndex(indice);
        altura++;
    }
    return altura;
}

void HeapQ::preOrdem(const int& indice) {

    // TODO: Testar

    if (indice <= heap.size()) {
        printf("%i ", heap[indice]);
        this->preOrdem(this->leftChildIndex(indice));
        this->preOrdem(this->rightChildIndex(indice));
    }
}