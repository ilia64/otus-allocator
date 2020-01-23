#pragma once

template<typename T>
class allocator
{
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;

    template<typename U>
    struct rebind
    {
        using other = allocator<U>;
    };

    T *allocate(std::size_t n) const
    {
        auto p = std::malloc(n * sizeof(T));
        if (!p)
        {
            throw std::bad_alloc();
        }
        return reinterpret_cast<T*>(p);
    }

    void deallocate(T *p, std::size_t n) const
    {
        std::free(p);
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
