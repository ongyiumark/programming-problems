#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll query(ll t) {
  cout << "? " << t << endl;
  ll d; cin >> d;
  return d;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll pow2 = 2;
  while (true) {
    ll t = pow2-1;
    ll d = query(t);
    if (d < t) {
      cout << "! " << t-d << endl; 
      break;
    } 

    pow2 *= 2;
  }

  return 0;
}