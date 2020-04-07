#ifndef _MODINT_H_
#define _MODINT_H_
#include <assert.h>
#include <iostream>

template <int Mod>
struct ModInt {
    int v;
    ModInt()
        : v(0)
    {
    }
    template <typename T>
    explicit ModInt(T t)
    {
        v = t % Mod;
        if (v < 0)
            v += Mod;
    }

    ModInt pow(int k) const
    {
        ModInt res(1), x(v);
        while (k) {
            if (k % 2 == 1)
                res *= x;
            x *= x;
            k >>= 1;
        }
        return res;
    }

    template <typename T>
    ModInt& operator=(T a)
    {
        v = a % Mod;
        if (v < 0)
            v += Mod;
        return *this;
    }
    ModInt inv() const { return pow(Mod - 2); }
    ModInt& operator+=(ModInt a)
    {
        v += a.v;
        if (v >= Mod)
            v -= Mod;
        return *this;
    }
    ModInt& operator-=(ModInt a)
    {
        v += Mod - a.v;
        if (v >= Mod)
            v -= Mod;
        return *this;
    }
    ModInt& operator*=(ModInt a)
    {
        v = 1LL * v * a.v % Mod;
        return *this;
    }
    ModInt& operator/=(ModInt a)
    {
        assert(a.v != 0);
        return (*this) *= a.inv();
    }
    ModInt operator+(ModInt a) const { return ModInt(v) += a; }
    ModInt operator-(ModInt a) const { return ModInt(v) -= a; }
    ModInt operator*(ModInt a) const { return ModInt(v) *= a; }
    ModInt operator/(ModInt a) const { return ModInt(v) /= a; }
    ModInt operator-() const { return ModInt(-v); }
    bool operator==(const ModInt a) const { return v == a.v; }
    bool operator!=(const ModInt a) const { return v != a.v; }
    bool operator<(const ModInt a) const { return v < a.v; }

    friend std::ostream& operator<<(std::ostream& os, const ModInt& a) const { return os << a.v; }
    friend std::istream& operator>>(std::istream& is, ModInt& a) const
    {
        int val;
        is >> val;
        a = ModInt(val);
        return is;
    }
};

#endif // #ifndef _MODINT_H_
