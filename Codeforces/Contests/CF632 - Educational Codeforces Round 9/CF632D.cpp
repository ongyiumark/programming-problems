/*
  Maintain an array of counts for each LCM.
    DP[i] = longest subsequence whose LCM is i.
  
  We can simply go through all multiples of A and add 1 to the DP.

  It may be the case that there are lots of A = 1, which would make this O(NM).
  So, we process all same values of A at the same time.

  To get the actual LCM (and not some multiple of LCM),
    we get the highest DP[i] and the lowest i if there are ties.
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,ll> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e6+5;
int a[N];
int n, m;

ll dp[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  map<int,int> nums;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    nums[a[i]]++;
  }

  memset(dp, 0, sizeof dp);
  for (auto it : nums) {
    for (int j = 1; j*it.first <= m; j++) {
      dp[j*it.first] += it.second;
    }
  }

  ll kmax = 0;
  ll l = 1;
  for (int i = 1; i <= m; i++) {
    if (kmax < dp[i]) {
      kmax = dp[i];
      l = i;
    }
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (l%a[i] == 0) ans.push_back(i+1);
  }
  cout << l << " " << kmax << endl;
  for (int i = 0; i < kmax; i++) {
    cout << ans[i];
    if (i != kmax-1) cout << " ";
    else cout << endl;
  }
  
  return 0;
}
