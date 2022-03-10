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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll n; cin >> n;
  ll lo = 1;
  ll hi = 1e9;
  ll ans = -1;
  while(lo <= hi){
    ll mid = hi - (hi-lo)/2;
    if (mid*(mid+1)/2 <= n){
      ans = mid;
      lo = mid+1;
    }
    else hi = mid-1;
  }

  ll res = n - ans*(ans+1)/2;
  cout << (res == 0 ? ans : res) << endl; 

  return 0;
}
