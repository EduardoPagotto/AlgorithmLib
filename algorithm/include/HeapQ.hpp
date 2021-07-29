#ifndef __HEAP_Q__HPP
#define __HEAP_Q__HPP

#include <vector>

class HeapQ {
  public:
    HeapQ();
    virtual ~HeapQ();
    inline unsigned int size() const { return heap.size(); }
    inline bool empty() const { return heap.size() == 0; }

    void push(int key);
    void pop();
    int top();

    // extra
    void reBuild();
    void debugData();
    int alturaHeap();
    void preOrdem(int atual);

  private:
    inline int parentIndex(const int& i) const { return (i - 1) / 2; }
    inline int leftChildIndex(const int& i) const { return (2 * i + 1); }
    inline int rightChildIndex(const int& i) const { return (2 * i + 2); }
    void swap(const int& indiceA, const int& indiceB);
    void heapify_down(const int& indice);
    void heapify_up(const int& indice);

    std::vector<int> heap;
};

#endif
