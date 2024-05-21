/*
  Digit DP.
  DP[i][1] denotes the number of pairs when a+b match the top i digits of s.
  DP[i][0] denotes the number of pairs when a+b is already less than s.

  If a+b is already less than s, then we can add any digit with no constraint. That is, we can add (0,0), (0,1), and (1,0).
    So, DP[i+1][0] += 3*DP[i][0]

  If a+b matches the top i digits of s, then we need to consider cases.
    If s[i] == 0, then we can only add (0,0). So, DP[i+1][1] += DP[i][1].
    If s[i] == 1, then we can add (0,0), (1,0), or (0,1).
      If we add (0,0), then a+b becomes less than s. So, DP[i+1][0] += DP[i][1].
      If we add (1,0) or (0,1), then a+b matches the top i+1 digits of s. So, DP[i+1][1] += 2*DP[i+1][1].

  The base case is DP[0][1] = 1 because there is exactly one way to match an empty string.
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

const ll MOD = 1e9+7;
const int N = 1e5+5;
ll dp[N][2];

string s;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s;
  int n = s.size();
  memset(dp, 0, sizeof dp);
  dp[0][1] = 1;
  for (int i = 0; i < n; i++){
    dp[i+1][0] += 3*dp[i][0];
    if (s[i] == '0'){
      dp[i+1][1] += dp[i][1];
    }
    else {
      dp[i+1][0] += dp[i][1];
      dp[i+1][1] += 2*dp[i][1];
    }
    dp[i+1][0] %= MOD;
    dp[i+1][1] %= MOD;
  }
  
  cout << (dp[n][1]+dp[n][0])%MOD << endl;
  return 0;
}
