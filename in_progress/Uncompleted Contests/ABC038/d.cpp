#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5+5;



int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin >> n;
    vector<vector<int>> x(MXN), y(MXN);
    for (int i = 0; i < n; i++) {
        int h, w; cin >> h >> w;
        x[h].push_back(w);
        y[w].push_back(h);
    }

    for (int i = 0; i < MXN; i++) {
        sort(x[i].begin(), x[i].end());
        sort(y[i].begin(), y[i].end());
    }

    set<tuple<int,int,int,int>> edges;
    
    set<pair<int,int>> y_set;
    for (int px = MXN-1; px >= 1; px--) {
        if (x[px].size() == 0) continue;

        for (int y : x[px]) {
            auto it = y_set.lower_bound({y+1, -1});
            if (it == y_set.end()) continue;
            edges.insert({px, y, it->second, it->first});
        }
        for (int y : x[px]) y_set.insert({y, px});
    }

    set<pair<int,int>> x_set;
    for (int py = MXN-1; py >= 1; py--) {
        if (y[py].size() == 0) continue;

        for (int x : y[py]) {
            auto it = x_set.lower_bound({x+1, -1});
            if (it == x_set.end()) continue;
            edges.insert({x, py, it->first, it->second});
        }
        for (int x : y[py]) x_set.insert({x, py});
    }

    map<pair<int,int>, vector<pair<int,int>>> adj_list;
    for (auto [a, b, c, d] : edges) {
        adj_list[{a, b}].push_back({c, d});
    }

    map<pair<int,int>, int> dist;
    function<void(pair<int,int>)> dfs = [&](pair<int,int> u)->void {
        dist[u] = 1;
        for (pair<int,int> &v : adj_list[u]) {
            if (dist.find(v) == dist.end()) dfs(v);
            dist[u] = max(dist[u], dist[v]+1);
        }
    };


    for (int px = 1; px < MXN; px++) {
        for (int y : x[px]) {
            pair<int,int> u = {px, y};
            if (dist.find(u) != dist.end()) continue;
            dfs(u);
        }
    }

    int ans = 1;
    for (int px = 1; px < MXN; px++) {
        for (int y : x[px]) {
            pair<int,int> u = {px, y};
            ans = max(ans, dist[u]);
        }
    }
    cout << ans << "\n";

    return 0;
}