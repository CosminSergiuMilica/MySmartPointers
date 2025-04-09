#ifndef MY_UNIQUE_POINTER_H
#define MY_UNIQUE_POINTER_H

#include <iostream>
using namespace std;

template <typename T>
class MyUniquePointer {
    T* ptr;

public:
    MyUniquePointer(T* p = nullptr) : ptr(p) {}

    ~MyUniquePointer() {
        delete ptr;
        ptr = nullptr;  
    }
    //eliminam proprietatea de copiere
    MyUniquePointer(const MyUniquePointer&) = delete;
    MyUniquePointer& operator=(const MyUniquePointer&) = delete;

    MyUniquePointer(MyUniquePointer&& my_ptr) noexcept : ptr(my_ptr.ptr) {
        my_ptr.ptr = nullptr;
    }

    MyUniquePointer& operator=(MyUniquePointer&& my_ptr) noexcept {
        if (this != &my_ptr) {
            delete ptr; 
            ptr = my_ptr.ptr;
            my_ptr.ptr = nullptr;
        }
        return *this;
    }
    T* get() const {
        return ptr;
    }
    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }
};

#endif
