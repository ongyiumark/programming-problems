#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5+5;
ll A[N];
ll phi[N];
bool is_composite[N];
vector<int> primes;

void sieve() {
    memset(is_composite, false, sizeof is_composite);
    phi[0] = phi[1] = 0;
    for (int i = 2; i < N; i++){
        if (!is_composite[i]) {
            primes.push_back(i);
            phi[i] = i-1;
        }
        for (int j = 0; j < primes.size() && i*primes[j] < N; j++){
            is_composite[i*primes[j]] = true;
            if (i % primes[j] == 0) {
                phi[i*primes[j]] = phi[i]*primes[j];
                break;
            }
            else {
                phi[i*primes[j]] = phi[i]*phi[primes[j]];
            }
        }

    }
}

ll modpow(ll b, ll e, ll mod){
    ll ans = 1;
    while(e > 0) {
        if (e&1) ans = (ans*b)%mod;
        e >>= 1;
        b = (b*b)%mod;
    }
    return ans;
}

ll modinv(ll x, ll mod) {
    return modpow(x, phi[mod]-1, mod);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    sieve();
    int b; int l; cin >> b >> l;
    for (int i = 0; i < l; i++){
        cin >> A[i];
    }

    ll r = 0;
    for (int i = 0; i < l; i++){
        if (i > 0) r = (r*b)%(b+1);
        r += A[i];
        r %= (b+1);
    }
    if (r == 0) {
        cout << 0 << " " << 0 << "\n";
        return 0;
    }

    for (int i = 0; i < l; i++){
        ll binv = modinv(b, b+1);
        binv = modpow(binv, l-i-1, b+1);
        ll a = r*binv%(b+1);
        if (a <= A[i]) {
            cout << i+1 << " " << A[i]-a << "\n";
            return 0;
        }
    }

    cout << -1 << " " << -1 << "\n";
    return 0;
}