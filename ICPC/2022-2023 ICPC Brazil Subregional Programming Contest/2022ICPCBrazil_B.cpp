#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int LG = 32;
const ll MOD = 1e9+7;

ll modpow(ll b, ll e) {
  ll ans = 1;
  while (e > 0) {
    if (e&1) ans = ans*b%MOD;
    b = b*b%MOD;
    e >>= 1;
  }
  return ans;
}

ll modinv(ll x) {
  return modpow(x, MOD-2);
}

ll dp[LG+1][2][2][2];
ll solve_helper(int bit, int fa, int fb, int fc, ll A, ll B, ll C) {
  if (bit == -1) return 1;
  ll &ans = dp[bit][fa][fb][fc];
  if (ans != -1) return ans;

  int bit_A = (A>>bit)&1;
  int bit_B = (B>>bit)&1;
  int bit_C = (C>>bit)&1;

  ans = 0;
  for (int mask = 0; mask < (1<<3); mask++) {
    int curr_a = (mask)&1;
    int curr_b = (mask>>1)&1;
    int curr_c = (mask>>2)&1;

    if (curr_a > bit_A && !fa) continue;
    if (curr_b > bit_B && !fb) continue;
    if (curr_c > bit_C && !fc) continue;

    if ((curr_a^curr_b^curr_c) != 0) continue;

    ans += solve_helper(bit-1, fa|(curr_a < bit_A), fb|(curr_b < bit_B), fc|(curr_c < bit_C), A, B, C);
    ans %= MOD;
  }

  return ans;
}

ll solve(ll A, ll B, ll C) {
  memset(dp, -1, sizeof dp);
  return solve_helper(LG, 0, 0, 0, A, B, C);
}

ll brute(ll l1, ll r1, ll l2, ll r2, ll l3, ll r3) {
  ll ans = 0;
  for (int a = l1; a <= r1; a++) {
    for (int b = l2; b <= r2; b++) {
      for (int c = l3; c <= r3; c++) {
        ans += ((a^b^c) == 0);
      }
    }
  }
  return ans;
}

ll smart(ll l1, ll r1, ll l2, ll r2, ll l3, ll r3) {
  return solve(r1, r2, r3) 
          - solve(l1-1, r2, r3) - solve(r1, l2-1, r3) - solve(r1, r2, l3-1) 
          + solve(r1, l2-1, l3-1) + solve(l1-1, r2, l3-1) + solve(l1-1, l2-1, r3)
          - solve(l1-1, l2-1, l3-1); 
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);  

  ll l1, r1, l2, r2, l3, r3; cin >> l1 >> r1 >> l2 >> r2 >> l3 >> r3;
  ll den = (r1-l1+1)*(r2-l2+1)%MOD*(r3-l3+1)%MOD;

  ll num = den-smart(l1, r1, l2, r2, l3, r3); 
  num %= MOD;
  if (num < 0) num += MOD;
  
  cout << num * modinv(den) %MOD << "\n";

  return 0;
}