#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 3005;
ll memo[N][N][2];
bool vis[N][N][2];
ll a[N];

ll solve(int l, int r, int turn) {
    ll &ans = memo[l][r][turn];
    if (vis[l][r][turn]) return ans;
    vis[l][r][turn] = true;

    if (r < l) return ans = 0;
    if (turn == 0) ans = max(a[l]+solve(l+1, r, 1-turn), a[r]+solve(l, r-1, 1-turn));
    else ans = min(solve(l+1, r, 1-turn)-a[l], solve(l, r-1, 1-turn)-a[r]);
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];


    memset(memo, -1, sizeof memo);

    cout << solve(0, n-1, 0) << "\n";
    return 0;
}