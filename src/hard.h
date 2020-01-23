#pragma once

struct hard
{
    int fa;
    int fi;

    explicit hard(int fa_, int fi_): fa(fa_), fi(fi_) {}
};

std::ostream& operator<< (std::ostream &out, const hard& h)
{
    out << '{' << h.fa << ", " << h.fi << '}';
    return out;
}
