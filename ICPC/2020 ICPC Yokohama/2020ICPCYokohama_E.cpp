#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9;
const ld PI = acosl(-1);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<ld> x(n);
  ld xmax = 0;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    xmax = max(xmax, x[i]);
  }
  sort(x.rbegin(), x.rend());


  ld lo = xmax/2;
  ld hi = 1e9;

  while(fabs(hi-lo) >= EPS) {
    ld r = (lo+hi)/2;
    
    ld total = 0;
    for (int i = 0; i < n; i++) total += 2*asinl(x[i]/(2*r));
    if (total > 2*PI) lo = r;
    else hi = r;
  }

  ld ctotal = 0;
  for (int i = 0; i < n; i++) ctotal += 2*asinl(x[i]/(2*lo)); 
  cout << setprecision(12) << fixed;
  if (fabs(ctotal-2*PI) < 1e-3) {
    cout << lo << "\n";
    return 0;
  }

  lo = xmax/2;
  hi = 1e9;

  while(fabs(hi-lo) >= EPS) {
    ld r = (lo+hi)/2;
    
    ld total = 0;
    for (int i = 1; i < n; i++) total += 2*asinl(x[i]/(2*r));
    total += 2*PI - 2*asinl(x[0]/(2*r));
    if (total > 2*PI) hi = r;
    else lo = r;
  }
  cout << lo << "\n";

  
  return 0;
}