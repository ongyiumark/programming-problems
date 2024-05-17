#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
const int MOD = 998244353;
vector<int> pow2(20, 1);
vector dp(20, vector<int>(20, -1));

int solve(int idx, int dep) {
    if (idx >= n) return 1;

    int& ans = dp[idx][dep];
    if (ans != -1) return ans;
    ans = 0;
    for (int i = dep+1; i >= 0; --i) {
        ans = (ans + solve(idx+1, i)) % MOD;
        ans = (ans + pow2[i]) % MOD;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
    }

    for (int i = 1; i < n; ++i) {
        pow2[i] = 2*pow2[i-1];
    }

    cout << solve(1, 0) << endl;

    return 0;
}
