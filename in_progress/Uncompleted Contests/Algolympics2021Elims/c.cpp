/*
  Let L = lcm({a1,a2,a3}).
  The 'cost' of size i, is L/a[i]*c[i].
  The size with the least cost is the best size.
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

ll a[3], c[3];
ll cost[3];

ll gcd(ll a, ll b){
  if (b == 0) return a;
  return gcd(b, a%b);
}

ll lcm(ll a, ll b){
  return a/gcd(a,b)*b;
}

void solve(){
  for (int i = 0; i < 3; i++) cin >> a[i];
  for (int i = 0; i < 3; i++) cin >> c[i];

  ll lmult = 1;
  for (int i = 0; i < 3; i++) lmult = lcm(lmult, a[i]);
  for (int i = 0; i < 3; i++) cost[i] = lmult/a[i]*c[i];

  int idx = 0;
  ll hi = 1e18;
  for (int i = 0; i < 3; i++){
    if (hi > cost[i]){
      hi = cost[i];
      idx = i+1;
    }
  }
  cout << idx << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
