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

ll n, x;
ll t[15];

__int128_t mygcd(__int128_t a, __int128_t b){
  if (b == 0) return a;
  return mygcd(b, a%b);
}

__int128_t mylcm(__int128_t a, __int128_t b){
  return a/mygcd(a,b)*b;
}

__int128_t inc_exc(ll i, __int128_t L, ll sign, ll time){
  if (L > time) return 0;
  if (i == n) return sign*(time/L);
  return inc_exc(i+1, L, sign, time)+inc_exc(i+1, mylcm(L,t[i]), -sign, time);
}

bool valid(ll time){
  return inc_exc(0, 1, -1, time)+time >= x; 
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }

  ll lo = 1;
  ll hi = 3e18;
  ll ans = 0;
  while (lo <= hi) {
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
