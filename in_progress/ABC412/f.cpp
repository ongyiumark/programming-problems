#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll MOD = 998244353;
ll modpow(ll b, ll e) {
    ll ans = 1;
    while (e > 0) {
        if (e&1) ans = ans*b%MOD;
        b = b*b%MOD;
        e >>= 1;
    }
    return ans;
}

ll inv(ll x) {
    return modpow(x, MOD-2);
}

int main() {
    int n, c; cin >> n >> c;
    vector<ll> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    A[c-1]++;

    vector<pair<int,int>> B(n);
    for (int i = 0; i < n; i++) {
        B[i] = {A[i], i};
    }
    sort(B.begin(), B.end(), greater<pair<int,int>>());

    ll S = 0;
    for (int i = 0; i < n; i++) S += A[i];
    S--;

    vector<ll> dp(n);
    ll rhs = S;
    ll lhs = S;

    for (int i = 1; i < n; i++) {
        lhs -= B[i].first;
    }
    dp[0] = rhs*inv(lhs)%MOD;

    for (int i = 1; i < n; i++) {
        rhs = (rhs + dp[i-1]*B[i-1].first)%MOD;
        lhs = (lhs + B[i].first)%MOD;
        dp[i] = rhs*inv(lhs)%MOD;
    }

    ll result = 0;
    for (int i = 0; i < n; i++) {
        if (B[i].second == c-1) result = dp[i];
    }
    cout << result << "\n";

    return 0;
}