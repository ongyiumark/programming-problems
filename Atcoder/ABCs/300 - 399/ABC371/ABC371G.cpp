#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int LGN = 20;

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n; cin >> n;
  vector<int> p(n), a(n);
  for (int &x : p) cin >> x;
  for (int &x : a) cin >> x;
  for (int i = 0; i < n; i++) p[i] -= 1;

  vector<vector<int>> divs(n+1, vector<int>());
  for (int i = 2; i <= n; i++) {
    if (!divs[i].empty()) continue;
    for (ll d = i; d <= n; d *= i) {
      for (int j = d; j <= n; j += d) {
        divs[j].emplace_back(d);
      }
    }
  }

  vector<bool> vis(n);
  vector<int> ans(n);
  vector<int> req(n+1, -1);

  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;

    vector<int> cycle;
    for (int c = i; !vis[c]; c = p[c]) {
      cycle.emplace_back(c);
      vis[c] = true;
    }

    int sz = cycle.size();
    int steps = -1;
    for (int j = 0; j < sz; j++) {
      bool ok = true;
      for (int d : divs[sz]) {
        if ((req[d] != -1) && (j%d != req[d])) {
          ok = false;
          break;
        }
      }    

      if (!ok) continue;

      if (steps == -1 || a[cycle[j]] < a[cycle[steps]]) {
        steps = j;
      }
    }

    for (int j = 0; j < sz; j++) {
      ans[cycle[j]] = a[cycle[(j+steps)%sz]];
    }
    for (int d : divs[sz]) req[d] = steps%d;
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << (i+1 < n ? " " : "\n");
  }
  return 0;
}