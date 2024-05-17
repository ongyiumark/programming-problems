#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> split(string &s) {
  stringstream ss(s);
  string t;
  vector<string> res;
  while(getline(ss, t, ' ')) res.push_back(t);
  return res;
} 

vector<bool> find_articulation(vector<vector<int>> &adj) {
  int n = adj.size();
  vector<bool> vis(n), result(n);
  vector<int> tin(n, -1), low(n, -1);

  int timer = 0;
  function<void(int, int)> dfs = [&](int u, int p) {
    tin[u] = low[u] = timer++;
    vis[u] = 1;
    int children = 0;
    for (int &v : adj[u]) {
      if (v == p) continue;
      if (vis[v]) {
        low[u] = min(low[u], tin[v]);
        continue;
      }
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] >= tin[u] && p != -1) result[u] = 1;
      children++;
    }
    if (p == -1 && children > 1) result[u] = 1;
  };
  for (int u = 0; u < n; u++) {
    if (vis[u]) continue;
    dfs(u, -1);
  }
  return result;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n;
  while(true) {
    cin >> n;
    if (n == 0) break;

    vector<vector<int>> adj(n);
    cin.ignore();
    string s;
    while (true) {
      getline(cin, s);
      if (s == "0") break;
      auto tokens = split(s);
      int u = stoi(tokens[0]);
      u--;
      for (int i = 1; i < tokens.size(); i++) {
        int v = stoi(tokens[i]);
        v--;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
      }
    }

    auto artics = find_articulation(adj);

    cout << accumulate(artics.begin(), artics.end(), 0) << "\n";
  }
}