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

struct point {
  ll x, y;
};

ld dist(const point &a, const point &b) {
  return sqrtl((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

struct edge {
  int v;
  ld w;
};

const ld EPS = 1e-9;

bool find_path(vector<vector<edge>> &adj, int s, int t, ld r) {
  int n = adj.size();
  vector<bool> vis(n);
  queue<int> q;
  vis[s] = true;
  q.push(s);

  while(!q.empty()) {
    int u = q.front();
    q.pop();
    if (u%3 == 2) return true;
    for (auto &[v, w] : adj[u]) {
      if (w > r) continue;
      if (vis[v]) continue;
      q.push(v);
      vis[v] = true;
    }
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  vector<point> p(3*n);
  for (int i = 0; i < n; i++) {
    ll x, y; cin >> x >> y;
    p[3*i] = {x, -100}; // 0 mod 3 is bottom
    p[3*i+1] = {x, y}; // 1 mod 3 is point
    p[3*i+2] = {x, 100}; // 2 mod 3 is top
  }

  vector<vector<edge>> adj(3*n+2, vector<edge>());
  for (int i = 0; i < 3*n; i++) {
    for (int j = i+1; j < 3*n; j++) {
      ld w = dist(p[i], p[j]);
      adj[i].push_back({j, w});
      adj[j].push_back({i, w});
    }
  } 

  int source = 3*n;
  int sink = 3*n+1;
  for (int i = 0; i < n; i++) {
    adj[source].push_back({3*i, 0});
    adj[3*i+2].push_back({sink, 0});
  }

  cout << setprecision(10) << fixed;

  ld lo = 0;
  ld hi = 200;
  ld r;
  while (fabs(hi-lo) > EPS) {
    r = (lo+hi)/2;
    bool found_wall = find_path(adj, source, sink, r); 
  
    if (found_wall) hi = r;
    else lo = r;
  } 

  cout << r/2 << "\n";
  return 0;
}
