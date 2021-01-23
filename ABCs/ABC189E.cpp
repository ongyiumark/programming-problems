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

const int N = 2e5+1;
pair<ll,ll> points[N];
pair<ll,ll> adds[N];
pair<bool,bool> mults[N];
bool flips[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(adds, 0, sizeof adds);
  memset(mults, 0, sizeof mults);
  memset(flips, 0, sizeof flips);
  
  int n; cin >> n;
  for (int i = 1; i <= n; i++){
    ll x, y; cin >> x >> y;
    points[i] = {x,y};
  }

  int m; cin >> m;
  pair<ll,ll> cadd = {0,0};
  pair<bool,bool> cmult = {0,0};
  bool cflip = 0;
  for (int i = 1; i <= m; i++){
    int op; cin >> op;
    // 1 <-> 2 and 3 <-> 4
    if (cflip) op = op + (op&1 ? 1 : -1);
    
    // mx+b -> -mx-b and swap xy.
    if (op == 1){
      cmult.first = !cmult.first;
      cadd.first *= -1;
      cflip = !cflip;
    }
    // my+b -> -my-b and swap xy.
    else if (op == 2){
      cmult.second = !cmult.second;
      cadd.second *= -1;
      cflip = !cflip;
    }
    // mx+b -> 2p-mx-b
    else if (op == 3){
      ll p; cin >> p;
      cmult.first = !cmult.first;
      cadd.first = 2*p-cadd.first;
    }
    // my+b -> 2p-my-b
    else {
      ll p; cin >> p;
      cmult.second = !cmult.second;
      cadd.second = 2*p-cadd.second;
    }
    adds[i] = cadd;
    mults[i] = cmult;
    flips[i] = cflip;
  }

  int q; cin >> q;
  while(q--){
    int a, b; cin >> a >> b;
    ll nx = (mults[a].first ? -1 : 1)*points[b].first + adds[a].first;
    ll ny = (mults[a].second ? -1 : 1)*points[b].second + adds[a].second;
    if (flips[a]) swap(nx, ny);
    cout << nx << " " << ny << endl;
  }
  return 0;
}
