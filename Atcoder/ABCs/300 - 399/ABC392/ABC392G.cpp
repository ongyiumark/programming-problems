#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
typedef complex<ld> cd;
const int MAXN = 1e6+5; 

void fft(vector<cd> &A, bool invert) {
    int n = A.size();
    for (int i = 1, j=0; i < n; i++) {
        int bit = (n >> 1);
        for (; j&bit; bit >>= 1) j^= bit;
        j ^= bit;
        if (i < j) swap(A[i], A[j]);
    }

    for (int cn = 2; cn <= n; cn <<= 1) {
        ld ang = 2*M_PIl/cn * (invert ? -1 : 1);
        cd wcn(cosl(ang), sinl(ang));
        for (int i = 0; i < n; i += cn) {
            cd w(1);
            for (int j = 0; j < cn/2; j++) {
                cd u = A[i+j], v = A[i+j+cn/2]*w;
                A[i+j] = u+v;
                A[i+j+cn/2] = u-v;
                w *= wcn;
            }
        }
    }
    if (invert) for (cd &x : A) x /= n;
}

vector<ll> square(vector<ll> &p) {
    int n = 1;
    int deg = 2*p.size()-1;
    while (n < deg) n <<= 1;
    vector<cd> A(p.begin(), p.end());
    A.resize(n);
    fft(A, false);
    for (cd &x : A) x = x*x;
    fft(A, true);

    vector<ll> res;
    for (cd &x : A) res.push_back(round(x.real()));
    res.resize(deg);
    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> S(n);
    for (int &x : S) cin >> x;
    vector<ll> p(MAXN);
    for (int &x : S) p[x] = 1;

    vector<ll> sq_p = square(p);
    ll ans = 0;
    for (int &x : S) {
        ans += (sq_p[2*x]-1)/2;
    }
    cout << ans << "\n";

    return 0;
}