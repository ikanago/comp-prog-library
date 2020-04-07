// 拡張ユークリッドの互除法で `ax + by = GCD(a, b)` の解 `(x, y)` を求める
template <typename T>
T extGCD(T a, T b, T &x, T &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    T d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}