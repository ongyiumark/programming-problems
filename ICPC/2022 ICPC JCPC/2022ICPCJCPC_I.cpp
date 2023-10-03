#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ifstream cin("wigz.in");

  int t; cin >> t;
  while(t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
      }
    }

    vector<vector<int>> ngrid;
    if (n > m) {
      swap(n, m);
      ngrid.resize(n, vector<int>(m));
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          ngrid[i][j] = grid[j][i];
        }
      }
    }
    else ngrid = grid;

    vector<int> rows(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        rows[i] += ngrid[i][j];
      }
    }
  
    int best = 0;
    for (int mask = 0; mask < (1<<n); mask++) {
      int nrow = __builtin_popcount(mask);
      if (nrow > k) continue;
      if (k-nrow > m) continue;

      int total = 0;
      for (int i = 0; i < n; i++) {
        if (mask&(1<<i)) total += rows[i];
      }

      vector<int> cols(m);
      for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
          if (mask&(1<<i)) continue;
          cols[j] += ngrid[i][j];
        }
      }
      sort(cols.rbegin(), cols.rend());
      for (int j = 0; j < k-nrow; j++) total += cols[j];

      best = max(total, best);
    }

    cout << best << "\n";
  }
  return 0;
}