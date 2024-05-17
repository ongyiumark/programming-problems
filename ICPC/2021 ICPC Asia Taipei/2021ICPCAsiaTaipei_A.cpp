#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) {
    int x, y, n; cin >> x >> y >> n;
    int ans = 0;
    while (ans + ans/x*y < n) ans++;
    cout << ans*3 << "\n";
  }
  
  return 0;
}