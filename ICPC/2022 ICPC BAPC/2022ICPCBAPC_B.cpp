#include <bits/stdc++.h>
using namespace std;

using ld = long double;
typedef long long ll;
const ld pi = acos(-1);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<pair<ll,ll>> pts(n);
    for (auto& [x, y] : pts) cin >> x >> y;

    ld ans = 0;
    for (int _ = 0; _ < 2; ++_) {
        ll x_max = 0, y_max = 0;
        for (int i = 1; i < n-1; ++i) {
            auto [x, y] = pts[i];
            if (x_max*y < x*y_max) continue;
            ans = max(ans, atanl((ld)y/x));
            x_max = x;
            y_max = y;
        }

        // flip
        ll max = pts.back().first;
        for (auto& [x, y] : pts) {
            x = max-x;
        }
        reverse(pts.begin(), pts.end());
    }

    cout << setprecision(20) << fixed << (ans * 180 / pi) << '\n';

    return 0;
}