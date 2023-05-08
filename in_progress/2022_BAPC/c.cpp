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

int c, t, r;
ld p;

const int N = 2e3+5;
ld no_save[N];
bool vis[N];
ld memo[N];

ld solve(int i) {
  if (i == 1) return no_save[i];
  if (vis[i]) return memo[i];

  vis[i] = 1;
  ld &ans = memo[i];
  
  ans = no_save[i];
  for (int j = 1; j < i; j++) {
    ans = min(ans, solve(j) + t + no_save[i-j]);
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> c >> t >> r >> p;
  no_save[0] = 0;
  for (int i = 1; i <= c; i++) {
    no_save[i] = (no_save[i-1] + 1 + p*r)/(1-p);
  }
  memset(vis, 0, sizeof vis);
  memset(memo, 0, sizeof memo);

  cout << setprecision(20) << fixed;
  cout << solve(c) + t << "\n";
  
  return 0;
}
