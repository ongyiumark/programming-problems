/*
  N^3 dp with the last positions of r,g,b as states. We can compute for the current position by max({r,g,b}).
  We can also check if the conditions are met depending on these positions.
  To speed up, we can assume WLOG a <= b <= c in dp[a][b][c]. This reduces the time complexity by a factor of 6.
    This is because dp[a][b][c] = dp[a][c][b] = ... 

  There's a better way to solve this. Refer to: https://atcoder.jp/contests/arc074/submissions/11766036
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

const int N = 300+5;
const ll MOD = 1e9+7;
int l[N], r[N], x[N];
int n, m;
ll dp[N][N][N];

ll solve(int rd, int g, int bl){
  if (rd == g && rd != 0) return 0;
  if (rd == bl && rd != 0) return 0;
  if (bl == g && bl != 0) return 0;
  int a = min({rd,g,bl});
  int c = max({rd,g,bl});
  int b = rd+g+bl-a-c;
  ll ans = dp[a][b][c];
  if (ans != -1) return ans;

  for (int i = 0; i < m; i++){
    if (r[i] != c) continue;
    int cnt = (int)(l[i] <= a)+(int)(l[i] <= b)+(int)(l[i] <= c);
    if (x[i] != cnt) return dp[a][b][c] = 0;
  }
  if (a == b && b == 0) return solve(a,b,c-1); 
  ans = 0;
  if (b == c-1) {
    for (int i = 0; i < b; i++)
      ans = (ans + solve(i, a, b))%MOD;
  }
  else ans = (ans + solve(a,b,c-1))%MOD;

  return dp[a][b][c] = ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < m; i++){
    cin >> l[i] >> r[i] >> x[i];
  }

  memset(dp, -1, sizeof dp);
  dp[0][0][0] = 1;
  ll ans = 0;
  for (int i = 0; i < n; i++){
    for (int j = i+1; j < n; j++){
      ans = (ans + solve(i,j,n))%MOD;
    }
  }
  ans = ans*6%MOD;
  ans = (ans + solve(0,0,n)*3)%MOD;
  cout << ans << endl;
  return 0;
}
