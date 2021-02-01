/*
  We'll solve for each bit separately.
  The question becomes how many (a+b) are there such that their i-th bit is 1.
  Notice that any bit above i does not affect the i-th bit, so we can simply ignore them.
  Let X = 2^i. If we take everything module 2*X, we remove all the bits above the i-th bit.

  Now, all our numbers range [0,2*X-1]. Thus, (a+b) range [0,4*X-2].
  The i-th bit of (a+b) is 1 if and only if X <= a+b < 2*X  or 3*X <= a+b < 4*X.

  If we sort b and fix an a, all values of b that satisfy these constrainst lie in an interval.
  We can count for this with binary search.
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

const int N = 2e5;
ll a[N], b[N];
ll ta[N], tb[N];
int n;

ll solve(ll curr, ll lower, ll upper){
  int lo = 0;
  int hi = n-1;
  int l = n;
  while(lo <= hi){
    int mid = hi-(hi-lo)/2;
    ll num = curr+tb[mid];
    if (num >= lower){
      l = mid;
      hi = mid-1;
    }
    else lo = mid+1;
  }

  lo = 0;
  hi = n-1;
  int r = -1;
  while(lo <= hi){
    int mid = hi-(hi-lo)/2;
    ll num = curr+tb[mid];
    if (num < upper){
      r = mid;
      lo = mid+1;
    }
    else hi = mid-1;
  }
  if (r < l) return 0;
  return r-l+1;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }
  ll ans = 0;

  for (int i = 0; i <= 30; i++){
    ll cbit = (1LL<<i);
    for (int j = 0; j < n; j++){
      tb[j] = b[j]%(2*cbit);
      ta[j] = a[j]%(2*cbit);
    }
    sort(tb, tb+n);
    ll bit_cnt = 0;
    for (int j = 0; j < n; j++){
      bit_cnt += solve(ta[j], cbit, 2*cbit) + solve(ta[j], 3*cbit, 4*cbit);
    }
    if (bit_cnt&1) ans |= cbit;
  }
  cout << ans << endl;
  return 0;
}
