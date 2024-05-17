#include<bits/stdc++.h>
using namespace std;

vector<string> split(string &s) {
  stringstream ss(s);
  string t; vector<string> res;
  while(getline(ss, t, ' ')) res.emplace_back(t);
  return res;
}

vector<int> toposort(vector<vector<int>> &adj, int s) {
  int n = adj.size();

  vector<int> ts;
  vector<bool> vis(n);
  function<void(int)> dfs = [&](int u) {
    vis[u] = 1;
    for (int &v : adj[u]) {
      if (vis[v]) continue;
      dfs(v);
    }
    ts.push_back(u);
  };

  dfs(s);
  reverse(ts.begin(), ts.end());
  return ts;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int nn; cin >> nn;
  cin.ignore();

  map<string, int> idx; 
  int counter = 0;
  vector<pair<int,int>> edges;
  vector<string> names;
  for (int i = 0; i < nn; i++) {
    string s; getline(cin, s);
    auto tokens = split(s);
    string &su = tokens[0];
    su = su.substr(0, (int)su.size()-1);
    if (idx.count(su) == 0) {
      names.emplace_back(su);
      idx[su] = counter++;
    }
    int u = idx[su];

    for (int i = 1; i < tokens.size(); i++) {
      string &sv = tokens[i];
      if (idx.count(sv) == 0) {
        names.emplace_back(sv);
        idx[sv] = counter++;
      }
      edges.emplace_back(idx[sv], u);
    }
  }
  string changed; cin >> changed;
  if (idx.count(changed) == 0) {
    names.emplace_back(changed);
    idx[changed] = counter++;
  }

  vector<vector<int>> adj(counter);
  for (auto [u, v] : edges) {
    adj[u].emplace_back(v);
  }

  vector<int> ts = toposort(adj, idx[changed]);

  for (auto i : ts) {
    cout << names[i] << "\n";
  }

  return 0;
}