#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MAXP = 1e7+5;
int main() {
    vector<ll> primes;
    vector<bool> isComposite(MAXP, false);
    for (int i = 2; i < MAXP; i++) {
        if (!isComposite[i]) primes.emplace_back(i);
        for (int j = 0; j < (int)primes.size() && i*primes[j] < MAXP; j++) {
            isComposite[i*primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }

    ll L, R; cin >> L >> R;
    // count the number of prime powers in [L+1, R]
    vector<bool> isPrimePower(R-L+1, true);
    for (int j = 0; j < (int)primes.size(); j++) {
        // smallest multiple of `primes[j]` that is at least `L+1`
        ll start = (L+1 + primes[j]-1)/primes[j];

        // mark all composite numbers
        for (ll i = start; i*primes[j] <= R; i++) {
            isPrimePower[i*primes[j]-L] = false;
        }

        // unmark prime powers
        for (ll p = primes[j]; p <= R; p *= primes[j]) {
            if (p < L) continue;
            isPrimePower[p-L] = true;
        }
    }

    int cnt = 0;
    for (int i = 1; i < (R-L+1); i++) cnt += isPrimePower[i];

    cout << cnt+1 << "\n";

    return 0;
}