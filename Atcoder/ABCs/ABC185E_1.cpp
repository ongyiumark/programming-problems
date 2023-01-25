/*
  Levenstein distance.
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1005;
int dp[N][N];
int a[N], b[N];

int solve(int i, int j) {
  int &ans = dp[i][j];
  if (ans != -1) return ans;
  if (i == 0) return ans = j;
  if (j == 0) return ans = i;

  if (a[i-1] == b[j-1]) return ans = min({solve(i-1, j-1), solve(i-1, j)+1, solve(i, j-1)+1});   
  else return ans = min({solve(i-1, j-1), solve(i-1, j), solve(i, j-1)})+1;

}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int j = 0; j < m; j++) cin >> b[j];

  memset(dp, -1, sizeof dp);

  cout << solve(n, m) << "\n";
  return 0;
}
