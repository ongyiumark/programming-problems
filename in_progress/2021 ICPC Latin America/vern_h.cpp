#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
template <typename X, typename Y> istream& operator>>(istream& is, pair<X, Y>& p) { return is >> p.first >> p.second; }
template <bool Directed, typename TEdge, bool Index> struct graph {
    using EType = TEdge;
    vector<TEdge> edges;
    vector<vector<int>> adj;
    graph(int n) : adj(n + Index) {}
    graph(int n, int m) : graph(n) { edges.reserve(m << not Directed); }
    TEdge& operator()(int e) { return edges[e]; }
    vector<int>& operator[](int u) { return adj[u]; }
    int size() { return adj.size() - Index; }
    void append(int u, const TEdge& e) {
        adj[u].push_back(edges.size());
        edges.push_back(e);
    }
    void add_edge(const TEdge& e) {
        append(e.u, e);
        if(not Directed) append(e.v, e.reverse());
    }
};
template <typename T> struct fedge {
    int u, v; T w, c, f;
    T resid() { return c - f; }
    fedge reverse() const { return {v, u, -w, 0, 0}; }
    friend ostream& operator<<(ostream& os, const fedge& e) {
        return os << "(" << e.u << ", " << e.v << ", " << e.w << ", " << e.c << ", " << e.f << ")";
    }
};
template <typename T, bool Index> using flow_graph = graph<0, fedge<T>, Index>;
template <typename T, bool Index> pair<T, T> min_cost_flow(flow_graph<T, Index>& g, int s, int t, T flow_limit = lim<T>::max()) {
    vector<int> vis(g.adj.size()), p(g.adj.size());
    vector<T> d(g.adj.size()), pot(g.adj.size());
    auto augment = [&]() {
        fill(vis.begin(), vis.end(), false);
        fill(d.begin(), d.end(), lim<T>::max());
        priority_queue<pair<T, int>> pq({}, {{d[s] = 0, s}});
        while(not pq.empty()) {
            int u = pq.top().second; pq.pop();
            if(not vis[u]) {
                vis[u] = true;
                for(int e : g[u]) {
                    if(not vis[g(e).v] and g(e).resid() > 0 and d[g(e).v] > d[g(e).u] + pot[g(e).u] + g(e).w - pot[g(e).v]) {
                        pq.push({-(d[g(e).v] = d[g(e).u] + pot[g(e).u] + g(e).w - pot[g(e).v]), g(p[g(e).v] = e).v});
                    }
                }
            }
        }
        return d[t] < lim<T>::max();
    };
    if(count_if(g.edges.begin(), g.edges.end(), [](const fedge<T>& e) { return e.c and e.w < 0; })) {
        fill(pot.begin(), pot.end(), lim<T>::max());
        pot[s] = 0;
        for(int i = 0; i < g.size() - 1; i++) {
            for(const fedge<T>& e : g.edges) {
                if(e.c and pot[e.u] < lim<T>::max()) {
                    pot[e.v] = min(pot[e.v], pot[e.u] + e.w);
                }
            }
        }
    }
    T flow = 0, cost = 0;
    while(flow < flow_limit and augment()) {
        T b = flow_limit - flow;
        for(int v = t; v != s; v = g(p[v]).u) {
            b = min(b, g(p[v]).resid());
        }
        for(int v = t; v != s; v = g(p[v]).u) {
            g(p[v]).f += b, g(p[v] ^ 1).f -= b;
            cost += b * g(p[v]).w;
        }
        flow += b;
        for(int u = Index; u < g.adj.size(); u++) {
            pot[u] += d[u];
        }
    }
    return {flow, cost};
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector L(n + 2, vector<int>(n + 2));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> L[i][j];
        }
    }
    int s = n + 2;
    int t = n + 3;
    flow_graph<ll, 1> g(n + 3);
    for(int i = 1; i <= n; i += 2) {
        g.add_edge({s, i, 0, 1});
        for(int j = 2; j <= n + 1; j += 2) {
            g.add_edge({i, j, L[j - 2][i] + L[i][j], 1});
        }
    }
    for(int j = 2; j <= n + 1; j += 2) {
        g.add_edge({j, t, 0, 1});
    }
    auto [flow, cost] = min_cost_flow(g, s, t);
    cout << cost << endl;
    return 0;
}
