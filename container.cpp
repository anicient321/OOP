#include "container.h"
#include <iostream>
#include <stdexcept>

container::container(size_t initial_capacity) 
    : size_(0), capacity_(initial_capacity) {
    if (capacity_ > 0) {
        data_ = new int[capacity_];
    } else {
        data_ = nullptr;
    }
    std::cout << "default konstruktor: capacity = " << capacity_ << std::endl;
}

container::container(const container& other) 
    : size_(other.size_), capacity_(other.capacity_) {
    if (capacity_ > 0) {
        data_ = new int[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    } else {
        data_ = nullptr;
    }
    std::cout << "copy konstruktor: kopiran container s " << size_ << " elemenata" << std::endl;
}

container::container(container&& other) 
    : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
    other.data_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
    std::cout << "move konstruktor: preuzeti resursi" << std::endl;
}

container::~container() {
    if (data_ != nullptr) {
        delete[] data_;
    }
    std::cout << "destruktor: oslobodena memorija" << std::endl;
}

void container::push_back(int value) {
    if (size_ == capacity_) {
        size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
        int* new_data = new int[new_capacity];
        
        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }
        
        if (data_ != nullptr) {
            delete[] data_;
        }
        
        data_ = new_data;
        capacity_ = new_capacity;
        std::cout << "realokacija: novi kapacitet = " << capacity_ << std::endl;
    }
    
    data_[size_] = value;
    ++size_;
}

size_t container::size() const {
    return size_;
}

size_t container::capacity() const {
    return capacity_;
}

int& container::at(size_t index) {
    if (index >= size_) {
        throw std::out_of_range("ERR: index izvan granica");
    }
    return data_[index];
}

const int& container::at(size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("ERR: index izvan granica");
    }
    return data_[index];
}

void container::clear() {
    size_ = 0;
}
