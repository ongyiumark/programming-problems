#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x; cin >> n >> x;
    vector<int> h(n), s(n);
    for (int &y : h) cin >> y;
    for (int &y : s) cin >> y;
    vector<ll> dp(x+1, 0);

    for (int i = 0; i <= n; i++) {
        for (int j = x; j >= 0; j--) {
            if (j + h[i] > x) continue;
            dp[j+h[i]] = max(dp[j+h[i]], dp[j]+s[i]);
        }
    }
    cout << dp[x] << "\n";
    return 0;
}