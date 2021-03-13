/*
  DP[i][ct] solution. ith night market at time ct.
  There are three cases:
    Include night market i. (We increase ct here.)
    Do not include night market i.
    We do nothing. (Increase ct by 1).
  You can only include i if s is not between ct and ct + b[i] AND ct + b[i] <= t.
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

const int N = 3000;
int a[N], b[N];
int dp[N+1][N+1];
int n, t, s; 
int solve(int i, int ct){
  if (i >= n) return 0;
  int &ret = dp[i][ct];
  if (ret != -1) return ret;
  ret = 0;
  ret = max(ret, solve(i+1, ct));
  if (ct + 1 < t) ret = max(ret, solve(i, ct+1));
  int l = ct;
  int r = ct+b[i];
  if (r <= t && !(l < s && s < r)) {
    ret = max(ret, a[i]+solve(i+1,r));
  }
  return ret;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> t >> s;
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

  memset(dp, -1, sizeof dp);
  cout << solve(0, 0) << endl;
  return 0;
}
