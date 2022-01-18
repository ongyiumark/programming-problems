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

const int MAXN = 1e5+5;
const ll MOD = 1e9+7;
bool flag[4*MAXN];
matrix segtree[4*MAXN];
int n;

matrix matmult(matrix& a, matrix& b){
  matrix c = {{0,0},{0,0}};
  for (int i = 0; i < 2; i++){
    for (int k = 0; k < 2; k++){
      for (int j = 0; j < 2; j++){
        c[i][j] += a[i][k]*b[k][j];
      }
    }
  }
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++){
      c[i][j] %= MOD;
    }
  }
  return c;
}

matrix flip(matrix& a){
    matrix res = {{a[1][1], a[1][0]}, {a[0][1], a[0][0]}};
    return res;
} 

void pull(int p){
  segtree[p] = matmult(segtree[2*p], segtree[2*p+1]);
}

void push(int p, int i, int j) {
  if (flag[p]){
    segtree[p] = flip(segtree[p]);
    if (i != j){
      flag[2*p] = !flag[2*p];
      flag[2*p+1] = !flag[2*p+1];
    }
    
    flag[p] = 0;
  }
}

void build(vector<matrix> &ar, int p, int i, int j){
  flag[p] = 0;
  if (i == j){
    segtree[p] = ar[i];
  }
  else {
    int k = (i+j)/2;
    build(ar, 2*p, i, k);
    build(ar, 2*p+1, k+1, j);
    pull(p);
  }
}

void update(int _i, int _j, int p, int i, int j){
  push(p, i, j);
  if (_i <= i && j <= _j){
    flag[p] = 1;
    push(p, i, j);
  }
  else if (_j < i || j < _i){

  }
  else {
    int k = (i+j)/2;
    update(_i,_j, 2*p, i, k);
    update(_i,_j, 2*p+1, k+1, j);
    pull(p);
  }
}

matrix query(int _i, int _j, int p, int i, int j){
  push(p, i, j);
  if (_i <= i && j <= _j){
    return segtree[p];
  }
  else if (_j < i || j < _i){
    matrix res = {{1,0},{0,1}};
    return res;
  }
  else {
    int k = (i+j)/2;
    matrix x = query(_i,_j, 2*p, i, k);
    matrix y = query(_i, _j, 2*p+1, k+1, j);
    return matmult(x, y);
  }
}

void debugmat(matrix &m){
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++){
      cout << m[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void printmat(ll a, ll b, matrix& m){
  ll top = m[0][0]*a + m[0][1]*b;
  top %= MOD;

  ll bot = m[1][0]*a + m[1][1]*b;
  bot %= MOD;

  cout << top << " " << bot << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memset(flag, 0, sizeof flag);
  int q; cin >> n >> q;
  string s; cin >> s;
  
  matrix A = {{1,1},{0,1}};
  matrix B = {{1,0},{1,1}}; 

  vector<matrix> arr;
  // Build segtree
  for (int i = 0; i < n; i++){
    if (s[i] == 'A') arr.push_back(A);
    else arr.push_back(B);
  }

  reverse(arr.begin(), arr.end());
  build(arr, 1, 0, n-1);

  /*for (int i = 0; i < n; i++){
    matrix mat = query(n-1-i,n-1-i,1,0,n-1);
    debugmat(mat);
  }*/

  while(q--){
    int t; cin >> t;
    if (t==1){
      int l, r; cin >> l >> r;
      l--, r--;
      update(n-1-r, n-1-l, 1, 0, n-1);
    }
    else{
      int l, r;
      ll a, b;
      cin >> l >> r;
      l--, r--;
      cin >> a >> b;
      matrix mat = query(n-1-r, n-1-l, 1, 0, n-1);
      //debugmat(mat);
      printmat(a, b, mat);
    }
  }


  
  return 0;
}
