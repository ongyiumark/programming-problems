#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const int LGN = 20;

pair<bool,int> solve(vector<ll> &pref, ll val, int k) {
  int n = (pref.size()-1)/2;
  vector<vector<int>> p(LGN, vector<int>(2*n+1, 2*n));

  int j = 1;
  for (int i = 0; i < 2*n; i++) {
    while (j <= 2*n && pref[j] - pref[i] < val) j++;
    if (j > 2*n) break;
    p[0][i] = j;
  }

  for (int t = 1; t < LGN; t++) {
    for (int i = 0; i < 2*n; i++) {
      p[t][i] = p[t-1][p[t-1][i]];
    }
  }

  vector<int> pk(2*n);
  for (int i = 0; i < 2*n; i++) {
    int y = i;
    for (int t = LGN-1; t >= 0; t--) {
      if ((1<<t)&k) y = p[t][y];
    }
    pk[i] = (y == 2*n) ? INF : y;
  }

  bool valid = false;
  int count = n;
  for (int i = 0; i < n; i++) {
    if (pk[i] <= i+n) {
      valid |= true;
      count -= 1;
    }
  }
  return {valid, count};
}

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n, k; cin >> n >> k;
  vector<ll> a(2*n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) a[i+n] = a[i];

  vector<ll> pref(2*n+1);
  for (int i = 0; i < 2*n; i++) pref[i+1] = pref[i] + a[i];

  ll ans = 1;
  ll ans_count = 0;
  ll lo = 1;
  ll hi = 2e9;
  while (lo <= hi) {
    ll mid = hi - (hi-lo)/2;
    auto [valid, count] = solve(pref, mid, k);
    if (valid) {
      ans = mid;
      ans_count = count;
      lo = mid+1;
    }
    else hi = mid-1;
  }
  cout << ans << " " << ans_count << "\n";
  

  return 0;
}