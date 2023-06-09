#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<pair<int,int>> factorize(int n) {
    vector<pair<int,int>> factors;
    for (int i = 2; i*i <= n; ++i) {
        if (n%i == 0) {
            factors.emplace_back(i, 0);
        }
        while (n%i == 0) {
            n /= i;
            ++factors.back().second;
        }
    }
    if (n != 1) factors.emplace_back(n, 1);
    return factors;
}

int solve(int n, int m) {
    vector<pair<int,int>> factors = factorize(m);
    unordered_map<int,int> cnt;
    int ans = -1;
    for (auto [x, mult] : factors) {
        int pow = x;
        while (pow <= n) {
            cnt[x] += n / pow;
            pow *= x;
            cout << cnt[x] << " " << pow << endl;
        }
        if (ans == -1) ans = cnt[x] / mult;
        else ans = min(ans, cnt[x] / mult);
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        cout << solve(n, m) << '\n';
    }

    return 0;
}