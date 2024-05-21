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

const ll MOD = 1e9+7;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k; cin >> n >> k;
  
  vector<int> nums;
  for (int i = 1; i <= n; i = n/(n/i)+1) nums.push_back(i);
  nums.push_back(n+1);
  int sz = nums.size();

  vector<unordered_map<ll,ll>> dp(k);
  for (int i = 0; i < sz-1; i++) {
    dp[0][nums[i]] = nums[i+1]-nums[i];
  }

  for (int i = 1; i < k; i++) {
    for (int j = 0; j < sz-1; j++) {
      dp[i-1][nums[j+1]] += dp[i-1][nums[j]];
      dp[i-1][nums[j+1]] %= MOD;
    }
    for (int j = sz-1; j > 0; j--) {
      dp[i-1][nums[j]] = dp[i-1][nums[j-1]];
    }
    dp[i-1][nums[0]] = 0;

    for (int j = 0; j < sz-1; j++) {
      dp[i][nums[j]] = nums[j+1]-nums[j];
      dp[i][nums[j]] *= dp[i-1][n/nums[j]+1];
      dp[i][nums[j]] %= MOD;
    }
  }

  ll total = 0;
  for (int j = 0; j < sz-1; j++) {
    total += dp[k-1][nums[j]];
    total %= MOD;
  }
  cout << total << "\n";
  
  
  return 0;
}
