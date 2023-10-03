#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ld d, s, e; cin >> d >> s >> e;

  cout << setprecision(10) << fixed;
  ld ans = s/d;
  if (s <= d-s-e) ans = max(ans, (d-s)/d * s/(d-s-e));
  else ans = max(ans, (s-(d-s-e))/d + (d-s)/d);
  cout << ans << "\n";
  return 0;
}