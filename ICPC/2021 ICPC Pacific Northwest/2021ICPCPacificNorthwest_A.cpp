#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef vector<vector<ll>> matrix;
const ll MOD = 1e9+7;

matrix matmult(matrix &a, matrix &b) {
  int n = a.size();
  int p = a[0].size();
  assert(p == b.size());
  int m = b[0].size();

  matrix c(n, vector<ll>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < p; k++) {
        c[i][j] += a[i][k]*b[k][j]%MOD;
        c[i][j] %= MOD;
      }
    }
  }
  return c;
}

matrix matpow(matrix b, ll e) {
  int n = b.size();
  assert(n == b[0].size());
  matrix ans(n, vector<ll>(n));
  for (int i = 0; i < n; i++) ans[i][i] = 1;

  while (e > 0) {
    if (e&1) ans = matmult(ans, b);
    b = matmult(b, b);
    e >>= 1;
  }
  return ans;
}

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);


  ll a, b, n; cin >> a >> b >> n;

  ll sin_theta = 2*a*b%MOD;
  ll cos_theta = (a*a - b*b)%MOD;
  ll d = (a*a + b*b)%MOD;
  sin_theta = (sin_theta*modinv(d))%MOD;
  cos_theta = (cos_theta*modinv(d))%MOD;


  matrix A = {{cos_theta, sin_theta}, {-sin_theta, cos_theta}};
  matrix s = {{-1}, {0}};

  A = matpow(A, n+1);
  matrix res = matmult(A, s);
  ll ans = res[0][0];
  if(ans < 0) ans += MOD;
  cout << ans << "\n";
 
  return 0;
}