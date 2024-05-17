#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod_pow(ll b, ll e, ll m) {
  ll ans = 1; b %= m; 
  while (e > 0) {
    if (e&1) ans = ans*b%m;
    b = b*b%m;
    e >>= 1; 
  }
  return ans;
}
ll mod_log(ll a, ll b, ll m) {
  a %= m; b %= m;
  ll n = sqrtl(m)+1;
  
  ll an = 1;
  for (int i = 0; i < n; i++) 
    an = an*a % m;

  unordered_map<ll,int> vals;
  for (int q = 0, cur = b; q <= n; q++) {
    vals[cur] = q;
    cur = cur*a%m;
  }
  for (int p = 1, cur = 1; p <= n; p++) {
    cur = cur*an%m;
    if (vals.count(cur)) {
      ll ans = n*p-vals[cur];
      return ans;
    }
  }
  return -1;
}

template<ll M=0>
struct Matrix {
  vector<vector<ll>> a;
  Matrix(int n, int m) : a(n, vector<ll>(m)) {}
  Matrix(int n) : a(n, vector<ll>(n)) {
    for (int i = 0; i < n; i++) a[i][i] = 1;
  }

  Matrix operator*(const Matrix &other) const {
    int n = a.size();
    int p = a[0].size(); assert(p == other.a.size());
    int m = other.a[0].size();

    Matrix res = Matrix(n, m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < p; k++) {
          if (M == 0) res.a[i][j] = (res.a[i][j] 
            + (a[i][k]*other.a[k][j]));
          else {
            res.a[i][j] = (res.a[i][j] 
              + (a[i][k]*other.a[k][j])%M)%M;
            if (res.a[i][j] < 0) res.a[i][j] += M; 
          }
        }
      }
    }
    return res;
  }

  Matrix expo(ll e) const {
    int n = a.size(); assert(n == a[0].size());
    Matrix b = Matrix(n, n);
    b.a = a;

    Matrix ans = Matrix(n);
    while (e > 0) {
      if (e&1) ans = ans*b;
      b = b*b;
      e >>= 1;
    }
    return ans;
  }
};

const ll MOD = 1e9+7;
int main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, f1, f2, f3, c; cin >> n >> f1 >> f2 >> f3 >> c;

  ll logf1 = mod_log(5, f1, MOD), logf2 = mod_log(5, f2, MOD);
  ll logf3 = mod_log(5, f3, MOD), logc = mod_log(5, c, MOD);
  
  Matrix<MOD-1> A(5, 5);
  A.a = {
    {1, 1, 1, 2*logc, -6*logc},
    {1, 0, 0, 0 ,0},
    {0, 1, 0, 0, 0},
    {0, 0, 0, 1, 1},
    {0, 0, 0, 0, 1}}; 
  Matrix<MOD-1> b(5, 1);
  b.a = {
    {logf3},
    {logf2},
    {logf1},
    {4},
    {1},
  };

  cout << mod_pow(5, (A.expo(n-3)*b).a[0][0], MOD) << "\n";

  return 0;
}