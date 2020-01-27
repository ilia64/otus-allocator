#pragma once

#include <ostream>

struct hard
{
    int fa;
    int fi;

    explicit hard(int fa_, int fi_): fa(fa_), fi(fi_)
    {
        std::cout << "   +  " << __PRETTY_FUNCTION__ << ' ' << fi << '\n';
    }

    hard(const hard&) = delete;
    hard(hard&&) noexcept = delete;

    ~hard()
    {
        std::cout << "   -  " << __PRETTY_FUNCTION__ << ' ' << fi << '\n';
    }
};

std::ostream& operator<< (std::ostream &out, const hard& h)
{
    return out << h.fa << ' ' << h.fi;
}
