/*
  To get the maximum cost, simply do minimum cost on negative of the weights.
  USe Bellman-Ford to detect negative cycles, which means that you can increase the score indefinitely.
  Make sure to only consider cycles that are on the path to node n.
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
const int N = 1000;
const int M = 2000;
ll a[M], b[M], c[M];
ll dist[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m; 
  for (int i = 0; i < m; i++){
    cin >> a[i] >> b[i] >> c[i];
    c[i] *= -1;
    a[i]--; b[i]--;
  }

  memset(dist, 63, sizeof dist);
  dist[0] = 0;
  for (int i = 0; i < n-1; i++){
    for (int j = 0; j < m; j++){
      if (dist[a[j]]+c[j] < dist[b[j]]){
        dist[b[j]] = dist[a[j]]+c[j];
      }
    }
  }

  bool cycle = 0;
  for (int j = 0; j < m; j++){
    if (dist[a[j]]+c[j] < dist[b[j]]){
      dist[b[j]] = dist[a[j]]+c[j];
      if (b[j] == n-1) cycle = 1;
    }
  }

  if (cycle) cout << "inf" << endl;
  else cout << -dist[n-1] << endl;
  return 0;
}
