#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ld r, s, h; cin >> r >> s >> h;
  ld tropical_year = (2*M_PI*r)/(s*h);
  ll rounded = (ll)(tropical_year+0.5);
  ll floored = (ll)(tropical_year);

  ll nonleap = rounded;
  ll leap = rounded + (rounded == floored ? 1 : -1);

  ld best = 1e9;
  ll n1, n2, n3;
  for (ll k1 = 2; k1 <= 1000; k1++) {
    for (ll k2 = 2; 2*k1*k2 <= 1000; k2++) {
      ll leap_count = k1*k2 - k2 + 1;
      for (ll i = 2*k1*k2; i <= 1000; i += k1*k2) {
        ld estimate = leap_count*leap + (i-leap_count)*nonleap;
        estimate /= i;
        if (best > fabs(estimate-tropical_year)) {
          best = fabs(estimate-tropical_year);
          n1 = i/k1/k2;
          n2 = n1*k1;
          n3 = n2*k2;
        }
      }
    }
  }

  cout << n1 << " " << n2 << " " << n3 << "\n";
  return 0;
}