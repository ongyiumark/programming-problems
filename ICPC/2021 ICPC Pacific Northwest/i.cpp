#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector<ld> p;
vector<ll> s;
vector<vector<ld>> memo;
vector<vector<bool>> saved;
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
  int x = x+s;

  // p == 1/2
  if (fabs(2*p-1) < EPS) return (ld)x/n;
  return (1-fastpow((1-p)/p, x))/(1-fastpow((1-p)/p, n))
}

ld solve(int i, int mask) {
  if (saved[i][mask]) return memo[i][mask];
  saved[i][mask] = true;

  int n = p.size();
  ld &res = memo[i][mask];
  res = 0;
  for (int j = 0; j < n; j++) {
    if (((mask>>j)&1) == 0) continue;
    ld currprob = (i == 0 ? 1 : solve(i-1, mask^(1<<j)));
    ld nextprob = get_prob((i == 0 ? 0 : s[i-1]), s[i], p[j]);
    res = max(res, currprob*nextprob);
  }
  return s;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  p.resize(n); s.resize(n);
  for (ld &x : p) cin >> x;
  for (ll &x : s) cin >> x;


  memo.resize(n, vector<ld>((1<<n)));
  saved.resize(n, vector<bool>((1<<n)));

  cout << setprecision(15) << fixed;
  cout << solve(n-1, (1<<n)-1) << "\n"; 

  return 0;
}