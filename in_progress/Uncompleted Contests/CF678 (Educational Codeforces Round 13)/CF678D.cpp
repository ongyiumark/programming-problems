/* 
  Standard matrix exponentiation.
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
typedef vector<vector<ll>> matrix;
template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll MOD = 1e9+7;

matrix mult(matrix& a, matrix& b) {
  int n = a.size();
  int p = a[0].size();
  int m = b[0].size();
  assert(p == b.size());

  matrix c(n,vector<ll>(m,0));
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < p; k++) {
      for (int j = 0; j < m; j++) {
        c[i][j] = (c[i][j] + a[i][k]*b[k][j])%MOD;
      }
    }
  }
  return c;
}

matrix matpow(matrix a, ll e) {
  int n = a.size();
  assert(n == a[0].size());
  matrix ans(n, vector<ll>(n,0));
  for (int i = 0; i < n; i++) ans[i][i] = 1;

  while(e > 0) {
    if (e&1) ans = mult(ans,a);
    a = mult(a,a);
    e >>= 1;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll A, B, n, x; cin >> A >> B >> n >> x;
  matrix f = {{A,B},{0,1}};
  matrix s = {{x},{1}};
  
  matrix pref = matpow(f, n);
  matrix ans = mult(pref,s);
  cout << ans[0][0] << endl;
  return 0;
}
