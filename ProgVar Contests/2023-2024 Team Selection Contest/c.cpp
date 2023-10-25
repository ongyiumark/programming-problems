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

int n;
vector<ld> p;
vector<ld> memo;
vector<bool> seen;

ld solve(int mask) {
  if (seen[mask]) return memo[mask];
  seen[mask] = 1;
  ld &ans = memo[mask];
  if (__builtin_popcount(mask) == 2) return ans = 0;

  ld product = 1;
  ld product_c = 1;
  for (int i = 0; i < n; i++) {
    if ((mask&(1<<i)) == 0) continue;
    product *= p[i];
    product_c *= (1-p[i]);
  }

  ld prob_move = 0;
  for (int i = 0; i < n; i++) {
    if ((mask&(1<<i)) == 0) continue;
    prob_move += product/p[i]*(1-p[i]) + product_c/(1-p[i])*p[i];
  }
  ld prob_stay = 1-prob_move;

  ans = 0;
  for (int i = 0; i < n; i++) {
    if ((mask&(1<<i)) == 0) continue;
    ld prob = product/p[i]*(1-p[i]) + product_c/(1-p[i])*p[i];
    ans += prob*solve(mask^(1<<i));
  }
  ans = (1+ans)/(1-prob_stay);

  return ans;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  p.assign(n, 0);
  for (int i = 0; i < n; i++) cin >> p[i];

  cout << setprecision(11) << fixed;
  memo.assign((1<<n), 0);
  seen.assign((1<<n), 0);
  cout << solve((1<<n)-1) << "\n";
  
  return 0;
}
