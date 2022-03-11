/*
  Just use a map for the costs.
  We can show that there are only N*(4N) possible sums.
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

const int N = 100+5;
const int VMAX = 1e7+5;
ll W[N], V[N];
map<ll, ll> dp, ndp; 

int n, w;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> w;
  for (int i = 0; i < n; i++) {
    cin >> W[i] >> V[i];
  }

  dp[0] = 0;
  for (int i = 0; i < n; i++){
    for (auto it = dp.rbegin(); it != dp.rend(); it++){
      ndp[it->first + W[i]] = max(ndp[it->first + W[i]], it->second+V[i]);
    }
    for (auto it = ndp.begin(); it != ndp.end(); it++){
      dp[it->first] = max(dp[it->first], it->second);
    }
    ndp.clear();
  }

  ll ans = 0;
  for (auto it = dp.rbegin(); it != dp.rend(); it++){
    if (it->first <= w) {
      ans = max(it->second, ans);
    }
  }
  
  cout << ans << endl;

  return 0;
}
