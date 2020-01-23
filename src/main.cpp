#include <iostream>
#include <map>

#include "func.h"
#include "hard.h"
#include "allocator.h"

int main()
{
    const size_t size = 10;
/*    {
        std::map<int, hard, std::less<>> db;
        for (int i = 0; i < size; ++i)
        {
            db.emplace(i, hard{fact(i), fib(i)});
        }

        for (const auto& p : db)
        {
            std::cout << p.first << ' ' << p.second << '\n';
        }
    }*/

    {
        std::map<int, hard, std::less<>, allocator<std::pair<const int, hard>, size>> db;
        for (int i = 0; i < size; ++i)
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
