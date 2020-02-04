#pragma once

#include <iostream>

template<typename T, size_t N>
class allocator
{
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using heap_type = const T[N];

    template<typename U>
    struct rebind
    {
        using other = allocator<U, N>;
    };

private:
    mutable int count;
    mutable pointer heap;

public:
    allocator()
    : count(0)
    , heap(nullptr)
    {
    }

    allocator(const allocator&) = delete;
    allocator(allocator &&ob) noexcept = delete;

    ~allocator()
    {
        std::free(heap);
    }

    pointer allocate(std::size_t n) const
    {
        if (heap == nullptr)
        {
            heap = (pointer)std::malloc(sizeof(value_type) * N);
            std::cout << "M " << heap << ' ' << sizeof(T) * N << std::endl;
        }

        if (n + count > N)
        {
            throw std::bad_alloc();
        }

        pointer position = heap + count;
        ++count;
        std::cout << "A "<< position << std::endl;

        return position;
    }

    void deallocate(pointer p, std::size_t n) const
    {
        //ignore)))
    }

    template<typename U, typename ...Args>
    void construct(U* p, Args&& ...args) const
    {
        new(p) U(std::forward<Args>(args)...);
        std::cout << "C "<< p << std::endl;
    };


    template<typename ...Args>
    void construct(T p, Args&& ...args) const
    {
        new(p) T(std::forward<Args>(args)...);
        std::cout << "C "<< p << std::endl;
    };

    void destroy(pointer p) const
    {
        p->~T();
    }
};
