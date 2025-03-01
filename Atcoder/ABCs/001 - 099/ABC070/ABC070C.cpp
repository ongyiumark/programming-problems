/*
  Get the LCM of all T's.
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

ll gcd(ll a, ll b){
  if (b == 0) return a;
  return gcd(b, a%b);
}

ll lcm(ll a, ll b){
  return a/gcd(a,b)*b;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  ll ans = 1;
  for (int i = 0; i < n; i++){
    ll t; cin >> t;
    ans = lcm(ans, t);
  }
  cout << ans << endl;

  return 0;
}
