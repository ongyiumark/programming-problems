/*  
  Use DP to find out possible combinations of sugar and water possible.
  From those possbilities, only consider the ones that satisfy the constraints.

  Use algebra to not deal with floating point numbers.
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

bool dp[3001][3001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  memset(dp, 0, sizeof dp);
  dp[0][0] = 1;
  for (int i = 0; i <= f; i++){
    for (int j = 0; j <= f; j++){
      if (!dp[i][j]) continue;
      if (j + 100*a <= f) dp[i][j+100*a] = 1;
      if (j + 100*b <= f) dp[i][j+100*b] = 1;
      if (i + c <= f) dp[i+c][j] = 1;
      if (i + d <= f) dp[i+d][j] = 1;
    }
  }
  int total = 0;
  int sugar = 0;
  for (int i = 0; i <= f; i++){
    for (int j = 1; j <= f; j++){
      if (i + j > f) continue;
      if (j*e < i*100) continue;
      if (!dp[i][j]) continue;
      if (total == 0){
        total = i+j;
        sugar = i;
      }
      else if (sugar*(i+j) < i*(total)){
        total = i+j;
        sugar = i;
      }
    }
  }
  cout << total << " " << sugar << endl;
  return 0;
}
