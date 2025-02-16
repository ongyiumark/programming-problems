#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1'000'000 + 5;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k; cin >> n >> k;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> freq(MAXN);
    for (int &x : a) freq[x] += 1;

    vector<int> div_count(MAXN);
    for (int d = 1; d < MAXN; d++) {
        for (int j = d; j < MAXN; j+=d) {
            div_count[d] += freq[j];
        }
    }

    vector<int> ans(MAXN);
    for (int d = 1; d < MAXN; d++) {
        if (div_count[d] < k) continue;
        for (int j = d; j < MAXN; j += d) {
            ans[j] = max(ans[j], d);
        }
    }

    for (int &x : a) {
        cout << ans[x] << "\n";
    }
    return 0;
}