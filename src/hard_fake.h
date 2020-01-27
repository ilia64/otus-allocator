#pragma once

#include <ostream>

struct hard_fake
{
    int fa;
    int fi;

    explicit hard_fake(int fa, int fi): fa(fa), fi(fi)
    {
    }

    hard_fake(const hard_fake& h)
    {
        fa = h.fa;
        fi = h.fi;
    }

    hard_fake(hard_fake&& h) noexcept
    {
        fa = h.fa;
        fi = h.fi;
    }

    ~hard_fake() = default;
};

std::ostream& operator<< (std::ostream &out, const hard_fake& h)
{
    return out << h.fa << ' ' << h.fi;
}
