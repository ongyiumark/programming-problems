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

const int N = 5005;
string words[N];
int dp[N];
int par[N];
int n, w;

int solve(int h) {
  memset(dp, 31, sizeof dp);
  memset(par, -1, sizeof par);
  dp[n] = 0;
  for (int j = n-1; j >= 0; j--) {
    int hiwidth = 0;
    for (int k = 1; k <= h && j+k <= n; k++) {
      hiwidth = max(hiwidth, (int)words[j+k-1].size());
      dp[j] = min(dp[j], dp[j+k]+hiwidth+1);
      if (dp[j+k]+hiwidth+1 <= dp[j]) {
        dp[j] = dp[j+k]+hiwidth+1;
        par[j] = j+k;
      } 
    }
  }
  /*
  for (int i = 0; i < n; i++) {
    cout << dp[i] << " ";
  }
  cout << endl;
  */
  return dp[0]-1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> w;
  for (int i = 0; i < n; i++) cin >> words[i];

  //cout << solve(1) << endl;
  int lo = 1;
  int hi = n;
  int ans = n;
  while(lo <= hi) {
    int mid = hi - (hi-lo)/2;
    if (solve(mid) <= w) {
      ans = mid;
      hi = mid-1;
    }
    else lo = mid+1;
  }
  solve(ans);
  
  int x = 0;
  vector<int> nums;
  while(x != n) {
    int m = par[x]-x;
    nums.push_back(m);
    x = par[x];
  }

  int sz = nums.size();
  cout << ans << " " << sz << endl;
  vector<string> cols[sz];  
  vector<int> width;
  int idx = 0;
  for (int j = 0; j < sz; j++) {
    int m = nums[j];
    int t = 0;
    for (int i = idx; i < idx+m; i++) {
      cols[j].push_back(words[i]);
      t = max(t, (int)words[i].size());
    }
    width.push_back(t);
    idx+=m;
  }

  for (int i = 0; i < sz; i++) {
    cout << width[i];
    if (i < sz-1) cout << " ";
    else cout << endl;
  }

  int idxs[sz];
  memset(idxs, 0, sizeof idxs);
  for (int k = 0; k < ans; k++) {
    for (int i = 0; i < sz; i++) {
      int need = width[i];
      if (idxs[i] < (int)cols[i].size()) {
        cout << cols[i][idxs[i]];
        need -= (int) cols[i][idxs[i]++].size();
      }

      while(need--) cout << " ";
      if (i < sz-1) cout << " ";
      else cout << endl;
    }
  }

  
  return 0;
}
