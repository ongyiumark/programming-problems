#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;


int main() {
  cin.tie(0)->sync_with_stdio(false);
  ld n, x, y, a, b; cin >> n >> x >> y >> a >> b;
  ld dx = n*a, dy = n*b;
  cout << setprecision(11) << fixed;
  cout << hypotl(dx, dy)/2 << "\n";
}