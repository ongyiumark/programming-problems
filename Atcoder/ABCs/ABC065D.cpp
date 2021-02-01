/*
  For every pair of points a and b, we can create two edges with weights: |x_a - x_b| and |y_a - y_b| 
  This is an MST problem, but we can't include all the edges.
  
  Notice that if x_a < x_b < x_c, it would be optimal to have a-b and b-c rather than a-c.
  Thus, we only need to include edges of adjacent cities when sorted by x.
  The same argument works for y.
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

const int N = 1e5;
int x[N], y[N];
pair<int,int> px[N], py[N];
vector<pair<int,int>> graph[N];

ll solve(int n){
  priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
  int val[n], par[n];
  vector<bool> vis(n);
  memset(val, 127, sizeof val);
  val[0] = 0;
  par[0] = -1;
  pq.push({0,0});
  
  while(!pq.empty()){
    int u = pq.top().second;
    pq.pop();
    vis[u] = true;
    for (auto e : graph[u]){
      int v = e.first;
      int w = e.second;
      if (!vis[v] && w < val[v]){
        val[v] = w;
        par[v] = u;
        pq.push({val[v], v});
      }
    }
  }

  ll total = 0;
  for (int i = 1; i < n; i++){
    total += val[i];
  }
  return total;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
    px[i] = {x[i], i};
    py[i] = {y[i], i};
  }
  sort(px, px+n);
  sort(py, py+n);

  for (int i = 1; i < n; i++){
    int u = px[i].second;
    int v = px[i-1].second;
    graph[u].push_back({v, abs(x[u]-x[v])});
    graph[v].push_back({u, abs(x[u]-x[v])});

    u = py[i].second;
    v = py[i-1].second;
    graph[u].push_back({v, abs(y[u]-y[v])});
    graph[v].push_back({u, abs(y[u]-y[v])});
  }

  cout << solve(n) << endl;

  return 0;
}
