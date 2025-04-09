#ifndef MY_SHARED_POINTER_H
#define MY_SHARED_POINTER_H

#include<iostream>

template <typename T>
class MySharedPointer{
    T* ptr;//pointerul
    int * ref_count;//contor de referinta
public:
    MySharedPointer(T*p=nullptr):ptr{p}, ref_count{new int(1)}{};
    ~MySharedPointer(){
        --(*ref_count);//destructorul decrementeaza counterul si doar cand ajungem la 0 eliberam pointerul
        if(*ref_count == 0){
            delete ptr;
            ptr = nullptr;
        }

    }
    //constructor de copiere utilizat pentru cresterea 
    MySharedPointer(const MySharedPointer& other): ptr(other.ptr), ref_count(other.ref_count){
        std::cout<<"constructor copiere"<<std::endl;
        ++(*ref_count);
    }

    MySharedPointer& operator=(const MySharedPointer& other){
        std::cout<<"Operator de copiere"<<std::endl;
        if (this == &other) return *this; // Auto-atribuire

        --(*ref_count); // reatribuind alta valoare, eliberam resursa pe care o ocupam deja
        if (*ref_count == 0) {//daca ajung la 0 insemana ca nimeni nu mai detinea resursa deci o distrugem
            delete ptr;
            delete ref_count;
        }

        // acum copiem datele pe care le are celalalt
        ptr = other.ptr;
        ref_count = other.ref_count;
        ++(*ref_count); // si crestem contorul pentur ca si noi suntem owneri pe acest pointe
        return *this;
    }

    MySharedPointer(MySharedPointer&& other) noexcept
    : ptr(other.ptr), ref_count(other.ref_count) {
        std::cout<<"constructor de mutare"<<std::endl;
        other.ptr = nullptr;
        other.ref_count = nullptr;
    }

    MySharedPointer& operator=(MySharedPointer&& other) noexcept{
        std::cout<<"Operator de mutare"<<std::endl;
        
        if (this == &other) return *this;
        
        if (ref_count!=nullptr) {
            --(*ref_count);
            if (*ref_count == 0) {
                delete ptr;
                delete ref_count;
            }
        }
    
        ptr = other.ptr;
        ref_count = other.ref_count;
    
        other.ptr = nullptr;
        other.ref_count = nullptr;
        return *this;
    }

    T* get() const{
        return ptr;
    }

    T& operator*() const{
        return *ptr;
    }

    T* operator->() const{
        return ptr;
    }

    int use_count() const{
        return *ref_count;
    }
};

#endif