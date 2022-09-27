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

ll gcd(ll a, ll b) {
  if (b==0) return a;
  else return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
  return a/gcd(a,b)*b;
}

struct frac {
  ll a, b; 
  frac() : a(0), b(1) {}
  frac(ll _a, ll _b) : a(_a), b(_b) {}

  void reduce() {
    if (b < 0) b = -b, a = -a;
    ll g = gcd(abs(a), abs(b));
    a/=g; b/=g;
  }

  frac operator+(const frac &other) const {
    ll L = lcm(b, other.b);
    frac res(L/b*a + L/other.b*other.a, L);
    res.reduce();
    return res;
  }

  frac operator-(const frac &other) const {
    ll L = lcm(b, other.b);
    frac res(L/b*a - L/other.b*other.a, L);
    res.reduce();
    return res;
  }

  frac operator*(const frac &other) const {
    frac res(a*other.a, b*other.b);
    res.reduce();
    return res;
  }

  frac operator/(const frac &other) const {
    frac res(a*other.b, b*other.a);
    res.reduce();
    return res;
  }

  bool operator==(const frac &other) const {
    return a==other.a && b == other.b;
  } 
};

ostream& operator<<(ostream& os, const frac& f) {
  os << f.a << "/" << f.b;
  return os;
}

int m,n,p;
const frac ZERO = frac(0, 1);
const frac ONE = frac(1, 1);

const int N = 35;
frac memo[N][N];

frac solve(int x, int y) {
  if (!(memo[x][y] == frac(-1,1))) return memo[x][y];
  if (y > p || x > n) return ZERO;
  if (y == p && x == n) return ONE;
  else if (y == p) return ZERO;
  else if (x == n) return ZERO;

  return memo[x][y] = frac(2*(n-x), m-y)*solve(x+1, y+1) + (frac(1,1) - frac(2*(n-x), m-y))*solve(x,y+1);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> m >> n >> p;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      memo[i][j] = frac(-1,1);
    } 
  }
  
  cout << solve(0,0) << endl;
  return 0;
}
