class Dijkstra {
private:
    vector<vector<Edge>> G
    vector<int> d;
    struct Edge {
        int to;
        int cost;
    };

public:
    int n;

    Dijkstra(int size) {
        n = size;
        G.resize(n, vector<Edge>());
        d.resize(n, INF);
    }

    // `from` and `to` must be 0-indexed.
    void add(int from, int to, int cost) {
        Edge e = {to, cost};
        G[from].push_back(e);
    }

    void dijkstra(int start) {
        priority_queue <PII, vector<PII>, greater<PII>> pq;
        // vector of { minimum cost to Edge i, Edge i}
        d[start] = 0;
        q.push({0, start});
        while (!q.empty()) {
            PII p = q.top();
            q.pop();
            if (d[p.second] < p.first) continue;
            for (auto &&e : G[p.second]) {
                if (d[e.to] > d[p.second] + e.cost) {
                    d[e.to] = d[p.second] + e.cost;
                    pq.push({d[e.to], e.to});
                }
            }
        }
    }
};