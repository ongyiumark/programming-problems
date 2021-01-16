/*
  Classic knapsack problem but you can't create a normal array, so use a hashmap instead.
  This was not the intended solution.

  We have to use the fact that w_1 <= w_i <= w_1 + 3, meaning that there are only 4 possible weights. 
  So, simply try all combinations of ax_1 + bx_2 + cx_3 + dx_4 <= W where x_1 to x_4 are the possible weights.
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

const int N = 100;
struct item{
  ll w, v;
};

item arr[N];
map<ll, ll> dp;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, w; cin >> n >> w;
  for (int i = 0; i < n; i++){
    cin >> arr[i].w >> arr[i].v;
  }

  dp[0] = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++){
    for (auto it = dp.rbegin(); it != dp.rend(); it++){
      ll j = it->first;
      if (dp.count(j+arr[i].w)) dp[j+arr[i].w] = max(dp[j+arr[i].w], dp[j]+arr[i].v);
      else dp[j+arr[i].w] = dp[j]+arr[i].v;
      if (j+arr[i].w <= w) ans = max(ans, dp[j+arr[i].w]);
    }
  }
  cout << ans << endl;
  return 0;
}
