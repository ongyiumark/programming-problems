/*
  Notice that if we know the bitwise OR result we want, say x,
  we can simply choose all integers which are bitwise less than x. 
  That is, if (x|a) == x.

  Do this for all possible x.
  It's always optimal to include more 1's if you can, so this reduces the possibilities.
  For each bit of k, turn off the i-th bit and turn on all the lower bits.
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

const int N = 1e5;
int a[N];
ll b[N];
ll n, k;

ll solve(ll x){
  ll total = 0;
  for (int i = 0; i < n; i++){
    if ((x|a[i]) == x) total += b[i];
  }
  return total;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  for (int i = 0; i < n; i++){
    cin >> a[i] >> b[i];
  }

  ll ans = solve(k);
  for (int i = 30; i >= 0; i--){
    if (((1LL<<i)&k) == 0) continue;
    ll x = k;
    x ^= (1LL<<i);
    x |= (1LL<<i)-1;
    ans = max(ans, solve(x));
  }

  cout << ans << endl;
  return 0;
}
