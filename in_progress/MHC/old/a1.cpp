#include <bits/stdc++.h>
using namespace std;

void testcase() {
  int s, d; cin >> s >> d;
  int k; cin >> k;

  int required_buns = k+1;
  int required_patty = k;

  int buns = (s+d)*2;
  int patty = s + 2*d;

  if (required_buns <= buns && required_patty <= patty) {
    cout << "YES\n";
  }
  else cout << "NO\n";
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