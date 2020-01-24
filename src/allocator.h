#pragma once

template<typename T, size_t N>
class allocator
{
public:
    using value_type = T;
    using heap = T[N];

private:
    mutable int count;
    void* start;

public:
    allocator()
    : count(0)
    , start(std::malloc(sizeof(heap)))
    {
    }

    ~allocator()
    {
        std::free(reinterpret_cast<heap*>(start));
    }

    template<typename U>
    struct rebind
    {
        using other = allocator<U, N>;
    };

    T *allocate(std::size_t n) const
    {
        if (n + count > N)
        {
            throw std::bad_alloc();
        }

        T* a = reinterpret_cast<T*>(start);
        T* b = a + sizeof(T) * count++;
        return b;
    }

    void deallocate(T *p, std::size_t n) const
    {
        //ignore)))
    }

    template<typename U, typename ...Args>
    void construct(U* p, Args &&...args) const
    {
        new(p) U(std::forward<Args>(args)...);
    };

    void destroy(T* p) const
    {
        p->~T();
    }
};
