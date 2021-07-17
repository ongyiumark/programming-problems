/*
    My original DP solution worked, but we can precompute some things before hand.
    Keep track of the power needed (m) and the current index (idx).

    solve(m, idx) = sum from i=0 to i=m (x^i * solve(m-i, idx+1)) 
        where x[idx] is sum of k=A[idx] to k=B[idx] (k^i).
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll MOD = 1e9+7;
const int N = 405;
ll n, c;
ll A[N], B[N];

ll modpow(ll b, ll e){
    ll ans = 1;
    while(e > 0){
        if (e&1) ans = ans*b%MOD;
        e >>= 1;
        b = b*b%MOD;
    }
    return ans;
}

ll dp[N][N];
ll precomp[N][N];

ll solve(int m, int idx) {
    ll& ans = dp[m][idx];
    if (ans != -1) return ans;
    if (idx == n-1) return ans = precomp[m][idx];
    ans = 0;
    for (int i = 0; i <= m; i++){
        ans += precomp[i][idx]*solve(m-i, idx+1);
        ans %= MOD;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> c;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];

    memset(precomp, 0, sizeof precomp);
    for (int i = 0; i <= c; i++){
        for (int j = 0; j < n; j++){
            for (int x = A[j]; x <= B[j]; x++){
                precomp[i][j] += modpow(x, i);
                precomp[i][j] %= MOD;
            }
        }
    }

    memset(dp, -1, sizeof dp);
    ll ans = solve(c, 0);
    cout << ans << endl;
    return 0;
}