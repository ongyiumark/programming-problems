#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector<ld> p;
vector<ll> s;
vector<ld> memo;
vector<bool> saved;
vector<vector<vector<ld>>> probs;

const int N = 205;
const ld EPS = 1e-9;

ld fastpow(ld b, ll e) {
  ld ans = 1;
  while (e > 0) {
    if (e&1) ans *= b;
    b = b*b;
    e >>= 1;
  }
  return ans;
}

// get from x to s with probability p
ld get_prob(int x, int s, ld p) {
  int n = s+s; // normalize 0 to n
  x = x+s;

  // p == 1/2
  if (fabs(2*p-1) < EPS) return (ld)x/n;
  return (1-fastpow((1-p)/p, x))/(1-fastpow((1-p)/p, n));
}

ld solve(int mask) {
  if (saved[mask]) return memo[mask];
  saved[mask] = true;

  int n = p.size();
  int i = __builtin_popcount(mask)-1;
  ld &res = memo[mask];
  res = 0;
  if (mask == 0) return res = 1;

  for (int j = 0; j < n; j++) {
    if (((mask>>j)&1) == 0) continue;
    int pos = (i == 0 ? 0 : s[i-1]);

    ld prob = 0;
    prob += get_prob(pos, s[i], p[j])*solve(mask^(1<<j));
    prob += get_prob(-pos, s[i], p[j])*(1-solve(mask^(1<<j)));
    res = max(res, prob);
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  p.resize(n); s.resize(n);
  for (ld &x : p) cin >> x;
  for (ll &x : s) cin >> x;


  memo.resize(1<<n);
  saved.resize(1<<n);

  cout << setprecision(15) << fixed;
  cout << solve((1<<n)-1) << "\n"; 

  return 0;
}