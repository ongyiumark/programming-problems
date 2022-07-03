/*
  Fix the number of things with weight 3, then use DP to solve the maximum cost with just weights 1 and 2.
  DP[i] = {a,b,c} where
    a is the number of things with weight 1
    b is the number of things with weight 2
    c is the best cost
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

const int N = 1e5+5;
const int M = 3e5+5;
vector<ll> x[3];
ll pref[3][N];

tuple<int, int, ll> dp[M];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int w; ll c;
    cin >> w >> c;
    x[w-1].push_back(c);
  }

  for (int i = 0; i < 3; i++) sort(x[i].begin(), x[i].end(), greater<ll>());
  
  for (int i = 0; i < 3; i++) {
    pref[i][0] = 0;
    
    for (int j = 0; j < x[i].size(); j++) {
      pref[i][j+1] = pref[i][j] + x[i][j];
    }
  }

  for (int i = 0; i <= m; i++) dp[i] = {0,0,0};
  
  for (int i = 0; i <= m; i++) {
    auto [a,b,c] = dp[i];

    if (i+1 <= m && a < x[0].size() && get<2>(dp[i+1]) <= c+x[0][a]) dp[i+1] = {a+1, b, c+x[0][a]};
    if (i+2 <= m && b < x[1].size() && get<2>(dp[i+2]) <= c+x[1][b]) dp[i+2] = {a, b+1, c+x[1][b]};
  }

  tuple<int,int, ll> hi = {0,0,0};
  for (int i = 0; i <= m; i++){
    auto [a,b,c] = dp[i];
    if (get<2>(hi) <= c) hi = dp[i];
    else dp[i] = hi; 
  }

  ll ans = 0;
  for (int i = 0; i <= x[2].size(); i++) {
    // Fix number of weight 3.
    if (m-3*i < 0) break;

    auto [a,b,c] = dp[m-3*i];
    ans = max(ans, c + pref[2][i]);
  }

  cout << ans << endl;
  
  return 0;
}
