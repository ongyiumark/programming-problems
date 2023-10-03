#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll INF = 1e18;

vector<vector<pair<int,int>>> p;
vector<vector<ll>> d, rows, cols;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k; cin >> n >> k;
  p.resize(k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x; cin >> x;
      x--;
      p[x].push_back({i, j});
    }
  }

  d.resize(n, vector<ll>(n, INF));
  rows.resize(2, vector<ll>(n, INF));
  cols.resize(2, vector<ll>(n, INF));
  for (auto [i,j] : p[0]) {
    d[i][j] = 0;
    rows[0][i] = 0;
    cols[0][j] = 0;
  }

  for (int l = 1; l < k; l++) {
    fill(rows[l%2].begin(), rows[l%2].end(), INF);
    fill(cols[l%2].begin(), cols[l%2].end(), INF);
    
    for (auto [i, j] : p[l]) {
      for (int ii = 0; ii < n; ii++) {
        d[i][j] = min(d[i][j], rows[(l-1)%2][ii]+(ii-i)*(ii-i));
        d[i][j] = min(d[i][j], cols[(l-1)%2][ii]+(ii-j)*(ii-j));
      }

      rows[l%2][i] = min(rows[l%2][i], d[i][j]);
      cols[l%2][j] = min(cols[l%2][j], d[i][j]);
    }
  }

  ll ans = INF;
  for (auto [i, j] : p[k-1]) {
    ans = min(ans, d[i][j]);
  }
  cout << (ans == INF ? -1 : ans) << "\n";
  return 0;
}