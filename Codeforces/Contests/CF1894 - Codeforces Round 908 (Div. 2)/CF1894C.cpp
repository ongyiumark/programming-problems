#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    int pointer = n-1;

    bool cycle = 0;
    vector<bool> vis(n);
    int cnt = 0;
    while (true) {

      if (b[pointer] > n) break;
      vis[pointer] = 1;
      pointer = (pointer-b[pointer])%n;
      if (pointer < 0) pointer += n;

      if (vis[pointer]) {
        cycle = 1; break;
      }
      cnt++;
    }
    if (cycle) cout << "Yes\n";
    else if (cnt >= k) cout << "Yes\n";
    else cout << "No\n";
  }

  return 0;
}