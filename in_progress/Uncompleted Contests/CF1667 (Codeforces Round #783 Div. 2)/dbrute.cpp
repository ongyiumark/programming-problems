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

const int N = 5e5+5;
const ll INF = 1e18;
ll a[N];
ll pref[N];
ll dp[N];
ll best[N];
int n;

ll cost(int l, int r) {
  ll s = pref[r]-pref[l-1];
  if (s > 0) return r-l+1;
  else if (s < 0) return -(r-l+1);
  return 0;
}
/*
void solve_dp(int k_L, int k_R, int n_L, int n_R) {
  int n_M = (n_L + n_R)/2;
  dp[n_M] = INF;
  int best_k = -1;
  for (int k = k_L; k <= n_M && k <= k_R; k++) {
    if (dp[k]+cost(k+1,n_M) < dp[n_M]) {
      dp[n_M] = dp[k]+cost(k+1,n_M);
      best_k = k;
    }
  }
  if (n_L <= n_M-1) solve_dp(k_L, best_k, n_L, n_M-1);
  if (n_M+1 <= n_R) solve_dp(best_k, k_R, n_M+1, n_R);
}
*/



ll solve(int tn) {
  ll &ans = dp[tn];
  if (ans != -1) return ans;
  if (tn == 0) return 0;
  ans = -INF;
  for (int i = 1; i <= tn; i++) {
    ll tmp = solve(i-1) + cost(i, tn);
    cout << tn << " " << i << " " << tmp << endl; 
    
    if (ans < tmp) {
      best[tn] = i;
      ans = tmp;
    }
  }
  return ans;
}


void testcase() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  pref[0] = 0;
  for (int i = 0; i < n; i++) {
    pref[i+1] = pref[i] + a[i];
  }

  memset(dp, -1, sizeof dp);
  memset(best, 0, sizeof best);
  //cout << solve(n) << endl;
  for (int i = 0; i <= 2; i++) {
    solve(i);
    cout << best[i] << endl;

  }
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--) {
    testcase();
  }
  return 0;
}
