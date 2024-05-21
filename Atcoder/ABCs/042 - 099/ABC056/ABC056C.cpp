/*
  Just go right every time until you arrive or surpass x.
  Reverse the difference to compensate.
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll x; cin >> x;

  ll a = 1;
  ll b = 1e5;
  ll ans = -1;
  while(a <= b){
    ll mid = b-(b-a)/2;
    if (mid*(mid+1)/2 >= x){
      ans = mid;
      b = mid-1;
    }
    else a = mid+1;
  }

  cout << ans << endl;
  return 0;
}
