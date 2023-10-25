#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 250;
int memo[N][N];
int arr[N], pref[N];
const int INF = 1e9;

int solve(int l, int r) {
    int &ans = memo[l][r];
    if (ans != -1) return ans;
    if (r < l) return ans = 0;

    ans = INF;
    for (int i = l; i <= r; i++) {
        int tmp = 0;
        if (i-1 >= 0) tmp += pref[i-1]-pref[l]+arr[l]+solve(l, i-1);
        if (i+1 < n) tmp += pref[r]-pref[i]+solve(i+1, r);
        ans = min(ans, tmp);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n) {
        for (int i = 0; i < n; i++) cin >> arr[i];
        pref[0] = arr[0];
        for (int i = 1; i < n; i++) pref[i] = pref[i-1] + arr[i];
        memset(memo, -1, sizeof memo);
        cout << solve(0, n-1) << "\n";
    }

    return 0;
}