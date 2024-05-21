/*
  Let a = x (mod k)
  Thus, b = k-x (mod k) and c = x (mod k)
  Since a+c = 2x = 0 (mod k)
  When k is odd, x must be 0 (mod k).
  When k is even, x is either 0 (mod k) or k/2 (mod k).
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

ll solve(ll n, ll k){
  if (k%2 == 1){
    ll cnt = n/k;
    return cnt*cnt*cnt;
  }
  else {
    ll cnt1 = n/(k/2)-n/k;
    ll cnt2 = n/k;
    return cnt1*cnt1*cnt1 + cnt2*cnt2*cnt2;
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, k; cin >> n >> k;
  cout << solve(n, k) << endl;
  return 0;
}
