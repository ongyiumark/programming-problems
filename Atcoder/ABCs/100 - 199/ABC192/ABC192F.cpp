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
ll a[N];
ll memo[N][N][N];
bool vis[N][N][N];
int n;
ll x;

ll solve(int i, int j, int k, int l) {
  ll &ans = memo[i][j][k];
  if (vis[i][j][k]) return ans;
  vis[i][j][k] = 1;
  if (i == n) {
    if (k == x%l && j == l) return ans = 0;
    else return ans = -1e18; 
  }

  ans = -1e18;
  if (j < l) ans = max(ans, solve(i+1,j+1,(k+a[i])%l, l)+a[i]);
  ans = max(ans, solve(i+1, j, k, l));
  
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> x;
  for (int i = 0; i < n; i++) cin >> a[i];

  ll total = 0;
  for (int i = 0; i < n; i++) total += a[i];
  if (total >= x) {
    cout << 0 << "\n";
    return 0;
  }

  // fix number materials
  ll ans = 1e18;
  for (int l = 1; l <= n; l++) {
    memset(vis, 0, sizeof vis);
    ll tmp = solve(0,0,0,l);
    if (tmp < 0) continue;
    ans = min(ans, (x-tmp)/l);
  }

  cout << ans << "\n";

  return 0;
}
