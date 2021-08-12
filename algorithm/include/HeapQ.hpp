#ifndef __HEAP_Q__HPP
#define __HEAP_Q__HPP

#include <cstdint>
#include <vector>

template <class T>
class HeapQ {
  public:
    HeapQ(bool max = true);
    virtual ~HeapQ();
    inline unsigned int size() const { return heap.size(); }
    inline bool empty() const { return heap.size() == 0; }

    void push(const T& key);
    void pop();
    T top();

    // extra
    void reBuild();
    void showRaw();
    int height();
    void preOrdem(const int& indice);

  private:
    inline int parentIndex(const int& i) const { return (i - 1) / 2; }
    inline int leftChildIndex(const int& i) const { return (2 * i + 1); }
    inline int rightChildIndex(const int& i) const { return (2 * i + 2); }
    void swap(const int& indiceA, const int& indiceB);
    void heapify_down(const int& indice);
    void heapify_up(const int& indice);

    std::vector<T> heap;
    bool max;
};

template class HeapQ<int>;
template class HeapQ<uint32_t>;

#endif
