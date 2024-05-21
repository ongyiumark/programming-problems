/*
  For each dice score, we can binary search for the number of heads needed to win.
    Snuke needs consecutive heads because the moment he gets tails, he loses.
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

ll n, k;
const int N = 1e5+5;
ll heads[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  for (ll i = 1; i <= n; i++){
    int lo = 0;
    int hi = 20;
    int ans = 0;
    while(lo <= hi){
      int mid = hi-(hi-lo)/2;
      if (i*(1LL<<mid) >= k){
        ans = mid;
        hi = mid-1;
      }
      else lo = mid+1;
    }

    heads[i] = ans;
  }

  ll hipow = 0;
  for (int i = 1; i <= n; i++){
    hipow = max(hipow, heads[i]);
  }
  ll total = 0;
  for (int i = 1; i <= n; i++){
    heads[i] = hipow - heads[i];
    total += (1LL<<heads[i]);
  }

  cout << setprecision(15) << fixed << (ld)total/(1LL<<hipow)/n << endl;
  return 0;
}
