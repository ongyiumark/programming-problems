/*
  Used that fact that n%(b-1) == s%(b-1).
  Showed that (n-s)/k = b-1 for some k.
  Tried all factors of n-s.

  Edge case when n == s.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll solve(ll b, ll n){
  if (n == 0) return 0;
  return solve(b, n/b) + n%b;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, s; cin >> n >> s;
  if (n < s) {
    cout << -1 << endl;
    return 0;
  }

  if (n == s){
    cout << n+1 << endl;
    return 0;
  }

  ll to_factor = n-s;

  ll ans = 1e18;
  for (ll i = 1; i*i <= to_factor; i++){
    if (to_factor%i != 0) continue;

    ll a = i + 1; 
    ll b = to_factor/i + 1;

    if (solve(a, n) == s) ans = min(ans, a);
    if (solve(b, n) == s) ans = min(ans, b);
  }

  cout << ((ans == 1e18) ? -1 : ans) << endl;

  return 0;
}
