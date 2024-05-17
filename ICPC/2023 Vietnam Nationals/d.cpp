#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    const int MAXN = 2e5;
    int T; cin >> T;
    vector<int> a(MAXN);
    vector<int> cnt(MAXN);
    while (T--) {
        int n; cin >> n;
        a.resize(n);
        for (int& i : a) cin >> i;

        int l = 0, r = 0;
        cnt[a[0]] = 1;
        int ans = 0;
        while (r < n and l <= r) {
            while (cnt[a[r]] > 1) {
                --cnt[a[l]];
                ++l;
            }

            while (cnt[a[r]] <= 1) {
                ans += r-l+1;
                ++r;
                if (r >= n) break;
                cnt[a[r]] += 1;
            }
        }
        cout << ans << '\n';

        // reset
        for (int& i : a)
            cnt[i] = 0;
    }

    return 0;
}