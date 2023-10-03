#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int INF = 1e9;

int lev(int j, int n, int m, string &s, vector<vector<int>> &dp) {
    // edit distance of s[j-n:j:-1] and s[j:j+m]
    int &ans = dp[n][m];
    if (ans != -1) return ans;

    // if empty
    if (m == 0) return ans = n;
    if (n == 0) return ans = m;

    if (s[j-1-(n-1)] == s[j+(m-1)]) ans = lev(j, n-1, m-1, s, dp);
    else ans = 1 + min({lev(j, n, m-1, s, dp), lev(j, n-1, m, s, dp), lev(j, n-1, m-1, s, dp)});

    return ans;
}

int solve(int i, int j, string &s, vector<vector<int>> &memo, vector<vector<vector<int>>> &dp) {
    int &ans = memo[i][j];
    if (ans != -1) return ans;

    int n = j-i;
    int max_m = (int)s.size()-j;

    ans = 1+lev(j, n, max_m, s, dp[j]);
    for (int m = 1; m < max_m; m++) {
        ans = min(ans, 1+lev(j, n, m, s, dp[j])+solve(j, j+m, s, memo, dp));
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;

    int n = s.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>());
    for (int j = 0; j < n; j++) {
        dp[j].resize(j+1, vector<int>(n-j+1, -1));
        lev(j, j, n-j, s, dp[j]); // precompute
    }

    vector<vector<int>> memo(n+1, vector<int>(n+1, -1));
    cout << solve(0, 0, s, memo, dp) << "\n";
    return 0;
}