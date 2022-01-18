/*
  DP where DP[n][mask] is the maximum total length using child 1, 2, ... , n with the nth child having mask.
  We need to precompute all the subsequences of each name, and sort them with their masks.
  Then, we can compute a prefix maximim of DP[n-1][mask].
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

const int N = 15;
ll dp[N][(1<<N)];
ll dpmax[N][(1<<N)];
string names[N];
vector<pair<string, int>> subseqs[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> names[i];
  
  // precompute subsequences
  for (int i = 0; i < n; i++){
    for (int mask = 1; mask < (1<<(int)names[i].size()); mask++){
      int m = names[i].size();
      string s = "";
      for (int j = 0; j < m; j++){
        if (mask&(1<<j)){
          s += names[i][j];
        }
      }
      subseqs[i].push_back({s, mask});
    }
    sort(subseqs[i].begin(), subseqs[i].end());
  }

  for (int mask = 1; mask < (1<<(int)names[0].size()); mask++){
    dp[0][mask] = __builtin_popcount(mask);
  }

  dpmax[0][0] = dp[0][subseqs[0][0].second];
  for (int i = 1; i < subseqs[0].size(); i++){
    dpmax[0][i] = max(dpmax[0][i-1], dp[0][subseqs[0][i].second]);
  }
  
  for (int i = 1; i < n; i++) {
    for (int mask = 1; mask < (1<<(int)names[i].size()); mask++){
      int m = names[i].size();
      string s = "";
      for (int j = 0; j < m; j++){
        if (mask&(1<<j)){
          s += names[i][j];
        }
      }

      int lo = 0;
      int hi = (int)subseqs[i-1].size()-1;
      int ans = -1;
      while(lo <= hi) {
        int mid = hi - (hi-lo)/2;
        if (s > subseqs[i-1][mid].first){
          ans = mid;
          lo = mid+1;
        }
        else hi = mid-1;
      }
      if (ans == -1) dp[i][mask] = -1e18;
      else dp[i][mask] = __builtin_popcount(mask) + dpmax[i-1][ans];
    }
    dpmax[i][0] = dp[i][subseqs[i][0].second];
    for (int j = 1; j < subseqs[i].size(); j++){
      dpmax[i][j] = max(dpmax[i][j-1], dp[i][subseqs[i][j].second]);
    }
  }

  ll ans = -1e18;
  for (int mask = 1; mask < (1<<(int)names[n-1].size()); mask++){
    ans = max(ans, dp[n-1][mask]);
  }
  if (ans < 0) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}
