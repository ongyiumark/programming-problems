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

const int N = 1e5+5;
const int INF = 1e9;
int dp[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int x; cin >> x;
  memset(dp, -1, sizeof dp);
  dp[1] = 1;
  for (int i = 2; i <= x; i++) {
    int res = i;

    // Concatinate
    int tens = 10;
    while (i/tens){
      int a = i/tens;
      int b = i%tens;
      if (b != (i%(tens/10)) && b > 0){
        res = min(res, dp[a]+dp[b]);
      }
      tens *= 10;
    }

    // Multiply
    for (int d = 2; d*d <= i; d++) {
      if (i%d == 0) {
        res = min(res, dp[d]+dp[i/d]);
      }
    }

    // Add
    for (int d = 1; d <= i/2; d++) res = min(res, dp[d]+dp[i-d]);

    dp[i] = res;
  }

  cout << dp[x] << endl;
  
  return 0;
}
