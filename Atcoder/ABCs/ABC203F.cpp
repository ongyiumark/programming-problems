/*
  DP[i][j] is given the first i, the minimum number of weeds to pull in order to finish in at most j operations.
  If we pull the ith weed, DP[i-1][j].
  If we don't pull the ith weed, DP[half_idx[i-1]][j-1].

  Thus, DP[i][j] = min(DP[i-1][j], DP[half_idx[i-1]][j-1]).
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

const int N = 2e5+5;
ll A[N];
int half_idx[N];
ll dp[N][50];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k; cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> A[i];
  sort(A, A+n);

  for (int i = 0; i < n; i++) {
    int lo = 0;
    int hi = i-1;
    int ans = -1;
    while(lo <= hi) {
      int mid = hi - (hi-lo)/2;
      if (A[mid]*2 <= A[i]) {
        ans = mid;
        lo = mid+1;
      }
      else hi = mid-1;
    }
    half_idx[i] = ans+1;
  }

  memset(dp, 0, sizeof dp);
  for (int i = 1; i <= n; i++) {
    dp[i][0] = i;
    for (int j = 1; j < 50; j++) {
      dp[i][j] = min(dp[i-1][j]+1, dp[half_idx[i-1]][j-1]);
    }
  }

  for (int j = 0; j < 50; j++) {
    if (dp[n][j] <= k) {
      cout << j << " " << dp[n][j] << endl;
      return 0;
    }
  }

  return 0;
}
