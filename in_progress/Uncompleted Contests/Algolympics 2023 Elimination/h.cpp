#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
  return a/gcd(a,b)*b;
}

ll fastpow(ll b, ll e) {
  ll ans = 1;
  while (e > 0) {
    if (e&1) ans *= b;
    b *= b;
    e >>= 1;
  }
  return ans;
}

struct frac {
  ll n, d;

  void simplify() {
    ll g = gcd(n, d);
    n /= g; d /= g;
  }

  frac operator + (const frac & other) const {
    ll l = lcm(d, other.d);
    frac res = {l/d*n + l/other.d*other.n, l};
    
    res.simplify();
    return res;
  }

  frac operator * (const frac & other) const {
    frac res = {n*other.n, d*other.d};

    res.simplify();
    return res;
  }

  friend ostream& operator<<(ostream &os, const frac &other) {
    os << other.n << "/" << other.d;
    return os;
  }
};


ll n, m, x;
const int N = 7;
ll a[N], h[N];

map<array<int,8>, int> memo;

int solve(array<int,7> currh, int m) {
  //if (memo.find(params) != memo.end()) return memo[params];
  
  int den = 0;
  for (int i = 0; i < n; i++) {
    if (currh[i] > 0) {
      den++;
    }
  }

  if (total_attack <= x) return ans = frac({1,1});
  else if (lo > m) return ans = frac({0,1});
  
  for (int i = 0; i < n; i++) {
    if (currh[i] > 0 & curr[i] <= m) {
      int tmp = currh[i];
      currh[i] -= tmp;
      ans = ans + frac({m-tmp, fastpow(den, tmp)})*solve(currh, m-tmp);
      currh[i] += tmp;
    }
  }
  return ans;
}


void testcase() {
  memo.clear();
  cin >> n >> m >> x;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> h[i];

  array<int,7> currh;
  for (int i = 0; i < n; i++) currh[i] = h[i];

  solve(currh, m);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--) testcase();
  return 0;
}