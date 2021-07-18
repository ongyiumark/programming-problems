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

const int N = 1e5+5;
vector<pii> adjlist[N];

set<int> apartments;
int apartcnt[N];
int par[N];

int dfs(int u, int p){
  apartcnt[u] = (apartments.find(u) != apartments.end() ? 1 : 0);
  par[u] = p;
  for (auto e : adjlist[u]){
    if (e.first == p) continue;
    apartcnt[u] += dfs(e.first, u);
  }
  return apartcnt[u];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k; cin >> n >> k;
  for (int i = 0; i < n-1; i++){
    int u, v, w; cin >> u >> v >> w;
    adjlist[u].push_back({v,w});
    adjlist[v].push_back({u,w});
  }
  for (int i = 0; i < k; i++){
    int x; cin >> x;
    apartments.insert(x);
  }

  dfs(*apartments.begin(),-1);

  int cnt = 0;
  for (int i = 1; i <= n; i++){
    cnt += (apartcnt[i] == 0);
  }

  cout << n - cnt << endl;
  return 0;
}
