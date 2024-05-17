#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(int n) {
  int nbits = 0;
  int tmp = n;
  while(tmp > 0) nbits++, tmp /= 2;

  int LG = nbits+1;
  vector memo(LG, vector(2, vector(2, vector(2, vector(2, vector(2, -1LL))))));
  function<ll(int,bool,bool,bool,bool,bool)> solver = [&](int i, bool aless, bool bless, bool xorless, bool azero, bool bzero) -> ll {
    if (i == LG) return (azero && bzero);
    ll &ans = memo[i][aless][bless][xorless][azero][bzero];
    if (ans != -1) return ans;
    
    ans = 0;
    int nbit = (n>>(LG-i-1))&1;
    for (int mask = 0; mask < (1<<2); mask++) {
      int abit = (mask>>0)&1;
      int bbit = (mask>>1)&1;
      int xorbit = (abit^bbit);

      if (!xorless && xorbit > nbit) continue;
      if (!aless && abit > xorbit) continue;
      if (!bless && bbit > xorbit) continue;

      ans += solver(i+1, (abit<xorbit)|aless, (bbit<xorbit)|bless, (xorbit<nbit)|xorless, abit|azero, bbit|bzero);
    }
    return ans;
  };

  return solver(0, 0, 0, 0, 0, 0);
}

ll solve2(int n) {
  int nbits = 0;
  int tmp = n;
  while(tmp > 0) nbits++, tmp /= 2;

  int LG = nbits+1;
  vector memo(LG+1, vector(2, vector(2, 0LL)));
  for (int state = 0; state < (1<<2); state++) {
    memo[LG][(state>>0)&1][(state>>1)&1] = 1;
  }
  for (int i = LG-1; i >= 0; i--) {
    for (int state = 0; state < (1<<2); state++) {
      int aless = (state>>0)&1;
      int bless = (state>>1)&1;

      ll &ans = memo[i][aless][bless];
      int nbit = (n>>(LG-i-1))&1;
      int mbit = ((n-1)>>(LG-i-1))&1;
      for (int mask = 0; mask < (1<<2); mask++) {
        int abit = (mask>>0)&1;
        int bbit = (mask>>1)&1;
        int xorbit = (abit^bbit);

        if (xorbit != nbit) continue;
        if (!aless && abit > mbit) continue;
        if (!bless && bbit > mbit) continue;

        ans += memo[i+1][(abit<mbit)|aless][(bbit<mbit)|bless];
      }
    }
  }
  return memo[0][0][0];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m; cin >> n >> m;
  vector<int> s(m);
  for (int &x : s) cin >> x;
  sort(s.begin(), s.end());


  ll ans = solve(n);
  for (int i = 0; i < m; i++) {
    if (s[i] > n) break;
    if (i > 0 && s[i] == s[i-1]) continue;
    ans -= solve2(s[i]);
  }
  cout << ans << "\n";
  return 0;
}