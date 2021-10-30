/*
  Modified Least common ancestor (binary lifting).
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 3e5+5;
vector<pair<int,ull>> graph[N];
pair<int,ull> par[N];
int depth[N];

ull gcd(ull a, ull b){
  if (b==0) return a;
  return gcd(b, a%b);
}

ull lcm(ull a, ull b){
  return a/gcd(a,b)*b;
}

void root(int u, int p, int d){
  depth[u] = d;
  for (auto e : graph[u]){
    int v = e.first;
    ull w = e.second;
    if (v == p) continue;
    par[v] = {u,w};
    root(v, u, d+1);
  }
}

pair<int,ull> lca[20][N];

int move_idx(int x, int d){
  if (d == 0) return x;

  int i = 0;
  while(d > 0){
    if (d&1) x = lca[i][x].first;
    d/=2;
    i++;
  }
  return x;
}

ull move_lcm(int x, int d){
  if (d == 0) return 1;

  int i = 0;
  ull mult = 1;
  while(d > 0){
    if (d&1) {
      mult = lcm(mult, lca[i][x].second);
      x = lca[i][x].first;
    }
    d/=2;
    i++;
  }
  return mult;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, q; cin >> n >> q;
  for (int i = 0; i < n-1; i++){
    int u, v, w; cin >> u >> v >> w;
    u--; v--;
    graph[u].push_back({v,w});
    graph[v].push_back({u,w});
  }

  // root at 0
  par[0] = {0,1};
  root(0, -1, 0);

  for (int i = 0; i < n; i++){
    lca[0][i] = par[i];
  }

  // precompute lca
  for (int k = 1; k < 20; k++){
    for (int i = 0; i < n; i++){
      pair<int, ull> h1 = lca[k-1][i];
      pair<int, ull> h2 = lca[k-1][h1.first];
      lca[k][i] = {h2.first, lcm(h1.second, h2.second)};
    }
  }

  while(q--){
    int a, b;
    cin >> a >> b;
    a--; b--;

    if (depth[a] > depth[b]) swap(a,b);

    ull tmp = move_lcm(b, depth[b]-depth[a]);
    b = move_idx(b, depth[b]-depth[a]);
    if (b == a) {
      cout << tmp << endl;
      continue;
    }

    int lo = 0;
    int hi = n;
    int ans = -1;
    while(lo <= hi){
      int mid = hi - (hi-lo)/2;
      int a1 = move_idx(a, mid);
      int b1 = move_idx(b, mid);
      if (a1 == b1){
        ans = mid;
        hi = mid-1;
      }
      else lo = mid+1;
    }

    ull res = lcm(tmp, lcm(move_lcm(a, ans), move_lcm(b, ans)));
    cout << res << endl;
  }



  return 0;
}
