#ifndef CONTAINER_H
#define CONTAINER_H

#include <cstddef>

class container {
private:
    int* data_;
    size_t size_;
    size_t capacity_;

public:
    container(size_t initial_capacity = 0);
    container(const container& other);
    container(container&& other);
    ~container();
    
    void push_back(int value);
    size_t size() const;
    size_t capacity() const;
    int& at(size_t index);
    const int& at(size_t index) const;
    void clear();
};

#endif
