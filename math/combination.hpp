#include <vector>

// 組み合わせ，順列を求める
// 前処理 `O(n)`，クエリ `O(1)` ただし，`n < Mod`
template <int Mod>
class Combination {
    std::vector<long> fac, inv, finv;

public:
    explicit Combination(long size)
        : fac(size + 1)
        , inv(size + 1)
        , finv(size + 1)
    {
        fac[0] = fac[1] = 1;
        inv[1] = 1;
        finv[0] = finv[1] = 1;
        for (int i = 2; i <= size; i++) {
            fac[i] = fac[i - 1] * i % Mod;
            inv[i] = Mod - inv[Mod % i] * (Mod / i) % Mod;
            finv[i] = finv[i - 1] * inv[i] % Mod;
        }
    }

    // `nCr` を求める
    int C(int n, int r) const
    {
        if (r < 0 || n < r)
            return 0;
        return fac[n] * (finv[r] * finv[n - r] % Mod) % Mod;
    }

    // `nPr` を求める
    int P(int n, int r) const
    {
        if (r < 0 || n < r)
            return 0;
        return fac[n] * finv[n - r] % Mod;
    }
};