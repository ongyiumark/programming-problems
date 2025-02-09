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

const ll MOD = 998244353;

// count ways to make mask from empty
int cnt_ways(int mask, int i, int h) {
  if (mask == 0) return 1;

  int ret = 0;
  if ((mask>>i)&1 == 1) {
    mask ^= (1 << i);
    ret += cnt_ways(mask, i+1, h);
    mask ^= (1 << i);
  }
  else ret += cnt_ways(mask, i+1, h);

  if (i+1 < h and ((mask>>i)&1 == 1) and ((mask>>(i+1))&1 == 1)) {
    mask ^= (1 << i);
    mask ^= (1 << (i+1));
    ret += cnt_ways(mask, i+2, h);
    mask ^= (1 << i);
    mask ^= (1 << (i+1));
  }

  return ret;
}

ll solve(int mi, int mj, int h) {
  // mi based on mj
  int f_mi = ((1<<h)-1) - mi; // remove 2 by 1 for current layer
  if ((f_mi&mj) == mj) { // must be possible to get from mj to f_mi
    return cnt_ways(f_mi - mj, 0, h); // count ways to get from mj to f_mi
  }
  else return 0;
}

vector<vector<ll>> matmult(vector<vector<ll>> &A, vector<vector<ll>> &B) {
  ll n = A.size();
  ll p = A[0].size();
  ll m = B[0].size();
  assert(p == B.size());

  vector<vector<ll>> C(n, vector<ll>(m));
  for (int k = 0; k < p; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        C[i][j] += A[i][k]*B[k][j];
        C[i][j] %= MOD;
      }
    }
  }
  return C;
}

vector<vector<ll>> matpow(vector<vector<ll>> A, ll e) {
  ll n = A.size();
  assert(n == A[0].size());
  vector<vector<ll>> ans(n, vector<ll>(n));
  for (int i = 0; i < n; i++) ans[i][i] = 1;

  while(e > 0) {
    if (e&1) ans = matmult(ans, A);
    A = matmult(A, A);
    e >>= 1;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll h, w; cin >> h >> w;
  int sz = (1<<h);
  vector<vector<ll>> mat(sz, vector<ll>(sz, 0));
  for (int i = 0; i < sz; i++) {
    for (int j = 0; j < sz; j++) {
      mat[i][j] = solve(i, j, h);
    }
  }

  vector<vector<ll>> res = matpow(mat, w);
  cout << res[0][0] << endl;
  
  return 0;
}
