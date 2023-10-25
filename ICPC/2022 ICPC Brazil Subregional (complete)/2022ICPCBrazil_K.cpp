#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9;
const int K = 401;

struct poly {
  vector<ll> p;

  poly() : p(K) {}
  poly identity() {
    poly res = poly();
    res.p[0] = 1;
    return res;
  }

  poly operator*(const poly& other) const {
    poly ans = poly();
    for (int i = 0; i < K; i++) {
      for (int j = 0; j <= i; j++) {
        ans.p[i] += p[j]*other.p[i-j]%MOD;
      }
    }
    for (int i = 0; i < K; i++) ans.p[i]%=MOD;
    return ans;
  }
  poly operator+(const poly& other) const {
    poly ans = poly();
    for (int i = 0; i < K; i++) {
      ans.p[i] = (p[i] + other.p[i])%MOD;
    }
    return ans;
  }
};

struct polymatrix {
  vector<vector<poly>> a;
  polymatrix(int n, int m) : a(n, vector<poly>(m)) {}
  polymatrix identity(int n) {
    polymatrix res = polymatrix(n, n);
    for (int i = 0; i < n; i++) res.a[i][i] = poly().identity();
    return res;
  }

  polymatrix operator*(const polymatrix &other) const {
    int n = a.size();
    int p = a[0].size();
    assert(p == other.a.size());
    int m = other.a[0].size();

    polymatrix res = polymatrix(n, m);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < p; k++) {
          res.a[i][j] = res.a[i][j] + (a[i][k]*other.a[k][j]);
        }
      }
    }
    return res;
  }

  polymatrix expo(ll e) const {
    int n = a.size();
    assert(n == a[0].size());
    polymatrix b = polymatrix(n, n);
    b.a = a;

    polymatrix ans = polymatrix(1, 1).identity(n);
    while (e > 0) {
      if (e&1) ans = ans*b;
      b = b*b;
      e >>= 1;
    }
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k; cin >> n >> m >> k;
  vector<int> d(m), p(m);
  for (int i = 0; i < m; i++) {
    cin >> d[i] >> p[i];
  }

  vector cnt(11, poly());
  for (int i = 0; i < m; i++) {
    if (p[i] > k) continue;
    cnt[d[i]].p[p[i]]++;
  }

  vector dp(10, poly());
  dp[9] = poly().identity();

  polymatrix mat(10, 10);
  for (int j = 0; j < 10; j++) mat.a[0][j] = cnt[j+1];
  for (int i = 1; i < 10; i++) mat.a[i][i-1] = poly().identity();

  polymatrix start(10, 1);
  for (int i = 0; i < 10; i++) start.a[i][0] = dp[9-i];
  polymatrix res = mat.expo(n-1)*start;
  
  ll total = 0;
  for (int a = 0; a <= k; a++) {
    total += res.a[0][0].p[a];
  }
  total %= MOD;
  cout << total << "\n";
  

  return 0;
}