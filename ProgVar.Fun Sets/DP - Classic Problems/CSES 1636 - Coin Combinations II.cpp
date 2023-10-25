#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2e18;

const int MOD = 1e9+7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for (int &y : coins) cin >> y;
    vector<ll> dp(x+1, 0);
    dp[0] = 1;

    for (int c : coins) {
        for (int i = 0; i <= x; i++) {
            if (i-c < 0) continue;
            dp[i] += dp[i-c];
            dp[i] %= MOD;
        }
    }

    cout << dp[x] << "\n";

    return 0;
}