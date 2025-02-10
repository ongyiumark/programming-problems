#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = (119<<23)+1;
const ll primitive_root = 3;

ll mod_pow(ll b, ll e, ll m) {
    ll ans = 1;
    while (e > 0) {
        if (e&1) ans = ans*b%m;
        b = b*b%m;
        e >>= 1;
    }
    return ans;
}

template<ll P, ll g>
void ntt(vector<ll> &A, bool invert) {
    int n = A.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = (n>>1);
        for (; j&bit; bit>>=1) j ^= bit;
        j ^= bit;
        if (i < j) swap(A[i], A[j]);
    }

    ll w0 = mod_pow(g, (P-1)/n, P);
    ll w0_inv = mod_pow(w0, P-2, P);
    for (int cn = 2; cn <= n; cn <<= 1) {
        ll wcn = (invert ? w0_inv : w0);
        for (int i = cn; i < n; i <<= 1)
            wcn = wcn*wcn%P;
        for (int i = 0; i < n; i += cn) {
            ll w = 1;
            for (int j = 0; j < cn/2; j++) {
                ll u = A[i+j]%P, v = A[i+j+cn/2]*w%P;
                A[i+j] = u+v < P ? u+v : u+v-P;
                A[i+j+cn/2] = u-v >= 0 ? u-v : u-v+P;
                w = w*wcn%P;
            }
        }
    }
    if (invert) {
        ll n_inv = mod_pow(n, P-2, P);
        for (ll &x : A) x = (x*n_inv)%P;
    }
}


template<ll P, ll g>
vector<ll> multiply(vector<ll> &p1, vector<ll> &p2) {
    int n = 1;
    int deg = p1.size() + p2.size() - 1;
    while (n < deg) n <<= 1;
    vector<ll> A(p1.begin(), p1.end());
    vector<ll> B(p2.begin(), p2.end());
    A.resize(n); B.resize(n);

    ntt<P, g>(A, false); ntt<P, g>(B, false);
    vector<ll> C(n);
    for (int k = 0; k < n; k++) C[k] = A[k]*B[k]%P;
    ntt<P, g>(C, true);

    C.resize(deg);
    return C;
}

const int MAXN = 2e5+5;
vector<ll> fact(MAXN), ifact(MAXN);

ll perm(ll n, ll k) {
    return fact[n]*ifact[n-k]%MOD;
}

ll comb(ll n, ll k) {
    return perm(n, k)*ifact[k]%MOD;
}

vector<ll> divide(vector<ll> p, ll a) {
    // divide by p(x) by ax + 1
    int n = p.size();
    ll a_inv = mod_pow(a, MOD-2, MOD);
    for (int i = n-1; i >= 1; i--) {
        ll b = p[i]*a_inv%MOD;
        p[i-1] = p[i-1] >= b ? p[i-1]-b : p[i-1]-b+MOD;
        p[i] = b;
    }
    for (int i = 0; i < n-1; i++) p[i] = p[i+1];
    p.resize(n-1);
    return p;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n; cin >> n;

    vector<ll> counts;
    ll x = 1;
    while (x <= n) {
        counts.push_back(min(10*x, n+1)-x);
        x *= 10;
    }
        
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = i*fact[i-1]%MOD;
    ifact[MAXN-1] = mod_pow(fact[MAXN-1], MOD-2, MOD);
    for (int i = MAXN-2; i >= 0; i--) ifact[i] = ifact[i+1]*(i+1)%MOD;

    int num_polys = counts.size();
    vector<vector<ll>> polys(num_polys, vector<ll>());
    priority_queue<pair<ll, int>> pq;
    for (int k = 0; k < num_polys; k++) {
        polys[k].resize(counts[k]+1);
        for (int i = 0; i <= counts[k]; i++) {
            polys[k][i] = comb(counts[k], i)*mod_pow(10, (k+1)*i, MOD)%MOD;
        }
        pq.push({-counts[k], k});
    }

    for (int t = 0; t < num_polys-1; t++) {
        int i = pq.top().second; pq.pop();
        int j = pq.top().second; pq.pop();

        int idx = min(i, j);
        polys[idx] = multiply<MOD, primitive_root>(polys[i], polys[j]);
        pq.push({-polys[idx].size(), idx});
    }
    vector<ll> result_poly = polys[0];

    ll res = 0;
    for (int k = 0; k < num_polys; k++) {
        ll start = mod_pow(10, k, MOD);
        polys[k] = divide(result_poly, 10*start);

        ll total_m = 0;
        for (ll m = start; m < min(10*start, n+1); m++) total_m = (total_m + m)%MOD;
        
        ll X = 0;
        for (int si = 0; si < n; si++) {
            ll to_add = polys[k][si]*fact[si]%MOD;
            to_add = to_add*fact[n-1-si]%MOD;
            X = (X + to_add)%MOD;
        }
        
        res += X*total_m%MOD;
        res %= MOD;
    }
    
    cout << res << "\n";
    return 0;
}