#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<pair<ll,ll>> factorize(ll n) {
  vector<pair<ll,ll>> res;
  for (ll i = 2; i*i <=  n; i++) {
    if (n%i == 0) {
      ll mult = 0;
      do { n /= i, mult += 1; } while(n%i == 0);
      res.emplace_back(i, mult);
    }
  }
  if (n > 1) res.emplace_back(n, 1);
  sort(res.begin(), res.end());
  return res;
}


int main() {
  cin.tie(0)->sync_with_stdio(false);

  int q; cin >> q;
  while(q--) {
    ll n; cin >> n;
    auto facts = factorize(n);
    ll total = 0;
    for (auto &[p, mult] : facts) total += mult;
    cout << total;
    for (auto &[p, mult] : facts) {
      for (int i = 0; i < mult; i++) cout << " " << p;
    }
    cout << "\n";
  }

  return 0;
}