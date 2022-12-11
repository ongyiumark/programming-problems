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

const int N = 3005;
const ll INF = 1e18;
ll p[N];
ll memo[N][N];
bool vis[N][N];
int n;

ll solve(int i, int pj){
  if (vis[i][pj]) return memo[i][pj];
  vis[i][pj] = 1;
  ll &ans = memo[i][pj];
  if (i == n-1) return ans = p[i];

  ans = -INF;
  if (i + pj < n) ans = max(ans, solve(i+pj, pj)+p[i]);
  if (pj > 1) ans = max(ans, solve(i,pj-1));

  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  for (int i = 0; i < n; i++) cin >> p[i];

  memset(memo, 0, sizeof memo);
  memset(vis, 0, sizeof vis);
  cout << solve(0, n-1) << endl;

  return 0;
}
