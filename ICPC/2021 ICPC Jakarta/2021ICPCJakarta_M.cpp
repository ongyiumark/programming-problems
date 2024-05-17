#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e18;
int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;
  vector<ll> a(n);
  for (ll &x : a) cin >> x;
  vector<ll> p(n+1);
  for (int i = 1; i <= n; i++) {
    p[i] = p[i-1] + a[i-1];
  }
  vector<ll> pmin(n+1, INF), smin(n+1, INF), pmax(n+1, -INF), smax(n+1, -INF);
  for (int i = 0; i <= n; i++) {
    pmin[i] = p[i];
    pmax[i] = p[i];
    if (i > 0) {
      pmin[i] = min(pmin[i-1], pmin[i]);
      pmax[i] = max(pmax[i-1], pmax[i]);
    }
  }
  for (int i = n; i >= 0; i--) {
    smax[i] = p[i];
    smin[i] = p[i];
    if (i < n) {
      smin[i] = min(smin[i], smin[i+1]);
      smax[i] = max(smax[i], smax[i+1]);
    }
  }
  
  ll ans = -INF;
  for (int i = 1; i < n; i++) {
    ans = max({ans, abs(2*p[i]-pmin[i-1]-smin[i+1]), abs(2*p[i]-pmax[i-1]-smax[i+1])});
  }
  cout << ans << "\n";

  return 0;
}