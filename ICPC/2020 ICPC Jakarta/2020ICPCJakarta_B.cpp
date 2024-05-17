#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 235813;
ll modpow(ll b, ll e) {
  ll ans = 1;
  while (e > 0) {
    if (e&1) ans = ans*b%MOD;
    b = b*b %MOD;
    e >>= 1;
  }
  return ans;
}

ll inv(ll x) {
  return modpow(x, MOD-2);
}

vector<ll> fact, ifact;
ll perm(ll n, ll k) {
  return fact[n]*ifact[n-k]%MOD;
}
ll comb(ll n, ll k) {
  return perm(n,k)*ifact[k]%MOD;
}

const ll BOUND = 100000;
bool inside(ll x) {
  return (x <= BOUND || x >= MOD-BOUND);
}

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n; cin >> n;
  fact.assign(n, 1);
  ifact.assign(n, 1);
  for (int i = 1; i < n; i++) fact[i] = i*fact[i-1]%MOD;
  ifact[n-1] = inv(fact[n-1]);
  for (int i = n-2; i >= 0; i--) ifact[i] = (i+1)*ifact[i+1]%MOD;

  vector<ll> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    A[i] %= MOD;
    if (A[i] < 0) A[i] += MOD;
  }

  vector<ll> coef(n);
  for (int i = 0; i < n; i++) {
    coef[i] = comb(n-1, i);
    if (i&1) coef[i] *= -1;

    coef[i] %= MOD;
    if (coef[i] < 0) coef[i] += MOD;
  }

  ll current = 0;
  for (int i = 0; i < n; i++) {
    current += coef[i]*A[i]%MOD;
    current %= MOD;
  }

  int count = 0;
  for (int i = 0; i < n; i++) {
    current -= coef[i]*A[i];
    ll tmp = -current*inv(coef[i])%MOD;

    if (tmp < 0) tmp += MOD;

    count += (inside(tmp) && tmp != A[i]);

    current += coef[i]*A[i];
  }
  cout << count << "\n";

  return 0;
}