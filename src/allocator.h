#pragma once

template<typename T, size_t N>
class allocator
{
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;

    using heap = T[N];

private:
    size_t step;
    mutable int pos;
    void* array;

public:
    allocator()
    : step(sizeof(value_type))
    , pos(0)
    , array(std::malloc(sizeof(heap)))
    {
        std::cout << "allocator heap:" << sizeof(heap) << " step:" << step;
    }

    ~allocator()
    {
        std::free(reinterpret_cast<heap*>(array));
    }

    template<typename U>
    struct rebind
    {
        using other = allocator<U, N>;
    };

    T *allocate(std::size_t n) const
    {
        if (n + pos > N)
        {
            throw std::bad_alloc();
        }

        T* a = reinterpret_cast<T*>(array);
        T* b = a + sizeof(T) * pos++;
        return b;
    }

    void deallocate(T *p, std::size_t n) const
    {
        //ignore)))
    }

    template<typename U, typename ...Args>
    void construct(U* p, Args &&...args) const
    {
        std::cout << "      construct" <<'\n';
        new(p) U(std::forward<Args>(args)...);
    };

    void destroy(T* p) const
    {
        std::cout << "      destroy" <<'\n';
        p->~T();
    }
};
