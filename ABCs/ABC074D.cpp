/*
  Check for contradictions. It's impossible if you can find a shorter path than provided.
  That is, if dist[i][k] + dist[k][j] < dist[i][j] for some k.
  
  Only include edges (i, j) where there is no k such that dist[i][k] + dist[k][j] = dist[i][j].
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

const int N = 301;
ll dist[N][N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      cin >> dist[i][j];
    }
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      bool valid = 1;
      for (int k = 1; k <= n; k++){
        if (dist[i][j] > dist[i][k] + dist[k][j]){
          cout << -1 << endl;
          return 0;
        }

        if (dist[i][k] + dist[k][j] == dist[i][j] && i != k && k != j){
          valid = 0;
        }
      }
      if (valid) ans += dist[i][j];
    }
  }

  cout << ans/2 << endl;
  return 0;
}
