#include<iostream>
#include"exercise_Matrix.hpp"


int main()
{
    Matrix a(3,4);
    Matrix b(3,4);
    
    a(1,1) = 3;    // 设置a[1][1]=3
    b(2,3) = 4;    // 设置b[2][3]=4
    
    std::cout << "a is:\n" << a;
    std::cout << "b is:\n" << b;
    
    Matrix c = a + b;
    std::cout << "c is:\n" << c;
    
    Matrix d = a;
    std::cout << "Before assignment,d is:\n" << d;
    
    d = b;
    std::cout << "After assignment,d is:\n" << d;
    
    return 0;
}



