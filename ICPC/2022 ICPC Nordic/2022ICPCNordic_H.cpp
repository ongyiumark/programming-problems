#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<ll> h(n);
  for (ll &x : h) cin >> x;
  
  vector<ll> nh;
  nh.push_back(h[0]);
  for (int i = 1; i < n; i++) {
    if (nh.back() == h[i]) continue;
    nh.push_back(h[i]);
  }
  swap(h, nh);
  
  n = h.size();
  ll ans = 0;
  for (int j = 1; j < n-1; j++) {
    if (h[j-1] <= h[j] && h[j] >= h[j+1]) {
      int i = j-1;
      while (i-1 >= 0 && h[i-1] <= h[i]) i--;
      int k = j+1;
      while (k+1 < n && h[k] >= h[k+1]) k++;
      ans = max(ans, min(h[j]-h[i], h[j]-h[k]));
    }
  }
  cout << ans << "\n";

  return 0;
}