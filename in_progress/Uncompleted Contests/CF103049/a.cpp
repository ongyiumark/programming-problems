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
 
 
const ll MAXN = 2e5+2;
ll n, dp[MAXN];
ll dumb(ll idx) {
    if (dp[idx] != -1) return dp[idx];
    if (idx == 0) return 0; 
    dp[idx] = 1e18;
    for (ll i = n; i >= 1; --i) {
        dp[idx] = min(
            dp[idx],
            dumb(i) + dumb(idx-i)
        );
    }
    return dp[idx];
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 
  memset(dp, -1, sizeof(dp));
  int q; cin >> n >> q;
  ll a[n+1];
  for (int i = 1; i <= n; i++){
    cin >> a[i];
    dp[i] = a[i];
  }
 
  // find minimum energy per atom
  vector<pair<ll,int>> tmp;
  for (int i = 1; i <= n; i++){
    tmp.push_back({a[i],i});
  }
  sort(tmp.begin(), tmp.end(), [](const pair<ll,int>& left, const pair<ll,int>& right){
    return left.first*right.second < right.first*left.second;
  });
 
  ll x = tmp[0].second;
 
  while(q--){
    ll k; cin >> k;
    // find smallest j such that k-jx <= MAXN
 
    ll lo = 0;
    ll hi = k/x;
    ll j = 0;
    while(lo <= hi){
      ll mid = hi-(hi-lo)/2;
      if (k-mid*x <= MAXN){
        j = mid;
        hi = mid-1;
      }
      else lo = mid+1;
    }
 
    // combine (greedy for large k) + (dp for small(ish) k)
    cout << a[x]*j + dumb(k-j*x) << '\n';
    // cout << a[x]*j + a[k-j*x] << endl;
  }
  
  return 0;
}