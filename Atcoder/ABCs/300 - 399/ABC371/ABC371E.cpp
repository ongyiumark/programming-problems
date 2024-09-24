#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n; cin >> n;
  vector<int> seen(n, -1);

  ll ans = 0;
  ll adder = 0;
  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    a--;

    int last_i = seen[a];
    ans = ans + adder + (i-last_i);
    adder = adder + (i-last_i);
    seen[a] = i;
  }
  cout << ans << "\n";

  return 0;
}