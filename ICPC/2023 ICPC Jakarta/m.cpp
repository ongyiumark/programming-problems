#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n; cin >> n;
  ll total = 0;
  ll hi = 0;
  for (int i = 0; i < n; i++) {
    ll x; cin >> x;
    total += x;
    hi = max(hi, x);
  }

  cout << (hi > 2*(total-hi) ? total-hi : total/3) << "\n";

  return 0;
}