/*
  Answer the inverse of the problem.
  Bitmasking with the edges of the tree.
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

const int N = 51;
vector<int> graph[N];
map<pair<int, int>, int> edges; 

ll fastpow(ll b, ll e){
  ll ans = 1;
  while(e > 0){
    if (e&1) ans *= b;
    b *= b;
    e >>= 1;
  }
  return ans;
}

ll find_paths(int a, int b){
  queue<int> q;
  vector<bool> vis(N);
  vector<int> par(N, -1);

  vis[a] = true;
  q.push(a);

  while(!q.empty()){
    int u = q.front();
    q.pop();
    if (u == b) break;
    for (int v : graph[u]){
      if (vis[v]) continue;
      vis[v] = true;
      q.push(v);
      par[v] = u;
    }
  }

  ll path = 0;
  while(true){
    if (par[b] == -1) break;
    int x = min(b, par[b]);
    int y = max(b, par[b]);
    path |= (1LL << edges[{x,y}]);
    b = par[b];
  }

  return path;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    if (a > b) swap(a,b);
    graph[a].push_back(b);
    graph[b].push_back(a);
    edges[{a,b}] = i;
  }

  int m; cin >> m;
  ll paths[m];
  for (int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    paths[i] = find_paths(u, v);
  }

  ll ans = 0;
  for (int x = 1; x < (1LL << m); x++){
    ll path = 0;
    for (int i = 0; i < m; i++){
      if (x&(1LL << i)) path |= paths[i];
    }
    
    int cnt = __builtin_popcountll(path);
    ll ways = fastpow(2, n-1-cnt);
  
    if (__builtin_popcountll(x)%2) ans += ways;
    else ans -= ways;
  }

  cout << fastpow(2, n-1)-ans << endl;
  return 0;
}