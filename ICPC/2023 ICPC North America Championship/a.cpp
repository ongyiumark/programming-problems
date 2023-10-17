#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;

__int128 fastpow(ll b, ll e) {
  __int128 ans = 1;
  while (e > 0) {
    if (e&1) ans *= b;
    b *= b;
    e >>= 1;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int t; cin >> t;
  while(t--) {
    ll n, d; cin >> n >> d;

    // assume x sites
    // turn each compound into a base-(d+1) number with x digits
    // value of each digit will decide which day to apply the compound
    // -> minimum x s.t. (d+1)^x >= n
    int ans = 0;
    for (int x = 0; x < 62; x++) {
      if (fastpow(d+1, x) >= n) {
        ans = x;
        break;
      }
    }

    cout << ans << "\n";
    
  }
  return 0;
}