/*
  The idea is for every integer x inside the circle, we can binary search up and down for the boundaries.
  Be careful with floor division because floor division with negative numbers isn't just a/b in C++.

  Secondly, we need to read the input as strings to avoid precision errors.
  We can multiply everything by 10000 then divide the boundaries by 10000. 
  Ceiling of the lower boundary and floor of the upper boundary.
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

ll h, k, r;
const ll mult = 10000;
 
ll floordiv(ll x, ll y){
    return x/y + (x%y != 0 && x < 0 ? -1 : 0);
}
ll solve(int x){
  x *= mult;
  if ((x-h)*(x-h) > r*r) return 0;

  ll u, d;
  u = d = k;
  
  ll lo = k;
  ll hi = k+r;
  while(lo <= hi){
    ll mid = hi-(hi-lo)/2;
    if ((x-h)*(x-h) + (mid-k)*(mid-k) <= r*r){
      u = mid;
      lo = mid+1;
    }
    else hi = mid-1;
  }

  lo = k-r;
  hi = k;
  while(lo <= hi){
    ll mid = hi-(hi-lo)/2;
    if ((x-h)*(x-h) + (mid-k)*(mid-k) <= r*r){
      d = mid;
      hi = mid-1;
    }
    else lo = mid+1;
  }

  ll uu = floordiv(u, mult);
  ll dd = floordiv(d+mult-1, mult);
  return uu-dd+1;
}

ll process(string s){
  string ans;
  int n = s.size();
  int pnt = n;
  for (int i = 0; i < n; i++){
    if (s[i] == '.') pnt = i+1; 
    else ans += s[i];
  }

  ans.append(4-(n-pnt),'0');
  return stoll(ans);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string h0, k0, r0;
  cin >> h0 >> k0 >> r0;
  
  h = process(h0), k = process(k0), r = process(r0);
  ll ans = 0;
  for (ll i = floordiv(h-r+mult-1, mult); i <= floordiv(h+r,mult); i++){
    ans += solve(i);
  }
  cout << ans << endl;
  return 0;
}
