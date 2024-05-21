/*
  Fix H. Either 2 horizontal cuts or 1 horizontal cut then 1 verical cut.
  Try all cases:
  (1) w is even.
  (2) w is odd.

  Do the same for W.
  I did some algebra to figure this out.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll solve(int h, int w){
  if (h%3 == 0 || w%3 == 0) return 0;
  ll ans = min(h, w);
  ll x = w/3;
  ll y = h/2;
  if (h%2 == 0) ans = min(ans, y);
  else ans = min(ans, max(x+y+1,2*x+1));

  x = h/3;
  y = w/2;
  if (w%2 == 0) ans = min(ans, y);
  else ans = min(ans, max(x+y+1,2*x+1));
  return ans;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int h, w; cin >> h >> w;
  cout << solve(h, w) << endl;
  return 0;
}
