/*
  DP[i][j][I/O] is the length of the longest alternating sequence from s[i:] and t[j:] starting with I/O.
  If we reach a deadend while trying to find an 'I' return -1. 
  If we reach a deadend while trying to find an 'O' return 0.
  Otherwise, return max(DP[i+1][j][O/I], DP[i][j+1][O/I]).
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

int m, n;
string s, t;
const int N = 2005;
int dp[N][N][2];
int solve(int i, int j, bool I){
  int &res = dp[i][j][I];
  if (res != -1) return res;
  res = 0;
  char c = (I ? 'I' : 'O');
  if (i < m && s[i] == c) res = max(res, solve(i+1, j, !I)+1);
  if (j < n && t[j] == c) res = max(res, solve(i, j+1, !I)+1);
  if (res == 0) return res = res-I;
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> m >> n;
  cin >> s >> t;
  memset(dp, -1, sizeof dp);
  int ans = 0;
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      ans = max(ans, solve(i, j, 1));
    }
  }
  cout << ans << endl;
  return 0;
}
