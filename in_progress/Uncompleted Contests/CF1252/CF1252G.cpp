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

const int N = 1e5+5;
ll A[N];
int R[N];
vector<ll> B[N];

struct segtree{
  int n, *vals, *deltas;
  segtree(vector<int> &ar) {
    n = ar.size();
    vals = new int[4*n];
    deltas = new int[4*n];
    build(ar, 1, 0, n-1);
  } 

  void build(vector<int> &ar, int p, int i, int j){
    deltas[p] = 0;
    if (i==j)
      vals[p] = ar[i];
    else {
      int k = (i+j)/2;
      build(ar, p<<1, i, k);
      build(ar, p<<1|1, k+1, j);
      pull(p);
    }
  }

  void pull(int p) {
    vals[p] = min(vals[p<<1],vals[p<<1|1]);
  }

  void push (int p, int i, int j) {
    if (deltas[p]){
      vals[p] += deltas[p];
      if (i != j) {
        deltas[p<<1] += deltas[p];
        deltas[p<<1|1] += deltas[p];
      }
      deltas[p] = 0;
    }
  }

  void update(int _i, int _j, int v, int p, int i, int j){
    push(p, i, j);
    if (_i <= i && j <= _j){
      deltas[p] += v;
      push(p, i, j);
    }
    else if (_j < i || j < _i) {

    }
    else {
      int k = (i+j)/2;
      update(_i, _j, v, p<<1, i, k);
      update(_i, _j, v, p<<1|1, k+1, j);
      pull(p);
    }
  }

  int query(int _i, int _j, int p, int i, int j) {
    push(p, i, j);
    if (_i <= i && j <= _j){
      return vals[p];
    }
    else if (_j < i || j < _i) {
      return 1e9;
    }
    else {
      int k = (i+j)/2;
      return min(query(_i, _j, p<<1, i, k), query(_i, _j, p<<1|1, k+1, j));
    }
  }
};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, q; cin >> n >> m >> q;
  for (int i = 0; i < n; i++) cin >> A[i];
  for (int i = 0; i < m; i++){
    cin >> R[i];
    for (int j = 0; j < R[i]; j++){
      ll tmp; cin >> tmp;
      B[i].push_back(tmp);
    }
  }

  ll randall = A[0];
  vector<int> pos;
  // grabbing positions
  ordered_set<ll> os;
  for (int i = 0; i < n; i++){
    os.insert(A[i]);
  }
  pos.push_back(os.order_of_key(randall));
  for (int i = 0; i < m; i++){
    for (int j = 0; j < R[i]; j++) os.erase(os.find_by_order(0));
    for (int j = 0; j < R[i]; j++) os.insert(B[i][j]);
    pos.push_back(os.order_of_key(randall));
  }
  pos.pop_back();
  for (int i = 0; i < m; i++) {
    //cout << pos[i] << " " << R[i] << endl;
    pos[i] -= R[i];
  }


  segtree sg(pos);

  while(q--){
    int x, y, z; cin >> x >> y >> z;
    x--; y--;
    if (B[x][y] < randall && randall < z){
      B[x][y] = z;
      sg.update(x+1, sg.n-1, -1, 1, 0, sg.n-1);
    }
    if (B[x][y] > randall && randall > z){
      B[x][y] = z;
      sg.update(x+1, sg.n-1, 1, 1, 0, sg.n-1);
    }

    int res = sg.query(0,sg.n-1, 1, 0, sg.n-1);
    cout << (res >= 0 ? 1 : 0) << endl;
  }


  return 0;
}
