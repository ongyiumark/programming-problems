/*
  Decide by fixing the number of digits of l and the number of digits of y.
  This transforms the problem into counting
    how many (x,y) such that ax + by = S.

  Because of the size of S, if a >= 8, then b <= a+1.
  So we can brute force (a,b) <= 8.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll MOD = 1e9+7;
ll cnts[10];

ll modpow(ll b, ll e) {
  ll ans = 1;
  while (e > 0) {
    if (e&1) ans = ans*b%MOD;
    b = b*b%MOD;
    e >>= 1;
  }
  return ans;
}

ll solve(ll a, ll b, ll S) {
  ll maxA = cnts[a];
  ll maxB = cnts[b];

  // Count how many integers (x,y) such that 
  // 0 < x <= maxA and 0 < y <= maxB 
  // where ax + by = S
  
  // a <= S-by <= a*maxA 

  if (S-b*maxB > a*maxA) return 0;
  if (S-b < a) return 0;


  // Find lower bound of y.
  ll lo = 1;
  ll hi = maxB;
  ll ylo = -1;
  while (lo <= hi) {
    ll mid = hi - (hi-lo)/2;
    if (S-b*mid <= a*maxA) {
      ylo = mid;
      hi = mid-1;
    }
    else lo = mid+1;
  }

  // Find upper bound of y
  lo = 1;
  hi = maxB;
  ll yup = -1;
  while (lo <= hi) {
    ll mid = hi - (hi-lo)/2;
    if (S-b*mid >= a) {
      yup = mid;
      lo = mid+1;
    }
    else hi = mid-1;
  }

  // We know ylo <= y <= yup and
  // S-by = 0 (mod a)
  // S = by (mod a)

  ll ans = 0;
  for (int y = 0; y < a; y++) {
    if (S%a != b*y%a) continue;
    ll m = y;
    if (m != 0) m = a-m;
    ans += (yup+m)/a - (ylo+m-1)/a;
    ans %= MOD;
  }

  return ans; 
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll S; cin >> S;
  ll ans = 0;

  // How many numbers with this many digits.
  cnts[0] = 1; cnts[1] = 9;
  for (int i = 2; i < 10; i++) {
    cnts[i] = cnts[i-1]*10;
  }

  // Brute force 1 to 8 digits.
  for (int l = 1; l <= 7; l++) {
    // Only l digits.
    if (S%l == 0 && S/l <= cnts[l]) {
      ans += cnts[l]-S/l+1;
      ans %= MOD;
    }

    for (int r = l+1; r <= 8; r++) {
      // l to r digits
      ll tS = S;
      for (int i = l+1; i < r; i++) tS -= cnts[i]*i;
      if (tS <= 0) continue;  
      ans += solve(l,r,tS);
      ans %= MOD;
    }
  }

  for (int l = 1; l*l <= S; l++) {
    // Only l digits.
    // Must be divide S.
    if (S%l != 0) continue;
    if (l >= 8) ans += (9*modpow(10, l-1)-S/l+1)%MOD;
    if (l*l != S && S/l >= 8) ans += (9*modpow(10, S/l-1)-l+1)%MOD;
    ans %= MOD;
  }

  for (int l = 8; 2*l+1 <= S; l++) {
    // l to l+1 digits.
    ll ylo = 1;
    ll yup = (S-l)/(l+1);
    ll m = S%l;
    if (m != 0) m = l-m;

    ans += (yup+m)/l - (ylo+m-1)/l; 
    ans %= MOD;
  }
  
  if (ans < 0) ans += MOD;
  cout << ans << endl;
  return 0;
}
