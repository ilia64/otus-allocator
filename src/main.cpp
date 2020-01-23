#include <iostream>
#include <map>

#include "hard.h"
#include "func.h"


int main()
{
    {
        std::map<int, hard> db;
        for (int i = 0; i < 10; ++i)
        {
            db.emplace(i, hard{fact(i), fib(i)});
        }

        for (const auto& p : db)
        {
            std::cout << p.first << ' ' << p.second << '\n';
        }
    }

    return 0;
}
