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
const ll MOD = 1e9+7;
ll dp[N][55];
set<string> track;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string p, s;
  cin >> p >> s;
  string ss = s+s;
  
  int n = s.size();
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    s = ss.substr(i, n);
    if (track.find(s) != track.end()) continue;
    track.insert(s);
    
    vector<int> idx[26];
    for (int i = 0; i < n; i++) {
      idx[s[i]-'a'].push_back(i);
    }

    memset(dp, 0, sizeof dp);
    for (int i = 0; i < p.size(); i++) {
      if (i > 0) {
        for (int j = 0; j < n; j++) {
          dp[i][j] += dp[i-1][j];
          dp[i][j] %= MOD;
        }
      }
      for (int j : idx[p[i]-'a']) {
        if (i < j) dp[i][j] = 0; // j <= i
        else if (i > 0 && j > 0) dp[i][j] += dp[i-1][j-1];
        else dp[i][j]++;

        dp[i][j] %= MOD;
      }
    }

    int m = p.size();
    ans += dp[m-1][n-1];
    ans %= MOD;
  }
  cout << ans << endl;


  return 0;
}
