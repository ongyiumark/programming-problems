/*
  Fix the number of terms to averge, denoted by d.
  Then, let DP[i][rem][cnt] be the number of ways to choose `cnt` terms 
    from a[i:] such that their sum is `rem` (mod d).
  
  This means that DP[i][rem][cnt] = DP[i+1][rem][cnt] + DP[i+1][(rem+a[i])%d][cnt+1]
  We found an interger-valued average if cnt == d and rem == 0.
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

const int N = 105;
ll MOD = 998244353;
ll a[N];
ll dp[N][N][N];

ll solve(int i, int rem, int cnt, int m, int n) {
  ll &ans = dp[i][rem][cnt];
  if (ans != -1) return ans;
  if (cnt == m) return ans = (rem == 0);
  if (i >= n) return ans = 0;

  return ans = (solve(i+1, rem, cnt, m, n) + solve(i+1, (rem+a[i])%m, cnt+1, m, n))%MOD;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll res = 0;
  for (int d = 1; d <= n; d++) {
    memset(dp, -1, sizeof dp);
    res += solve(0, 0, 0, d, n);
    res %= MOD;
  }

  cout << res << endl;
  return 0;
}
