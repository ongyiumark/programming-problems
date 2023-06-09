#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int memo[N][N];
const int INF = 1e9;
int cuts[51];
int n;

int solve(int l, int r) {
    int &ans = memo[l][r];
    if (ans != -1) return ans;

    ans = INF;
    int count = 0;

    for (int j = 0; j < n; j++) {
        int c = cuts[j];
        if (l < c && c < r) {
            ans = min(ans, r-l + solve(l,c) + solve(c,r));
            count += 1;
        }
    }

    if (count == 0) ans = 0;
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int len; cin >> len;
        if (!len) break;

        for (int i = 0; i <= len; i++) {
            for (int j = 0; j <= len; j++) {
                memo[i][j] = -1;
            }
        }
        cin >> n;
        for (int i = 0; i < n; i++) cin >> cuts[i];
        cout << "The minimum cutting is " << solve(0, len) << ".\n";
    }

    return 0;
}