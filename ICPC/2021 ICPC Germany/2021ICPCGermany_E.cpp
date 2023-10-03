#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll NMAX = 1e18;
int WMAX = 1e6;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m; cin >> n >> m;

  vector<tuple<ll,ll,ll>> roads(m);
  for (int i = 0; i < m; i++) {
    ll u, d, c; cin >> u >> d >> c;
    u--;
    roads[i] = {c, d, u};
  }

  vector<ll> lo(n, NMAX);
  sort(roads.rbegin(), roads.rend());

  int q; cin >> q;
  vector<int> query(q), ans(q);
  map<int, vector<int>> qidx; // keep track of indexes
  for (int i = 0; i < q; i++) {
    cin >> query[i];
    qidx[query[i]].push_back(i);
  }

  int unconnected = n-1; // 1 and n is traversable if this becomes 0
  int w = WMAX;
  ll distance = 0;
  for (int i = 0; i < m; i++) {
    auto [c, d, u] = roads[i];

    while(w > c) {
      if (qidx.find(w) != qidx.end()) {
        for (int qi : qidx[w]) ans[qi] = (unconnected > 0 ? 0 : distance);
      }
      w--;
    }

    // update distances
    if (lo[u] == NMAX) {
      unconnected--;
      lo[u] = d;
      distance += d;
    }
    else if (lo[u] > d) {
      distance -= lo[u]-d;
      lo[u] = d;
    }
  }
  // lowest capacity to 0
  while(w > 0) {
    if (qidx.find(w) != qidx.end()) {
      for (int qi : qidx[w]) ans[qi] = (unconnected > 0 ? 0 : distance);
    }
    w--;
  }

  // print answer
  for (int i = 0; i < q; i++) {
    if (ans[i] == 0) cout << "impossible\n";
    else cout << ans[i] << "\n";
  }
  
  return 0;
}