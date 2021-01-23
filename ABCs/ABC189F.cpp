/*
  It's impossible if and only if there's a consecutive blocked segment of length m.

  Suppose there's no blocked cells. We can solve for the answer recusively.
  Let dp[i] represent the expected number of moves starting from i.
  Thus, dp[i] = (dp[i+1] + dp[i+2] + ... + dp[i+m])/m + 1
  We can use prefix sums (suffix in this case) to keep each dp state O(1).

  Now for the blocked cells, dp[i] = dp[0]. However, this is no longer acyclic so we can't solve for it this way.
  Instead, we can keep track of the results in terms of dp[0].
  That is, dp[i] will have two numbers (a,b) representing a*dp[0]+b.

  Finally, solve dp[0] = a*dp[0]+b.
*/

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
pair<ld,ld> ans[N];
pair<ld,ld> pref[N];

pair<ld,ld> div_pair(pair<ld,ld> p, ll x){
  return {p.first/x, p.second/x};
}

pair<ld,ld> add_pairs(pair<ld,ld> a, pair<ld,ld> b){
  return {a.first+b.first, a.second+b.second};
}

pair<ld,ld> range_sum(int a, int b, int n){
  if (b+1 > n) return pref[a];
  return add_pairs(pref[a], div_pair(pref[b+1],-1));
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, k; 
  cin >> n >> m >> k;
  memset(ans, 0, sizeof ans);

  int consecutive = 0;
  int longest = 0;
  int curr = -1;
  for (int i = 0; i < k; i++){
    int a; cin >> a;
    ans[a] = {1,0};

    if (curr+1 == a) consecutive++;
    else consecutive = 1;
    longest = max(longest, consecutive);
    curr = a;
  }

  if (longest >= m) {
    cout << -1 << endl;
    return 0;
  }

  ans[n] = pref[n] = {0,0};
  for (int i = n-1; i >= 0; i--){
    // Skip if blocked.
    if (ans[i].first == 0) {
      ans[i] = div_pair(range_sum(i+1, i+m, n),m);
      ans[i].second++;
    }
    pref[i] = add_pairs(pref[i+1], ans[i]);
  }

  cout << fixed << setprecision(6) <<  ans[0].second/(1-ans[0].first) << endl;
  return 0;
}
