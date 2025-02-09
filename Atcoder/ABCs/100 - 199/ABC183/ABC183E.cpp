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

const int N = 2e3+5;
const ll MOD = 1e9+7;
ll row[N], col[N], diag[2*N];
ll dp[N][N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, 0, sizeof dp);
  memset(row, 0, sizeof row);
  memset(col, 0, sizeof col);
  memset(diag, 0, sizeof diag);

  int h, w; cin >> h >> w;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      char ch; cin >> ch;

      if (ch == '#') {
        row[i] = col[j] = diag[i-j+w] = 0;
        dp[i][j] = 0;
        continue;
      }

      if (i > 0 || j > 0) {
        dp[i][j] = (row[i] + col[j] + diag[i-j+w]) % MOD;
      }
      else {
        dp[i][j] = 1;
      }

      row[i] = (row[i] + dp[i][j]) % MOD;
      col[j] = (col[j] + dp[i][j]) % MOD;
      diag[i-j+w] = (diag[i-j+w] + dp[i][j]) % MOD;
    }
  }

  cout << dp[h-1][w-1] << "\n";


  
  return 0;
}
