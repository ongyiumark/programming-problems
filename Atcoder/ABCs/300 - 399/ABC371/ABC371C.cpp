#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n; cin >> n;

  int g_sz; cin >> g_sz;
  vector<vector<bool>> g_mat(n, vector<bool>(n));
  for (int i = 0; i < g_sz; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    if (u > v) swap(u, v);
    g_mat[u][v] = true;
  }

  int h_sz; cin >> h_sz;
  vector<vector<bool>> h_mat(n, vector<bool>(n));
  for (int i = 0; i < h_sz; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    if (u > v) swap(u, v);
    h_mat[u][v] = true;
  }
  
  vector<vector<int>> a(n, vector<int>(n, 0));
  for (int i = 0; i < n-1; i++) {
    for (int j = i+1; j < n; j++) {
      cin >> a[i][j];
    }
  }

  vector<int> perm(n);
  iota(perm.begin(), perm.end(), 0);
  
  int best_cost = 1e9;
  do {
    int cost = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        int gi = perm[i];
        int gj = perm[j];
        if (gi > gj) swap(gi, gj);

        if (g_mat[gi][gj] == h_mat[i][j]) continue;
        cost += a[i][j];
      }
    }
    best_cost = min(best_cost, cost);
  } while(next_permutation(perm.begin(), perm.end()));

  cout << best_cost << "\n";

  return 0;
}