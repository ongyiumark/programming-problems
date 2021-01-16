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

vector<ll> weights[4];
vector<ll> prefix[4];
ll n, W; 
ll w1;
ll ans = 0;

void solve(int i, ll totalw, ll totalv){
  if (i == 4){
    if (totalw <= W) ans = max(ans, totalv);
    return;
  }
  solve(i+1, totalw, totalv);
  for (int j = 0; j < prefix[i].size(); j++){
    solve(i+1, totalw+(j+1)*(w1+i), totalv+prefix[i][j]);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> W;
  ll v1; cin >> w1 >> v1;
  weights[0].push_back(v1);
  for (int i = 1; i < n; i++){
    int w, v; cin >> w >> v;
    w -= w1;
    weights[w].push_back(v);
  }

  for (int i = 0; i < 4; i++){
    int m = weights[i].size();
    sort(weights[i].begin(), weights[i].end(), greater<ll>());
    prefix[i].resize(m);
    if (m >= 1) prefix[i][0] = weights[i][0];
    for (int j = 1; j < m; j++){
      prefix[i][j] = prefix[i][j-1] + weights[i][j];
    }
  }

  solve(0,0,0);
  cout << ans << endl;
  return 0;
}
