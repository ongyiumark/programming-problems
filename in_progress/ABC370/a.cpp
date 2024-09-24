#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int l, r; cin >> l >> r;
  if (l+r == 1) cout << (l == 1 ? "Yes\n" : "No\n");
  else cout << "Invalid\n";
  return 0;
}