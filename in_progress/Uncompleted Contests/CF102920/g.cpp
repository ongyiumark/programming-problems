#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ll n, d, bots[1000000];
ll diff1, diff2;
 
ld solve() {
  diff1 = 0;
  for (ll i = 0; i < n; ++i)
    diff1 = max(diff1, abs((bots[i] - (bots[0]+d*i))));
 
  diff2 = 0;
  for (ll i = 0; i < n; ++i)
    diff2 = max(diff2, abs((bots[i] - (bots[0]-d*i))));
  
  return (ld)min(diff1,diff2)/2;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    cin >> n >> d;
    for (ll i = 0; i < n; ++i)
        cin >> bots[i];
 
    cout << fixed << setprecision(1) << solve() << '\n';
    return 0;
}