#include <vector>

class UnionFind {
    std::vector<int> _root;
    std::vector<int> _size;

public:
    explicit UnionFind(int n) : _root(n) {
        for (int i = 0; i < n; i++)
            _root[i] = i;
        _size.assign(n, 1);
    }

    // 要素xの親を取得(経路圧縮もする)
    int root(int x) {
        if (_root[x] == x)
            return x;
        return _root[x] = root(_root[x]);
    }

    // 要素xとyが同じ木にいるかどうかを返す
    bool same(int x, int y) {
        return root(x) == root(y);
    }

    // 要素xとyが属する木を結合する
    // サイズの小さい木を大きい木につなぐ
    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry)
            return;
        if (size(rx) < size(ry))
            std::swap(rx, ry);
        _root[ry] = rx;
        _size[rx] += _size[ry];
    }

    // 要素xが属する木の要素数を返す
    int size(int x) {
        return _size[root(x)];
    }
};