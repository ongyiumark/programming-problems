/*
  Brute force count.
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;
  bool adjmat[n][n];
  memset(adjmat, 0, sizeof adjmat);
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    adjmat[u][v] = adjmat[v][u] = 1;
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      for (int k = j+1; k < n; k++) {
        if (adjmat[i][j] && adjmat[j][k] && adjmat[k][i]) {
          res++;
        }
      }
    }
  }

  cout << res << endl;
  
  return 0;
}
