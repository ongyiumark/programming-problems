#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5;
map<pii, ll> points;
ll x[N], y[N];
map<pii, bool> vis;
int n, a, b;

int solve(){
  queue<int> q;
  q.push(a);
  q.push(b);
  vis[{min(a,b),max(a,b)}] = 1;

  ll dist = abs(x[a]-x[b]) + abs(y[a]-y[b]);
  int cnt = 0;
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for (int vx = 0; vx <= dist; vx++){
      if (points.count({x[u]+vx, y[u]+dist-vx})) {
        int idx = points[{x[u]+vx, y[u]+dist-vx}];
        if (!vis.count({min(u,idx),max(u,idx)})) {
          q.push(idx);
          vis[{min(u,idx),max(u,idx)}] = 1;
        }
      }
      if (points.count({x[u]-vx, y[u]+dist-vx})) {
        int idx = points[{x[u]-vx, y[u]+dist-vx}];
        if (!vis.count({min(u,idx),max(u,idx)})) {
          q.push(idx);
          vis[{min(u,idx),max(u,idx)}] = 1;
        }
      }
      if (points.count({x[u]+vx, y[u]-dist+vx})) {
        int idx = points[{x[u]+vx, y[u]-dist+vx}];
        if (!vis.count({min(u,idx),max(u,idx)})) {
          q.push(idx);
          vis[{min(u,idx),max(u,idx)}] = 1;
        }
      }
      if (points.count({x[u]-vx, y[u]-dist+vx})) {
        int idx = points[{x[u]-vx, y[u]-dist+vx}];
        if (!vis.count({min(u,idx),max(u,idx)})) {
          q.push(idx);
          vis[{min(u,idx),max(u,idx)}] = 1;
        }
      }
    }
  }
  return vis.size();
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> a >> b;
  a--; b--;
  for (int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
    points[{x[i], y[i]}] = i;
  }
  cout << solve() << endl;
  return 0;
}
