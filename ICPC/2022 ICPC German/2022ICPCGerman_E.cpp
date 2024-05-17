#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // (a,b), (c,d)
  // ((a+b)/2, (b+d)/2)
  int n; cin >> n;
  ld a, b, c, d;
  a = 100, b = 0, c = 0, d = 100;
  cout << setprecision(11) << fixed; 

  if (n == 1) {
    cout << 100.0 << " " << 0.0 << "\n";
    return 0;
  }
  if (n == 2) {
    cout << 0.0 << " " << 100.0 << "\n";
    return 0;
  }
  for (int i = 2; i < min(n, 10000); i++) {
    ld na = (a+c)/2;
    ld nb = (b+d)/2;
    
    a = c, b = d, c = na, d = nb;
  }
  cout << c << " " << d << "\n";
  

  return 0;
}