/*
  DP[i][state] which counts the ways to have result of 'state' (TRUE/FALSE) with the first i variables.

  To have a result of TRUE with an OR operation, we have:
    (10, 11, 01) => DP[i][1] := DP[i-1][1]+DP[i-1][1]+DP[i-1][0]

  To have a result of FALSE with an OR operation, we have:
    (00) => DP[i][0] := DP[i-1][0]

  To have a result of TRUE with an AND operation, we have:
    (11) => DP[i][1] := DP[i-1][1]

  To have a result of FALSE with an AND operation, we have:
    (01, 00, 10) => DP[i][0] := DP[i-1][0]+DP[i-1][0]+DP[i-1][1]

  The answer is DP[n][1].
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

const int N = 60;
bool is_or[N];
ll dp[N][2];

ll solve(int i, int t){
  ll &ret = dp[i][t];
  if (ret != -1) return ret;
  if (i == 0) return ret = 1;
  if (is_or[i-1]){
    if (t) ret = solve(i-1,0)+solve(i-1,1)*2;
    else ret = solve(i-1,0);
  }
  else {
    if (t) ret = solve(i-1,1);
    else ret = solve(i-1,0)*2+solve(i-1,1);
  }
  return ret;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < n; i++){
    string s; cin >> s;
    is_or[i] = (s == "OR"); 
  }

  memset(dp, -1, sizeof dp);
  cout << solve(n,1) << endl; 

  return 0;
}
