#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    
    vector<tuple<int, int, int>> queries(q);
    for (int i = 0; i < q; i++) {
        int r, x; cin >> r >> x;
        r--;
        queries[i] = {r, x, i};
    }

    sort(queries.begin(), queries.end());

    vector<int> ans(q);
    vector<int> dp(n, INT_MAX);
    int step = 0;
    for (int i = 0; i < q; i++) {
        auto [r, x, j] = queries[i];

        // step dp until r
        for (; step <= r; step++) {
            int lo = 0, hi = n-1;
            int idx = n-1;
            while (lo <= hi) {
                int mid = hi - (hi-lo)/2;
                if (dp[mid] >= a[step]) {
                    idx = mid;
                    hi = mid-1;
                }
                else lo = mid+1;
            }
            dp[idx] = a[step];
        }

        int lo = 0, hi = n-1;
        while (lo <= hi) {
            int mid = hi - (hi-lo)/2;
            if (dp[mid] <= x) {
                ans[j] = mid+1;
                lo = mid+1;
            }
            else hi = mid-1;
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }

    
    return 0;
}