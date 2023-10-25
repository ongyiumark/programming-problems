#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int INF = 1e9;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, t; cin >> n >> t;
  vector adjs(t, vector(n, vector<int>()));
  for (int i = 0; i < t; i++) {
    int m; cin >> m;
    for (int j = 0; j < m; j++) {
      int u, v; cin >> u >> v;
      u--; v--;
      adjs[i][u].push_back(v);
      adjs[i][v].push_back(u);
    }
  }

  int k; cin >> k;
  vector<int> a(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    a[i]--;
  }

  queue<pair<int,int>> q;
  q.push({0,0});
  map<pair<int,int>, int> dist;
  dist[{0,0}] = 0;

  while (!q.empty()) {
    auto [utime, unode] = q.front();
    q.pop();
    vector<int> &neighbors = adjs[a[utime]][unode];
    for (int v : neighbors) {
      if (dist.find({utime+1, v}) != dist.end()) continue;
      dist[{utime+1, v}] = dist[{utime,unode}]+1;
      if (utime+1 < k) q.push({utime+1, v});
    }
    if (dist.find({utime+1, unode}) == dist.end()) {
      dist[{utime+1, unode}] = dist[{utime, unode}]+1;
      if (utime+1 < k) q.push({utime+1, unode});
    }
  }

  int ans = INF;
  for (int time = 0; time < k; time++) {
    if (dist.find({time, n-1}) == dist.end()) continue;
    ans = min(dist[{time, n-1}], ans);
  }
  cout << (ans == INF ? - 1 : ans) << "\n";

  
  return 0;
}
