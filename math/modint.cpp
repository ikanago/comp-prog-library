template<int Mod>
struct ModInt {
    int v;
    ModInt(): v(0){}
    template<typename T>
    explicit ModInt(T t) {
        v = t % Mod;
        if (v < 0) v += Mod;
    }

    ModInt pow(int k) {
        ModInt res(1), x(v);
        while(k) {
            if (k & 1) res *= x;
            x *= x;
            k >>= 1;
        }
        return res;
    }

    template<typename T>
    ModInt& operator=(T a) { v = a % Mod; if (v < 0) v += Mod; return *this; }
    ModInt inv() { return pow(Mod - 2); }
    ModInt& operator+=(ModInt a) { v += a.v; if (v >= Mod) v -= Mod; return *this; }
    ModInt& operator-=(ModInt a) { v += Mod - a.v; if (v >= Mod) v -= Mod; return *this; }
    ModInt& operator*=(ModInt a) { v = 1LL * v * a.v % Mod; return *this; }
    ModInt& operator/=(ModInt a) { return (*this) *= a.inv(); }
    ModInt operator+(ModInt a) const { return ModInt(v) += a; }
    ModInt operator-(ModInt a) const { return ModInt(v) -= a; }
    ModInt operator*(ModInt a) const { return ModInt(v) *= a; }
    ModInt operator/(ModInt a) const { return ModInt(v) /= a; }
    ModInt operator-() { return ModInt(-v); }
    bool operator==(const ModInt a) const { return v == a.v; }
    bool operator!=(const ModInt a) const { return v != a.v; }
    bool operator<(const ModInt a) const { return v < a.v; }

    friend std::ostream &operator<<(std::ostream &os, const ModInt &a) { return os << a.v; }
    friend std::istream &operator>>(std::istream &is, ModInt &a) {
        int val;
        is >> val;
        a = ModInt(val);
        return is;
    }
};
