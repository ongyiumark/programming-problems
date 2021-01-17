/*
  Binary search the answer.
  For each monster, find the smallest k such that kA + (x-k)B >= h.
  The sum of all k's must be less than or equal to x.
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
ll h[N];
ll n, a, b;

bool valid(ll x){
  ll cnt = 0;
  for (int i = 0; i < n; i++){ 
    ll nh = h[i]-b*x;
    if (nh <= 0) continue;
    ll curr = (nh+a-b-1)/(a-b);
    cnt += curr;
  }
  return x >= cnt;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++){
    cin >> h[i];
  }
  
  ll lo = 0;
  ll hi = 1e9;
  ll ans = -1;
  while(lo <= hi){
    ll mid = hi - (hi-lo)/2;
    if (valid(mid)){
      ans = mid;
      hi = mid-1;
    }
    else lo = mid+1;
  }

  cout << ans << endl;

  return 0;
}
