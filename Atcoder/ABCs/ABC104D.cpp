/*
  We can solve this with DP.
  We need to keep track of the number of As, number of ABs, and number of ABCs for each step.

  If the current letter is 'A', we add the number of possible strings to the number of As. 
    For each possible string, we can append A.
  If the current letter is 'B', we add the number of As to the number of ABs.
  If the current letter is 'C', we add the number of ABs to the number of ABCs.

  Lastly, if the current letter is '?', we do all three above. However, we multiply all of them by three first.
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

const int N = 1e5;
const int MOD = 1e9+7;
ll dp[3][N+1]; // no. of A, AB, ABC
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s; cin >> s;
  int n = s.size();
  memset(dp, 0, sizeof dp);

  ll mult = 1;
  for (int i = 0; i < n; i++){
    for (int x = 0; x < 3; x++)
      dp[x][i+1] = dp[x][i];

    if (s[i] == 'A') dp[0][i+1] = dp[0][i]+mult;
    else if (s[i] == 'B') dp[1][i+1] = dp[1][i] + dp[0][i];
    else if (s[i] == 'C') dp[2][i+1] = dp[2][i] + dp[1][i];
    else {
      dp[0][i+1] = dp[0][i]*3 + mult;
      dp[1][i+1] = dp[1][i]*3 + dp[0][i];
      dp[2][i+1] = dp[2][i]*3 + dp[1][i];
      mult *= 3;
      mult %= MOD;
    }

    for (int x = 0; x < 3; x++){
      dp[x][i+1] %= MOD;
    }
  }
  
  cout << dp[2][n] << endl;
  return 0;
}
