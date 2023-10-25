#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll r; cin >> r;
  ll best_x, best_y, best_r2 = 1e18; 
  for (ll x = -r-1; x <= r+1; x++) {
    ll lo = 0;
    ll hi = r+1;
    ll y = r+1;

    while (lo <= hi) {
      ll mid = hi - (hi-lo)/2;
      if (mid*mid + x*x > r*r) {
        y = mid;
        hi = mid-1;
      }
      else lo = mid+1;
    }

    if (best_r2 > x*x + y*y) {
      best_x = x;
      best_y = y;
      best_r2 = x*x + y*y;
    }
  }
  cout << best_x << " " << best_y << "\n";

  return 0;
}