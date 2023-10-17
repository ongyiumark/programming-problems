#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<int> c_left(n), c_right(n);
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    c[i]--;
    c_left[c[i]]++;
  }
  vector adj(n, vector<pair<int,int>>());
  for (int i = 0; i < n-1; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }

  vector<int> subtree(n);
  vector<bool> is_big(n);
  function<void(int,int)> get_subtrees = [&](int u, int p) {
    subtree[u] = 1;
    int biggest = -1;
    for (auto [v, i] : adj[u]) {
      if (v == p) continue;
      get_subtrees(v, u);
      subtree[u] += subtree[v];
      if (biggest == -1 || subtree[biggest] < subtree[v]) biggest = v;
    }
    if (biggest != -1) is_big[biggest] = true;
  };
  get_subtrees(0, -1);
  
  // small to large
  int total = 0;
  vector<int> ans(n-1);
  vector descendants(n, vector<int>());
  function<void(int, int, int)> solve = [&](int u, int p, int id) {
    int biggest = -1, biggest_idx = -1;
    for (auto [v, i] : adj[u]) {
      if (v == p) continue;

      if (!is_big[v]) solve(v, u, i);
      else biggest = v, biggest_idx = i;
    }
    if (biggest != -1) {
      solve(biggest, u, biggest_idx);
      swap(descendants[u], descendants[biggest]);
    }

    descendants[u].push_back(u);
    // add to right
    total -= c_left[c[u]]*c_right[c[u]];
    c_left[c[u]]--; c_right[c[u]]++;
    total += c_left[c[u]]*c_right[c[u]];

    for (auto [v, i] : adj[u]) {
      if (v == p || v == biggest) continue;
      for (int vv : descendants[v]) {
        descendants[u].push_back(vv);
        // add to right
        total -= c_left[c[vv]]*c_right[c[vv]];
        c_left[c[vv]]--; c_right[c[vv]]++;
        total += c_left[c[vv]]*c_right[c[vv]];
      }
    }
  
    if (id != - 1) ans[id] = total;
    if (!is_big[u]) {
      for (int v : descendants[u]) {
        // add to left
        total -= c_left[c[v]]*c_right[c[v]];
        c_left[c[v]]++; c_right[c[v]]--;
        total += c_left[c[v]]*c_right[c[v]];
      }
    }
  };

  solve(0, -1, -1);
  for (int i = 0; i < n-1; i++) {
    cout << ans[i];
    cout << (i+1 < n-1 ? " " : "\n");
  }
  return 0;
}