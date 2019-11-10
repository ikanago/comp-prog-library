struct UnionFind {
    vector<int> parent, rank;

    explicit UnionFind(int n) : parent(n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int root(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = root(parent[x]);
    }

    bool is_same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return root_x == root_y;
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry)
            return;
        if (rank[x] < rank[y])
            parent[rx] = ry;
        else {
            parent[ry] = rx;
            rank[rx] += (rank[x] == rank[y]);
        }
    }
};