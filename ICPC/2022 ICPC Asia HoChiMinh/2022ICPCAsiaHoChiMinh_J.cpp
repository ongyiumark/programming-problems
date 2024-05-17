#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;


int main() {
  cin.tie(0)->sync_with_stdio(false);

  string s;
  string t = "ICPC";
  while (true) {
    cin >> s;
    if (s == "$") break;

    int n = s.size();
    vector<vector<ll>> dp(4, vector<ll>(n, 0));
    
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 4; j++) {
        if (s[i] == t[j]) {
          if (j == 0) dp[j][i] = 1;
          else dp[j][i] = (i > 1 ? dp[j-1][i-2] : 0);
        }
      
        dp[j][i] += (i > 0 ? dp[j][i-1] : 0);
      }
    }
    
    cout << dp[3][n-1] << "\n";
  }


}