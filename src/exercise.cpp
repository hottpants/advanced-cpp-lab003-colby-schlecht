#include "project/exercise.hpp"
#include <algorithm>
#include <utility>
#include <iostream>

// TODO: Implement default constructor.
DynamicBuffer::DynamicBuffer() {
    data_ = {};
    size_ = 0;

}

// TODO: Implement allocation and initialization.
// Use a C++ array allocated with new[] and zero-initialize the contents.
DynamicBuffer::DynamicBuffer(size_t capacity) {
    data_ = new int[capacity];
    size_ = capacity;
    
}

// TODO: Implement deep-copy constructor.
DynamicBuffer::DynamicBuffer(const DynamicBuffer& other) {
    data_ = other.data_;
    size_ = other.size_;
}

// TODO: Implement move constructor.
DynamicBuffer::DynamicBuffer(DynamicBuffer&& other) noexcept {

}

// TODO: Implement destructor with proper cleanup.
DynamicBuffer::~DynamicBuffer() {
    
}

// TODO: Implement copy assignment with self-assignment protection.
DynamicBuffer& DynamicBuffer::operator=(const DynamicBuffer& other) {
    
    
    return *this;
}

// TODO: Implement move assignment.
DynamicBuffer& DynamicBuffer::operator=(DynamicBuffer&& other) noexcept {
    

    return *this;
}

// TODO: Return the current managed size.
size_t DynamicBuffer::size() const noexcept {
    
    return size_;
}

// TODO: Return true if the buffer is empty.
bool DynamicBuffer::empty() const noexcept {

    return true;
}

// TODO: Implement resize with resource ownership and exception safety.
// Keep all existing values up to the minimum of old and new sizes.
void DynamicBuffer::resize(size_t newSize) {
    std::cout << "data_[0] = " << at(0) << std::endl;
    DynamicBuffer* resizedData_ = new DynamicBuffer(newSize);
    resizedData_->fill(0);
    resizedData_->copyFrom(*this);
    size_ = newSize;
    delete[] data_;
    std::cout << "resizedData_[0] = " << resizedData_->at(0) << std::endl;
    data_ = resizedData_->data_;
}

// TODO: Fill all elements with the given value.
void DynamicBuffer::fill(int value) {
    for (int i = 0; i < size_; i++) {
        setAt(i, value);
    }
}

// TODO: Validate index and assign the value.
void DynamicBuffer::setAt(size_t index, int value) {
    data_[index] = value;
    //std::cout << "VALUE AT " << index << ": " << value << ", " << data_[index] << std::endl;
}

// TODO: Return element at index with bounds checking.
int DynamicBuffer::at(size_t index) const {
    if(index < size()) { return (data_[index]); }

}

// TODO: Return a reference without bounds checking.
int& DynamicBuffer::operator[](size_t index) {
    return data_[index];
}

// TODO: Return const reference without bounds checking.
const int& DynamicBuffer::operator[](size_t index) const {
    return data_[index];

}

// TODO: Compare size and elements.
bool DynamicBuffer::operator==(const DynamicBuffer& other) const {

}

// TODO: Implement inequality comparison.
bool DynamicBuffer::operator!=(const DynamicBuffer& other) const {

}

// TODO: Return true when the buffer owns valid memory.
DynamicBuffer::operator bool() const noexcept {
    
}

// TODO: Delete allocated memory and reset state.
void DynamicBuffer::release() {
    
}

// TODO: Deep-copy the other object's contents.
void DynamicBuffer::copyFrom(const DynamicBuffer& other) {
    for(int i = 0; i < ((other.size() < size()) ? other.size() : size()); i++) {
        setAt(i, other.at(i));
    }
}

// TODO: Swap the resources of two buffers.
void DynamicBuffer::swap(DynamicBuffer& other) noexcept {
    
}
