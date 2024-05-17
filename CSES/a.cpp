#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9;
vector<int> bfs(vector<vector<int>>& adj, int s) {
  vector<int> dist(adj.size(), INF);
  dist[s] = 0;
  queue<int> q; q.push(s);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int &v : adj[u]) {
      if (dist[v] < INF) continue;
      dist[v] = dist[u]+1;
      q.push(v);
    }
  }
  return dist;
}  

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n, m; cin >> n >> m;
  vector<vector<int>> adj(n+1);
  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
  }

  auto dist = bfs(adj, 1);
  if (dist[n] == INF) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  vector<int> route;
  int u = n; 
  route.emplace_back(u);
  while (u != 1) {
    for (int &v : adj[u]) {
      if (dist[v] != dist[u]-1) continue;
      u = v; break;
    }
    route.emplace_back(u);
  }
  reverse(route.begin(), route.end());
  int sz = route.size();
  cout << sz << "\n";
  for (int i = 0; i < sz; i++) {
    cout << route[i] << " \n"[i+1==sz];
  }

  return 0;
}