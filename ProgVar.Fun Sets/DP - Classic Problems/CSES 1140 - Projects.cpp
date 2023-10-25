#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<tuple<ll,ll,ll>> projects(n);
    for (auto &[a,b,p] : projects) {
        cin >> a >> b >> p;
    }

    sort(projects.begin(), projects.end());
    vector<ll> dp(n+1);
    for (int i = n-1; i >= 0; i--) {
        ll ans = dp[i+1];

        int lo = i+1;
        int hi = n-1;
        int idx = n;

        auto &[a, b, p] = projects[i];

        while (lo <= hi) {
            int mid = hi - (hi-lo)/2;
            if (get<0>(projects[mid]) > b) {
                idx = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }

        ans = max(ans, p + dp[idx]);
        dp[i] = ans;
    }

    cout << dp[0] << "\n";

    return 0;
}