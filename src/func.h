#pragma once

int fib(int a)
{
    return (a > 1) ? fib(a - 2) + fib(a - 1) : 1;
}

template<int N>
int fib()
{
    return fib<N - 2>() + fib<N - 1>();
}

template<>
int fib<0>()
{
    return 1;
}

template<>
int fib<1>()
{
    return 1;
}

int fact(int a)
{
    return (a > 0) ? a * fact(a - 1) : 1;
}

template<int N>
int fact()
{
    return N * fact<N-1>();
}

template<>
int fact<0>()
{
    return 1;
}
