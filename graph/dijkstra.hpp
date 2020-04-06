#include <limits>
#include <queue>
#include <vector>

// 最短経路を時間計算量`O(|E|logV)`で求める．
// 負の辺がある場合には使えない．
template <typename T>
class Dijkstra {
    struct Edge {
        int to;
        T cost;
    };
    std::vector<std::vector<Edge>> G;
    std::vector<T> d;
    using P = std::pair<T, int>;

public:
    int n;

    explicit Dijkstra(int size)
    {
        n = size;
        G.resize(n, std::vector<Edge>());
        d.resize(n, std::numeric_limits<T>::max());
    }

    // `from` から `to` へコスト `cost` の辺を張る．
    // `from` と `to` は 0-indexed でなければならない.
    void add(int from, int to, int cost)
    {
        Edge e = { to, cost };
        G[from].push_back(e);
    }

    // 最短経路を求める．
    std::vector<T> solve(int start)
    {
        // priority queue which stores { minimum cost to Edge i, Edge i}
        std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
        d[start] = 0;
        pq.push({ 0, start });
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            auto current_edge = p.second;
            if (d[current_edge] < p.first)
                continue;
            for (const auto& next_edge : G[current_edge]) {
                if (d[next_edge.to] > d[current_edge] + next_edge.cost) {
                    d[next_edge.to] = d[current_edge] + next_edge.cost;
                    pq.push({ d[next_edge.to], next_edge.to });
                }
            }
        }
        return d;
    }
};