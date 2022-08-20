/*
  Let d(n) be the sum of the digits of n.
  Turns out that n-d(n) = (n//10 + n//100 + n//1000 + ...)*9.
  Then, we can binary search for the smallest n such that n-d(n) >= s. 
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll solve(ll x) {
  ll res = 0; 
  while(x > 0) {
    res += x/10;
    x /= 10;
  }
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll n, s; cin >> n >> s;
  ll need = (s+8)/9;

  ll lo = 1;
  ll hi = n;
  ll ans = -1;
  while(lo <= hi) {
    ll mid = hi-(hi-lo)/2;
    if (solve(mid) >= need) {
      ans = mid;
      hi = mid-1;
    }
    else lo = mid+1;
  }
  if (ans == -1) cout << 0 << endl;
  else cout << n-ans+1 << endl;


  return 0;
}
