/*
  Get the distances from 1 and the distances from n.
  Notice that all nodes where distance_from_1 <= distance_from_n will be colored black.
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

const int N = 1e5+1;
vector<int> adj[N];
int dist_f[N];
int dist_s[N];

void dfs(int u, int p, int d, int* dist){
  dist[u] = d;
  for (int v : adj[u]){
    if (v == p) continue;
    dfs(v, u, d+1, dist);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(1, -1, 0, dist_f); dfs(n, -1, 0, dist_s);

  int cnt = 0;
  for (int i = 1; i <= n; i++){
    cnt += dist_f[i] <= dist_s[i];
  }
  cout << (cnt > n-cnt ? "Fennec" : "Snuke") << endl;
  return 0;
}
