#include"MyUniquePointer/MyUniquePointer.h"
#include <iostream>
class B{
public:
    B(){
        std::cout<<"Constructor"<<std::endl;
    }
    ~B(){
        std::cout<<"Destructor"<<std::endl;
    }
    void sayHello(){
        std::cout<<"Hello"<<std::endl;
    }
};


int main(){
    MyUniquePointer<B> smart_ptr(new B());
    smart_ptr->sayHello();
    return 0;
}