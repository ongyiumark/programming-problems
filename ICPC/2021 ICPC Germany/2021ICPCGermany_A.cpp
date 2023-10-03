#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll NMAX = 1e18;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n; cin >> n;
  unordered_set<ll> powers;
  for (ll i = 1; i <= NMAX; i *= 2) powers.insert(i);
  powers.insert(0);

  for (ll p : powers) {
    if (p >= n) continue;
    if (powers.find(n-p-1) != powers.end()) {
      cout << p+1 << "\n";
      return 0;
    }
  }
  cout << "impossible\n";
  
  return 0;
}