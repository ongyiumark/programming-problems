#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for (int &y : coins) cin >> y;
    vector<ll> dp(x+1, INF);
    dp[0] = 0;

    for (int i = 1; i <= x; i++) {
        for (int c : coins) {
            if (i-c < 0) continue;
            dp[i] = min(dp[i], 1+dp[i-c]);
        }
    }
    if (dp[x] < INF) cout << dp[x] << "\n";
    else cout << -1 << "\n";


    return 0;
}