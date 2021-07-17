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
const int N = 5005;

struct poly {
    double a,b;

    poly (double a=0, double b=0) : a(a), b(b) {}
    poly operator+(const poly& p) const {
        return poly(a+p.a, b + p.b);
    }
    poly operator-(const poly& p) const {
        return poly(a-p.a, b-p.b);
    }
    poly operator*(const poly& p) const {
        return poly(a*p.a - b*p.b, a*p.b + b*p.a);
    }
};

void fft(poly in[], poly p[], int n, int s){
    if (n < 1) return;
    if (n == 1) {
        p[0] = in[0];
        return;
    }
    n >>= 1;
    fft(in, p, n, s << 1);
    fft(in + s, p+n, n , s << 1);
    poly w(1), wn(cos(M_PI/n), sin(M_PI/n));
    for (int i = 0; i < n; i++){
        poly even = p[i], odd = p[i+n];
        p[i] = even + w * odd;
        p[i+n] = even - w*odd;
        w = w * wn;
    }
}

void fft(poly p[], int n){
    poly *f = new poly[n];
    fft(p,f,n,1);
    copy(f,f+n,p);
    delete[] f;
}

void inverse_fft(poly p[], int n){
    for (int i = 0; i < n; i++) {
        p[i].b *= -1;
    }
    fft(p, n);
    for (int i = 0; i < n; i++) {
        p[i].a/=n;
        p[i].b/= -1*n;
    }
}

int mult(ll a[], int an, ll b[], int bn, ll c[]){
    int n, degree = an + bn - 1;
    for (n = 1; n < degree; n <<= 1){}
    poly *A = new poly[n], *B = new poly[n];
    copy(a, a+an, A); fill(A+an, A+n, 0);
    copy(b, b+bn, B); fill(B+bn, B+n, 0);
    fft(A,n); fft(B,n);
    for (int i = 0; i < n; i++) A[i] = A[i]*B[i];
    inverse_fft(A,n);
    for (int i = 0; i < an; i++){
        c[i] = (ll)(A[i].a+0.5);
    } 
    delete[] A,B; return degree;
}

string s;
int n, m;

ll cat[N];

ll modpow(ll b, ll e){
    ll ans = 1;
    while(e > 0){
        ans = b * ans %MOD;
        e >>= 1;
        b = b*b % MOD;
    }
    return ans;
}

ll solve(int b){
    int moves = n - b - m;
    if (moves < 0 || moves%2 == 1) return 0;
    if (moves == 0) return 1;

    int M = moves/2;
    int p = b+m+1;


    ll c[M+1];
    copy(cat, cat+M+1, c);
    for (int i = 1; i < p; i++){
        mult(c, M+1, cat, M+1, c);
        for (int j = 0; j <= M; j++) c[j] %= MOD;
    }

    ll ans = (c[M]*modpow(2,M))%MOD;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //compute catalan numbers
    cat[0] = 1;
    cat[1] = 1;
    for (int i = 2; i < N; i++){
        for (int j = 0; j < i; j++){
            cat[i] += cat[j]*cat[i-j-1]%MOD;
            cat[i] %= MOD;
        }
    }

    cin >> n >> s;
    m = s.size();

    ll ans = 0;
    for (int b = 0; b <= n; b++){
        //cout << b << " " << solve(b) << endl;
        ans += solve(b);
        ans %= MOD;
    }
    
    cout << ans << endl;

    return 0;
}