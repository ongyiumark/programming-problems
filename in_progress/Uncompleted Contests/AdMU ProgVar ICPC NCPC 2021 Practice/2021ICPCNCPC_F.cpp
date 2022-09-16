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

const ld eps = 1e-8;
bool eq(ld a, ld b) {
  return abs(a-b) < eps;
}

ld gauss_jordan(vector<vector<ld>> &A, vector<ld> &b) {
  int n = A.size();
  assert(n == A[0].size());
  assert(n == b.size());

  for (int k = 0; k < n; k++) {
    // Find pivot
    int piv = -1;
    for (int i = k; i < n; i++) {
      if (!eq(A[i][k], 0)) {
        piv = i;
        break;
      } 
    }
    if (piv == -1) continue;
    swap(A[piv],A[k]);
    swap(b[piv],b[k]);

    // Eliminate rows
    for (int i = 0; i < n; i++) {
      if (i == k) continue;
      ld mult = A[i][k]/A[k][k];
      for (int j = 0; j < n; j++) {
        A[i][j] -= mult*A[k][j];
      }
      b[i] -= mult*b[k];
    }

    // Scale row
    ld mult = 1/A[k][k];
    for (int j = 0; j < n; j++) {
      A[k][j] *= mult;
    }
    b[k] *= mult;
  }
  return b[0];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k; cin >> n >> k;
  ld p; cin >> p;

  int sz = (1<<n);
  vector<vector<ld>> A(sz, vector<ld>(sz, 0));
  vector<ld> b(sz, 0);
  for (int i = 0; i < sz; i++) {
    A[i][i] += 1;
    if (__builtin_popcount(i) >= k) continue;
    b[i] = 1;
    A[i][(i<<1)%sz] += -(1-p);
    A[i][(i<<1|1)%sz] += -p;
  }

  ld ans = gauss_jordan(A,b);
  cout << fixed << setprecision(12) << ans << endl;
  
  return 0;
}
