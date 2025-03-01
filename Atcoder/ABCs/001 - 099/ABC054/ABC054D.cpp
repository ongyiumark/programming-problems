/*
  Knapsack problem with two indexes.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 40;
int a[N], b[N], c[N];
int dp[401][401];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, ma, mb; cin >> n >> ma >> mb;
  for (int i = 0; i < n; i++){
    cin >> a[i] >> b[i] >> c[i];
  }

  memset(dp, 0x3F, sizeof dp);

  dp[0][0] = 0;
  for (int i = 0; i < n; i++){
    for (int j = 400; j >= 0; j--){
      for (int k = 400; k >= 0; k--){
        if (j + a[i] > 400) continue;
        if (k + b[i] > 400) continue;
        dp[j+a[i]][k+b[i]] = min(dp[j+a[i]][k+b[i]], dp[j][k]+c[i]);
      }
    }
  }

  int x = 1;
  int ans = 1e9;
  while (true){
    if (ma*x > 400 || mb*x > 400) break;
    ans = min(ans, dp[ma*x][mb*x]);
    x++;
  }
  if (ans == 1e9) ans = -1;
  cout << ans << endl;
  return 0;
}
