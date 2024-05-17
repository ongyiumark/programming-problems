#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+5;
const int SQN = 400;

typedef long long ll;
vector<ll> a(N);
int dp[N][SQN];
ll n;

int solve(ll p, ll k) {
    if (p > n) return 0;
    if (dp[p][k] != -1) return dp[p][k];
    dp[p][k] = 1+solve(p+a[p]+k, k);
    return dp[p][k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    int q; cin >> q;
    memset(dp, -1, sizeof dp);
    while(q--){
        ll p, k; cin >> p >> k;
        if (k*k > n) {
            ll m = 0;
            while(p <= n) {
                p = p+a[p]+k;
                m++;
            }
            cout << m << endl;
        }
        else cout << solve(p, k) << endl;
    }
} 