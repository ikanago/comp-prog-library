struct UnionFind {
    vector<int> _parent;
    vector<int> _size;

    explicit UnionFind(int n) : _parent(n), _size(n, 1LL) {
        for (int i = 0; i < n; i++)
            _parent[i] = i;
    }

    int root(int x) {
        if (_parent[x] == x)
            return x;
        return _parent[x] = root(_parent[x]);
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry)
            return;
        if (size(rx) < size(ry))
            swap(rx, ry);
        _parent[ry] = rx;
        _size[rx] += _size[ry];
    }

    int size(int x) {
        return _size[x];
    }
};