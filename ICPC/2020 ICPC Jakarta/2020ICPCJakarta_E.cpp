#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;
  vector<int> bit(n-1);
  for (int &x : bit) cin >> x;
  vector<int> d(n);


  int ans = 0;
  for (int i = 0; i < n-1; i++) {
    if (bit[i] == 1) d[i+1] = 1;
    else d[i+1] = d[i]+1;

    ans = max(ans, d[i+1]);
    if (bit[i] == 1) ans = min(ans, 2);
  }

  cout << ans << "\n";

  return 0; 
}