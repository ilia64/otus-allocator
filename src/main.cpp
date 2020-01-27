#include <iostream>
#include <map>

#include "func.h"
#include "hard.h"
#include "hard_fake.h"
#include "allocator.h"
#include "container.h"

int main()
{
    /// MAP
    const size_t size = 10;
    {
        std::map<int, hard_fake> db;

        for (int i = 0; i < size; ++i)
        {
            //db.try_emplace(i, fact(i), fib(i));
            db.emplace(i, hard_fake{fact(i), fib(i)});
        }

        for (const auto& p : db)
        {
            std::cout << p.first << ' ' << p.second << '\n';
        }
    }

    /// MAP + ALLOCATOR
    {
       std::map<int, hard_fake, std::less<>, allocator<std::pair<const int, hard_fake>, size>> db;
       for (int i = 0; i < size; ++i)
       {
           //db.try_emplace(i, fact(i), fib(i));
           db.emplace(i, hard_fake{fact(i), fib(i)});
       }

       for (const auto& p : db)
       {
           std::cout << p.first << ' ' << p.second << '\n';
       }
    }

    /// CONTAINER
    {
        container<hard> db;
        for (int i = 0; i < size; ++i)
        {
            db.push(fact(i), fib(i));
        }

        for (const hard& hard : db)
        {
            std::cout << hard << '\n';
        }
    }

    /// CONTAINER + ALLOCATOR
    {
        container<hard, allocator<hard, size>> db;
        for (int i = 0; i < size; ++i)
        {
            db.push(fact(i), fib(i));
        }

        for (const hard& hard : db)
        {
            std::cout << hard << '\n';
        }
    }

    return 0;
}
