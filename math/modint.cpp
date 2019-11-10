#include <bits/stdc++.h>
using namespace std;

template<int param>
class ModInt{//{{{
    using Z = int;
    using N = unsigned int;
    using ZZ = long long;
    using NN = unsigned long long;
    struct {} constexpr static exact{};

    // Using Z deliberately to avoid Z -> N promotion.
    template<class Ret = Z&>
    static auto modulo() -> std::enable_if_t<(param<=0), Ret> { static Z mod = 0; return mod; }
    template<class Ret = const Z>
    static auto mod() -> std::enable_if_t<(param<=0), Ret> { return modulo(); }
    template<class Ret = const Z>
    static constexpr auto mod() -> std::enable_if_t<(param>0), Ret> { return param; }
    // std::swap is not a constexpr function in C++14
    static constexpr void swap(Z &a, Z &b){ Z tmp = a; a = b; b = tmp; }

    Z val;
    constexpr ModInt(decltype(exact), const N v) : val(v) {}

public:
    template<class Arg = Z>
    static void set_modulo(const std::enable_if_t<(param<=0), Arg> mod) { modulo() = mod; }

    constexpr ModInt() : val(0) {}
    constexpr ModInt(Z v) : val((v%=mod()) < 0 ? v+mod() : v) {}
    constexpr ModInt(ZZ v) : val((v%=mod()) < 0 ? v+mod() : v) {}

    constexpr int get_val() const { return val; }

    constexpr ModInt inv() const {
        Z a = mod(), b = val;
        Z x = 0, u = 1;
        while (b) {
            const Z t = a / b;
            swap(a -= t * b, b);
            swap(x -= t * u, u);
        }
        return ModInt(exact, x < 0 ? x+mod() : x);
    }

    constexpr explicit operator int() const { return val; }
    constexpr ModInt operator+() const { return *this; }
    constexpr ModInt operator-() const { return ModInt(exact, val ? mod() - val : 0); }

    constexpr ModInt operator++(){ if(++val == mod()) val = 0; return *this; }
    constexpr ModInt operator--(){ val = (val == 0 ? mod()-1 : val-1); return *this; }
    constexpr ModInt operator++(int){ const ModInt res(*this); ++*this; return res; }
    constexpr ModInt operator--(int){ const ModInt res(*this); --*this; return res; }

    constexpr bool operator==(const ModInt &rhs) const { return val == rhs.val; }
    constexpr bool operator!=(const ModInt &rhs) const { return val != rhs.val; }
    constexpr ModInt &operator+=(const ModInt &rhs){
        if((val += rhs.val) >= mod()) val -= mod();
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt &rhs){
        if(rhs.val && (val += mod()-rhs.val) >= mod()) val -= mod();
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt &rhs){ val = (NN)(val) * rhs.val % mod(); return *this; }
    constexpr ModInt &operator/=(const ModInt &rhs){ return *this *= rhs.inv(); }

    constexpr ModInt pow(long long e) const {
        if(e < 0) return pow(-e).inv();
        NN res = 1, b = val;
        for(; e; e >>= 1, (b *= b) %= mod()) if(e&1) (res *= b) %= mod();
        return ModInt(exact, res);
    }
    friend constexpr ModInt operator+(ModInt lhs, const ModInt &rhs){ return lhs += rhs; }
    friend constexpr ModInt operator-(ModInt lhs, const ModInt &rhs){ return lhs -= rhs; }
    friend constexpr ModInt operator*(ModInt lhs, const ModInt &rhs){ return lhs *= rhs; }
    friend constexpr ModInt operator/(ModInt lhs, const ModInt &rhs){ return lhs /= rhs; }

    friend std::ostream &operator<<(std::ostream &os, const ModInt &v) { return os << v.val; }
    friend std::istream &operator>>(std::istream &is, ModInt &v) {
        int val;
        is >> val;
        v = ModInt(val);
        return is;
    }
};
