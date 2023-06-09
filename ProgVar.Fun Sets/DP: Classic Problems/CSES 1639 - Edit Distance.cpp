#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t; cin >> s >> t;
    int n = s.size();
    int m = t.size();

    int dp[n+1][m+1];
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) dp[i][j] = max(i,j);
            else dp[i][j] = min({dp[i][j-1]+1, dp[i-1][j]+1, dp[i-1][j-1] + (int)(s[i-1] != t[j-1])});
        }
    }
    cout << dp[n][m] << "\n";
    return 0;
}