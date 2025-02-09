/*
  Standard expectation DP
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

const int N = 100;
ld dp[N][N][N];
bool vis[N][N][N];

ld solve(int a, int b, int c) {
  if (a >= 100 || b >= 100 || c >= 100) return 0;
  ld &ans = dp[a][b][c];
  if (vis[a][b][c]) return ans;
  vis[a][b][c] = 1;
  return ans = 1+(a*solve(a+1, b, c) + b*solve(a,b+1,c) + c*solve(a,b,c+1))/(a+b+c);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, c; cin >> a >> b >> c;
  memset(vis, 0, sizeof vis);
  cout << setprecision(10) << fixed << solve(a, b, c) << "\n";
  
  return 0;
}
