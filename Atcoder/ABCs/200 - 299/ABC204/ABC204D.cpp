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

  int n; cin >> n;
  vector<int> T(n);
  for (int &x : T) cin >> x;

  int total = 0;
  for (int i = 0; i < n; i++) total += T[i];

  vector<int> dp(total+1, 0);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = total; j >= T[i]; j--) {
      dp[j] += dp[j-T[i]];
    }
  }
  int ans = 1e9;
  for (int j = 0; j <= total; j++) {
    if (dp[j] == 0) continue;
    ans = min(ans, max(j, total-j));
  }
  cout << ans << "\n";
  
  return 0;
}
