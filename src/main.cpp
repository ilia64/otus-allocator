#include <iostream>
#include <vector>
#include <map>
#include <tuple>

#include "hard.h"
#include "func.h"


int main()
{
    hard data{fact<10>(), fib<10>()};
    std::cout << data << std::endl;

    std::cout << "----" << std::endl;

    for (int i = 0; i < 10; ++i)
    {
        hard h{fact(i), fib(i)};
        std::cout << h << std::endl;
    }

    return 0;
}
