#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, k, x, y;
  cin >> n >> k >> x >> y;

  cout << x*min(n,k) + y*max(n-k,0LL) << endl;
  return 0;
}
