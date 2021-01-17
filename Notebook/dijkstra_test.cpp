/*
    Find the shortest path from s to t.
    Tested here: https://judge.yosupo.jp/problem/shortest_path
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5;
vector<pair<int,ll>> adjlist[N];
int n, m, s, t;

// Needs n, s, t, and adjlist.
void dijkstra(){
    vector<ll> dist(n, 1e18);
    vector<int> par(n, -1);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    dist[s] = 0;
    pq.push({dist[s], s});
    while(!pq.empty()){
        int u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();
        if (dist[u] < d) continue;
        for (auto &e : adjlist[u]){
            int v = e.first;
            ll w = e.second;
            if (dist[u]+w < dist[v]){
                dist[v] = dist[u]+w;
                par[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
   
    stack<pair<int,int>> path;
    int temp = t;
    while(par[temp] != -1){
        path.push({par[temp], temp});
        temp = par[temp];
    }
    if (path.size()){
        cout << dist[t] << " " << path.size() << endl;
        while(!path.empty()){
            auto e = path.top();
            path.pop();
            cout << e.first << " " << e.second << endl;
        }
    }
    else cout << -1 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++){
        int u, v, w; 
        cin >> u >> v >> w;
        adjlist[u].push_back({v, w});
    }

    dijkstra();
    return 0;   
}