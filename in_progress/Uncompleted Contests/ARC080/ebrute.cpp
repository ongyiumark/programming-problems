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

const int INF = 1e9;
const int N = 2e5+5;
int p[N];
int sparse[2][N][20];

int n;

int rmq(int par, int l, int r) {
  if (l%2 == 1) par = 1- par;
  int dist = 32 - __builtin_clz(r-l+1) - 1;
  int u = sparse[par][l][dist];
  int v = sparse[par][max(r-(1<<dist)+1, 0)][dist];
  if (u == -1) return v;
  if (v == -1) return u;
  return (p[u] < p[v] ? u : v);
}

vector<int> solve(int l, int r){
  vector<int> res;
  if (l > r) return res;
  assert((r-l+1)%2 == 0);
  if (r-l+1 == 2) {
    res.push_back(p[l]);
    res.push_back(p[l+1]);
    return res;
  }

  int idxl = rmq(0, l, r);
  int idxr = rmq(1, idxl, r);
  //cout << idxl << " " << idxr << " " << l << " " << r << endl;
  
  res.push_back(p[idxl]);
  res.push_back(p[idxr]);
  vector<int> left = solve(l, idxl-1);
  vector<int> right = solve(idxr+1, r);
  vector<int> mid = solve(idxl+1, idxr-1);

  int i = 0, j = 0, k = 0;
  int n = left.size(), m = right.size(), o = mid.size();
  // merge left, right, and mid
  while(i < n || j < m || k < o) {
    int x = (i < n ? left[i] : INF);
    int y = (j < m ? right[j] : INF);
    int z = (k < o ? mid[k] : INF);

    if (x < min(y,z)) {
      res.push_back(left[i]); res.push_back(left[i+1]);
      i += 2;
    }
    else if (y < min(x,z)) {
      res.push_back(right[j]); res.push_back(right[j+1]);
      j += 2;
    }
    else {
      res.push_back(mid[k]); res.push_back(mid[k+1]);
      k += 2;
    }
  }
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> p[i];
  for (int i = 0; i < n; i++) {
    sparse[i%2][i][0] = i;
    if (i%2 == 0) sparse[0][i+1][0] = -1;
    else sparse[1][i-1][0] = -1;
  }
  
  for (int j = 0; j < 2; j++) {
    for (int k = 1; k < 20; k++) {
      for (int i = 0; i < n; i++) {
        int u = sparse[j][i][k-1];
        int v = sparse[j][min(i+(1<<(k-1)), n-1)][k-1];
        if (u == -1) sparse[j][i][k] = v;
        else if (v == -1) sparse[j][i][k] = u;
        else sparse[j][i][k] = (p[u] < p[v] ? u : v);
      }
    }
  }
  /*
  for (int i = 0; i < n; i++) {
    cout << sparse[1][i][2] << endl;
  }
  */

  vector<int> ans = solve(0, n-1);  
  int sz = ans.size();
  for (int i = 0; i < sz; i++) {
    cout << ans[i];
    if (i != sz-1) cout << " ";
    else cout << endl;
  }
  return 0;
  
  
}
