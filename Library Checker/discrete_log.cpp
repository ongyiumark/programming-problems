#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

ll mod_log(ll a, ll b, ll m) {
  a %= m; b %= m;
  // preprocess coprime
  ll k = 1, add = 0, g;
  while ((g = gcd(a, m)) > 1) {
    if (b == k) return add;
    if (b % g) return -1;
    b /= g, m /= g, add++;
    k = k*a/g % m;
  }
  ll n = sqrtl(m)+1;
  
  // solve k a^x = b (mod m)
  ll an = 1;
  for (int i = 0; i < n; i++) an = an*a % m;
  
  unordered_map<ll,int> vals;
  for (int q = 0, cur = b; q <= n; q++) 
    vals[cur] = q, cur = cur*a%m;
  
  for (int p = 1, cur = k; p <= n; p++) {
    cur = cur*an%m;
    if (vals.count(cur)) {
      ll ans = n*p-vals[cur] + add;
      return ans;
    }
  }
  return -1;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int t; cin >> t;
  while (t--) {
    ll x, y, m; cin >> x >> y >> m;
    cout << mod_log(x, y, m) << "\n";
  }

  return 0;
}