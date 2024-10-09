#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void testcase() {
  ll a,b,c; cin >> a >> b >> c;
  ll best_k = max(0LL, c/b*2-1);
  if (c < a) {
    cout << best_k << "\n";
    return;
  }

  c -= a;
  ll x = 1;
  ll y = 0;
  if (2*a < b) {
    ll add_x = c/a;
    x += add_x;
    c -= add_x*a;
    
    ll add_y = c/b;
    y += add_y;
  }
  else {
    ll add_y = c/b;
    y += add_y;
    c -= add_y*b;

    ll add_x = c/a;
    x += add_x;
  }

  best_k = max(best_k, x+2*y);
  cout << best_k << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int t; cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    cout << "Case #" << tt << ": ";
    testcase();
  }
  return 0;
}