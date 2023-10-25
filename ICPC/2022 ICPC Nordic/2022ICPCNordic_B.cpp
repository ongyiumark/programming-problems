#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;

  vector<int> degree(n);
  vector adj(n, vector<int>());
  for (int i = 0; i < n-1; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    degree[u]++; degree[v]++;
  }

  // check if star graph
  int degree_more_than_one = 0;
  for (int i = 0; i < n; i++) {
    degree_more_than_one += (degree[i] > 1);
  }
  if (degree_more_than_one == 1) {
    cout << "NO\n";
    return 0;
  }

  int s = -1;
  for (int i = 0; i < n; i++) {
    if (degree[i] == 1) s = i;
  }

  vector<int> visited_order;
  function<void(int, int)> dfs = [&](int u, int p) {
    visited_order.push_back(u+1);
    for (int v : adj[u]) {
      if (v == p) continue;
      dfs(v, u);
    }
  };
  dfs(s, -1);
  cout << "YES\n";
  cout << visited_order[1] << " " << visited_order[0];
  for (int i = 2; i < n; i++) cout << " " << visited_order[i];
  cout << "\n"; 

  return 0;
}