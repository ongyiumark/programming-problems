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


int main(){
  cin.tie(0)->sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> a(n);
  for (ll &x : a) cin >> x;
  
  ll total = 0;
  for (int i = 0; i < n; i++) total += a[i];
  if (total % n != 0) {
    cout << -1 << "\n";
    return 0;
  }


  ll target = total/n;
  // maximize partitions st. all partitions average `target`
  // dp[mask] = maximum number of partitions

  vector<int> dp(1LL << n, -1);
  vector<int> best_state(1LL << n, -1);
  dp[0] = 0;
  for (int mask = 1; mask < (1LL<<n); mask++) {
    ll diff = 0;
    for (int i = 0; i < n; i++) {
      if ((mask >> i)&1) diff += (a[i]-target);
    }

    for (int i = 0; i < n; i++) {
      if ((mask >> i)&1) {
        ll candidate = dp[mask^(1LL << i)];
        if (dp[mask] <= candidate) {
          dp[mask] = candidate + (diff == 0);
          best_state[mask] = i;
        }
      }
    }
  }

  ll cur_mask = (1LL << n)-1;

  vector<tuple<int,int,ll>> res;
  while (cur_mask) {
    vector<pair<ll,int>> partition;
    ll diff = 0;
    while (diff != 0 || partition.size() == 0) {
      int i = best_state[cur_mask];
      
      partition.push_back({a[i], i});

      diff += (a[i]-target);
      cur_mask = (cur_mask^(1LL<<i));
    }

    sort(partition.begin(), partition.end(), greater<pair<ll,int>>());
    int sz = partition.size();
    for (int i = 0; i < sz-1; i++) {
      int u = partition[i].second;
      int v = partition[i+1].second;

      ll carry = partition[i].first-target;

      partition[i].first -= carry;
      partition[i+1].first += carry;
      res.push_back({u,v,carry});
    }
  }

  int res_sz = res.size();
  cout << res_sz << "\n";
  for (int i = 0; i < res_sz; i++) {
    auto [x,y,z] = res[i];
    cout << x+1 << " " << y+1 << " " << z << "\n";
  }

  return 0;
}
