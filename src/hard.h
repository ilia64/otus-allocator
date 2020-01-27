#pragma once

#include <ostream>

struct hard
{
    int fa;
    int fi;

    explicit hard(int fa, int fi): fa(fa), fi(fi)
    {
    }

    hard(const hard&) = delete;
    hard(hard&&) noexcept = delete;

    ~hard() = default;
};

std::ostream& operator<< (std::ostream &out, const hard& h)
{
    return out << h.fa << ' ' << h.fi;
}
