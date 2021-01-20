/*
  Get the all sources shortest path.
  Try all r! ways to go through the cities.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 200;
int R[8];
int adjmat[N][N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, r;
  cin >> n >> m >> r;
  for (int i = 0; i < r; i++){
    cin >> R[i];
    R[i]--;
  }
  memset(adjmat, 63, sizeof adjmat);
  for (int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    adjmat[a][b] = c;
    adjmat[b][a] = c;
  }

  for (int k = 0; k < n; k++){
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        adjmat[i][j] = min(adjmat[i][j], adjmat[i][k]+adjmat[k][j]);
      }
    }
  }

  sort(R, R+r);
  int ans = 1e9;
  do {
    int curr = 0;
    for (int i = 1; i < r; i++){
      curr += adjmat[R[i-1]][R[i]];
    }
    ans = min(ans, curr);
  } while(next_permutation(R, R+r));
  cout << ans << endl;
  return 0;
}
