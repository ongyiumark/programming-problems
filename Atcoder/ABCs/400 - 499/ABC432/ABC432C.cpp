#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
  cin.tie(0)->sync_with_stdio(false);
  int n; ll x, y;
  cin >> n >> x >> y;
  vector<ll> a(n);
  for (ll &aa : a) cin >> aa;

  // let p = number of small candies
  // let q = number of large candies
  ll min_a = 1e18;
  ll max_a = 0;
  for (int i = 0; i < n; i++) {
    min_a = min(min_a, a[i]);
    max_a = max(max_a, a[i]);
  }
  ll S = -1;
  bool possible = true;
  for (int i = 0; i < n; i++) {
    // p + q = a[i] -> p = a[i] - q
    // xp + yq = S -> x(a[i]-q) + yq = S
    //             -> xa[i] - xq + yq = S
    //             -> (y-x)q = S - xa[i] 
    //             -> q = (S-xa[i])/(y-x)
    //             -> p = (ya[i]-S)/(y-x)
    // S = y*a[i] % (y-x) = x*a[i] % (y-x)
    // xa[i] <= S <= ya[i];
    if (x*a[i] % (y-x) != y*a[i] % (y-x)) {
      possible = false;
      break;
    }
    if (S == -1) S = y*a[i]%(y-x);
    else {
      if (S%(y-x) != y*a[i]%(y-x)) {
        possible = false;
        break;
      }
    }
  }

  if (max_a*x > min_a*y) possible = false;
  if (S < min_a*y) {
    S = S + (y-x)*((min_a*y-S)/(y-x));
  }
  if (max_a*x > S) possible = false;

  if (!possible) {
    cout << -1 << "\n";
  }
  else {
    ll max_q = 0;
    for (int i = 0; i < n; i++) {
      max_q += (S-x*a[i])/(y-x);
    }
    cout << max_q << "\n";
  }

  
  return 0;
}
