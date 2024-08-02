#include <iostream>
#include "lmao.h"

int main() {
    int x = 10, y = 20;
    std::cout << "x = " << x << ", y = " << y << std::endl;
    
    add(x, y);
    
    std::cout << "x + y = " << getResult() << std::endl;
    
    return 0;
}