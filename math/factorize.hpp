#include <map>

// 整数 `n` を素因数分解する．
// 時間計算量は `O(sqrt(n))`．
template <typename T>
std::map<T, int> factorize(T n)
{
    std::map<T, int> res;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            n /= i;
            res[i]++;
        }
    }
    if (n > 1)
        res[n]++;
    return res;
}