#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void testcase() {
  ll r, c, a, b;
  cin >> r >> c >> a >> b;
  if (r > c) cout << "YES\n";
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