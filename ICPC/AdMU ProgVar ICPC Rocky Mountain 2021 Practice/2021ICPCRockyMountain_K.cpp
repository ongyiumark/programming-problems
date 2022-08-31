#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

template<typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1005;
const ll INF = 1e18;

struct dinics {
    struct edge {
        int u, v; ll c, f;
        edge(int u, int v, ll c) : u(u), v(v), c(c), f(0) {}
    };

    int n;
    vector<int> adj_ptr, par, dist;
    vector<vector<int>> adj;
    vector<edge> edges;

    dinics(int n) : n(n) {
        vector<vector<int>>(n).swap(adj);
        reset();
    }

    void reset() {
        vector<int>(n).swap(adj_ptr);
        vector<int>(n).swap(par);
        vector<int>(n).swap(dist);
        for (edge &e : edges) e.f = 0;
    }

    void add_edge(int u, int v, ll c, bool bi = false) {
        adj[u].push_back(edges.size());
        edges.push_back(edge(u,v,c));
        adj[v].push_back(edges.size());
        edges.push_back(edge(v,u, (bi ? c : 0)));
    }

    ll res (const edge &e) {
        return e.c - e.f;
    }

    bool make_level_graph(int s, int t) {
        for (int u = 0; u < n; u++) dist[u] = -1;
        dist[s] = 0;
        queue<int> q; q.push(s);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for (int i : adj[u]) {
                edge &e = edges[i];
                if (dist[e.v] < 0 && res(e) > 0) {
                    dist[e.v] = dist[u]+1;
                    q.push(e.v);
                }
            }
        }
        return dist[t] != -1;
    }

    bool is_next(int u, int v) {
        return dist[v] == dist[u]+1;
    }

    bool dfs(int u, int t) {
        if (u == t) return true;
        for (int &ii = adj_ptr[u]; ii < adj[u].size(); ii++) {
            int i = adj[u][ii];
            edge &e = edges[i];
            if (is_next(u, e.v) && res(e) > 0 && dfs(e.v,t)) {
                par[e.v] = i;
                return true;
            }
        }
        return false;
    }

    bool aug_path(int s, int t) {
        for (int u = 0; u < n; u++) par[u] = -1;
        return dfs(s,t);
    }

    ll calc_max_flow(int s, int t) {
        ll total_flow = 0;
        while(make_level_graph(s,t)) {
            for (int u = 0; u < n; u++) adj_ptr[u] = 0;
            while(aug_path(s,t)) {
                ll flow = INF;
                for (int i = par[t]; i != -1; i = par[edges[i].u]) flow = min(flow, res(edges[i]));
                for (int i = par[t]; i != -1; i = par[edges[i].u]) {
                    edges[i].f += flow;
                    edges[i^1].f -= flow;
                }
                total_flow += flow;
            }
        }
        return total_flow;
    }

    vector<bool> min_cut(int s, int t) {
        calc_max_flow(s,t);
        make_level_graph(s,t);
        vector<bool> cut_mem(n);
        for (int u = 0; u < n; u++) {
            cut_mem[u] = (dist[u] != -1);
        }
        return cut_mem;
    }
};

string s, t;

bool flipped(int i) {
    return t[i] != s[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, r; cin >> n >> r;
    cin >> s >> t;

    dinics mf(2*n+5);
    for (int i = 0; i < n; i++) {
        if (t[i] == '?') mf.add_edge(i, i+n, INF);
    }
    for (int i = 0; i < r; i++) {
        int u, v; cin >> u >> v; u--; v--;
        if (t[u] == '?' && t[v] == '?') {
            mf.add_edge(u, v+n, INF);
            mf.add_edge(v, u+n, INF);
        } 
        else if (t[u] == '?') {
            if (!flipped(v)) mf.add_edge(v, u+n, INF);
            else mf.add_edge(u, v+n, INF);
        }
        else if (t[v] == '?') {
            if (!flipped(u)) mf.add_edge(u, v+n, INF);
            else mf.add_edge(v, u+n, INF);
        }
        else if (flipped(u) && !flipped(v)) mf.add_edge(v, u+n, INF);
        else if (flipped(v) && !flipped(u)) mf.add_edge(u, v+n, INF);
    }
    int source = 2*n;
    int sink = 2*n+1;
    for (int i = 0; i < n; i++) mf.add_edge(source, i, 1);
    for (int i = n; i < 2*n; i++) mf.add_edge(i, sink, 1);

    vector<bool> mem = mf.min_cut(source, sink);
    vector<bool> min_cover(2*n);
    for (int i = 0; i < n; i++) min_cover[i] = !mem[i];
    for (int i = n; i < 2*n; i++) min_cover[i] = mem[i];

    string ans = t;
    for (int i = 0; i < n; i++) {
        if (t[i] == '?') {
            if (min_cover[i] && min_cover[i+n]) ans[i] = 'X';
            else if (min_cover[i]) ans[i] = (s[i] == 'A' ? 'B' :'A');
            else if (min_cover[i+n]) ans[i] = (s[i] == 'A' ? 'A' : 'B');
            else ans[i] = s[i];
        }
        else if (flipped(i)) {
            if (min_cover[i+n]) ans[i] = 'X';
        }
        else {
            if (min_cover[i]) ans[i] = 'X';
        }
    }
    cout << ans << endl;
    return 0;
}