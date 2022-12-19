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

const int N = 105;
const ll MOD = 1e9+7;
ll dp[N][N][2];
ll n, i, j, x, y;

ll comb[N][N];

ll c(ll n, ll k) {
  if (n < 0 || k > n) return 0;
  return comb[n][k];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(comb, 0, sizeof comb);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      if (i == 0 || j == 0) comb[i][j] = 1;
      else {
        comb[i][j] = (comb[i-1][j] + comb[i-1][j-1])%MOD;
      }
    }
  }

  int t; cin >> t;
  while(t--) {
    memset(dp, -1, sizeof dp);
    cin >> n >> i >> j >> x >> y;
    i--; j--;
    if (x > y) {
      i = n-1-i;
      j = n-1-j;
      swap(x,y);
      swap(i, j);
    }
    //cout << n << " " << i << " " << j << " " << x << " " << y << endl;
    // fix point k
    ll ans = 0;
    for (int k = 0; k < n; k++) {
      if (k <= i) continue;
      // fix a[k]
      for (int d = 1; d <= n; d++) {
        if (d == x) continue;
        if (d == y && k != j) continue;
        if (i < k && k < j) {
          if (x > d || d < y) continue;

          ll curr = c(y-d-1, j-k-1);
          curr = curr * c(d-x-1-(j-k-1), k-i-1) % MOD;
          curr = curr * c(x-1-(j-k-1)- (k-i-1), i) %MOD;
          ans += curr;
          ans %= MOD;
        } 
        //cout << k << " " << d << " " << y << endl;
        if (k >= j) {
          if (d < x || d < y) continue;

          //cout << k << " " << d << " " << y << endl;
          ll curr = c(d-y-1, k-j-1);
          curr = curr * c(y-x-1-(k-j-1), j-i-1) % MOD;
          curr = curr * c(x-1-(k-j-1)- (j-i-1), i) %MOD;
          ans += curr;
          ans %= MOD;
        }
        
      }
    } 
    cout << ans << "\n";
  }
  
  return 0;
}
