// template typename `T` is supposed to be ModInt.

template<typename T>
struct Combination {
private:
    vector<T> fac, finv;
public:
    explicit Combination(int size): fac(size + 1), finv(size + 1) {
        fac[0] = 1;
        finv[0] = 1;
        for (int i = 0; i < size; i++) {
            fac[i + 1] = fac[i] * T(i + 1);
            finv[i + 1] = finv[i] * T(i + 1).inv();
        }
    }

    T C(int n, int r) const {
        if (r < 0 || n < r) return T(0);
        return fac[n] * finv[r] * finv[n - r];
    }

    T P(int n, int r) const {
        if (r < 0 || n < r) return T(0);
        return fac[n] * finv[n - r];
    }

    T H(int n, int r) const {
        if (r < 0 || n < r) return T(0);
        return C(n + r - 1, r);
    }
};