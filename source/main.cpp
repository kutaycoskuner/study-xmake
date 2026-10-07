#include <iostream>
#include "my_functions.h"
#include <hello.hpp>

int main()
{
    std::cout << "hello from xmake" << std::endl;
    printMessage();
    hello::sayHello();
    std::cout << DATA_DIR << std::endl;
    return 0;
}
