#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

void testcase() {
  ll n, S, p; cin >> n >> S >> p;
  for (int i = 0; i < S; i++) {
    int x; cin >> x;
  }

  ll ans = 2*p-S + (n-1-p)*(3*p-S+n-2) + S*(S-1) + (p-S)*(p-S-1)*2 + S*(p-S)*3;
  ans *= 2;
  cout << ans << "\n";
  
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;
  while(t--) testcase();
  return 0;
}