/*
  Suppose we have a point (x,y). The following are the transformations:
    90deg: (y,-x)
   -90deg: (-y,x)
    x = p: (2p-x, y)
    y = p: (x, 2p-y)
  
  Notice that after any number of operations, the result will be some linear transformation on x and y. 
  That is, mx+b where m is -1 or 1, and b is some constant.
  x and y may also swap places.

  Thus, after each operation, we simply need to keep track of m, b, and whether or not x and y are swapped.

  I just looked at the editorial, these operations can actially be done with matrix multiplication.
   90deg: 0  1  0      -90deg: 0 -1  0     x = p:  -1  0  2p    y = p:  1  0  0
         -1  0  0              1  0  0              0  1  0             0 -1  2p
          0  0  1              0  0  1              0  0  1             0  0  0
  
  Multiply this to: x
                    y
                    1
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

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<vector<ll>> matmult(vector<vector<ll>> &a, vector<vector<ll>> &b){
  int arow = a.size();
  int acol = a[0].size();
  int bcol = b[0].size();
  assert(acol == b.size());
  vector<vector<ll>> ans(arow, vector<ll>(bcol));
  for (int i = 0; i < arow; i++){
    for (int j = 0; j < acol; j++){
      for (int k = 0; k < bcol; k++){
        ans[i][k] += a[i][j]*b[j][k];
      }
    }
  }
  return ans;
}

const int N = 2e5+1;
vector<vector<ll>> points[N];
vector<vector<ll>> ops[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 1; i <= n; i++){
    ll x, y; cin >> x >> y;
    points[i] = {{x}, {y}, {1}};
  }
  int m; cin >> m;
  ops[0] = {{1,0,0},{0,1,0},{0,0,1}};
  for (int i = 1; i <= m; i++){
    int t; cin >> t;
    vector<vector<ll>> op;
    if (t == 1) op = {{0,1,0}, {-1,0,0}, {0,0,1}};
    else if (t == 2) op = {{0,-1,0}, {1,0,0}, {0,0,1}};
    else if (t == 3) {
      ll p; cin >> p;
      op = {{-1,0,2*p}, {0,1,0}, {0,0,1}};
    }
    else {
      ll p; cin >> p;
      op = {{1,0,0}, {0,-1,2*p}, {0,0,1}};
    }
    ops[i] = matmult(op, ops[i-1]);
  }
  int q; cin >> q;
  while(q--){
    int a, b;
    cin >> a >> b;
    vector<vector<ll>> ans = matmult(ops[a],points[b]);
    cout << ans[0][0] << " " << ans[1][0] << endl;
  }
  return 0;
}
