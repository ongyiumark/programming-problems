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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, c; cin >> n >> c;
  vector<int> w(n);

  for (int &x : w) cin >> x;
  sort(w.begin(), w.end());

  // If including everything works...
  ll total = 0;
  for (int x : w) total += x;
  if (total <= c) {
    cout << total << "\n";
    return 0;
  }

  vector<bool> dp(c + 1);
  vector<vector<int>> mex(n+1, vector<int>(c+1,0));

  dp[0] = true;
  for (int i = 0; i < n; i++) {
    for (int j = c; j >= 0; j--) {
      if (j + w[i] > c) continue;
      if (dp[j]) {
        dp[j+w[i]] = true; 
        mex[i+1][j+w[i]] = (mex[i][j] == i ? i+1 : mex[i][j]);
      }
    }
    for (int j = 0; j <= c; j++) {
      mex[i+1][j] = max(mex[i][j], mex[i+1][j]);
    }
  }

  int ans = c;
  for (int i = c; i >= 0; i--) {
    if (!dp[i]) continue;
    if (i+w[mex[n][i]] > c) ans = min(ans, i);
  }
  cout << ans << "\n";
  
  return 0;
}
