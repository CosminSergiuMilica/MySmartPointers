#include "MyUniquePointer/MyUniquePointer.h"
#include "MySharedPointer/MySharedPointer.h"
#include <iostream>

class B {
public:
    B() {
        std::cout << "Constructor" << std::endl;
    }
    ~B() {
        std::cout << "Destructor" << std::endl;
    }
    void sayHello() {
        std::cout << "Hello" << std::endl;
    }
};

MySharedPointer<B> fct() {
    return MySharedPointer<B>(new B());
}

int main() {
    // unique pointer
    MyUniquePointer<B> smart_ptr(new B());
    smart_ptr->sayHello();

    // shared pointer
    MySharedPointer<B> shared_ptr(new B());
    shared_ptr->sayHello();
    std::cout << "use_count: " << shared_ptr.use_count() << std::endl;

    // copiere si atribuiri
    MySharedPointer<B> shared_ptr2;
    shared_ptr2 = shared_ptr; // atribuire prin copiere
    std::cout << "use_count after copy: " << shared_ptr.use_count() << std::endl;

    MySharedPointer<B> sh_ptr3 = fct();
    sh_ptr3 = fct(); // atribuire prin mutare

    return 0;
}
