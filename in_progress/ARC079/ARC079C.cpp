/*
  Just brute force all the neighbors of the neighbors of 1.
*/
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

const int N = 2e5+5;

vector<int> graph[N];
int n, m;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  bool ans = false;
  for (int u : graph[1]){
    for (int v : graph[u]){
      if (v == n) ans = true;
    }
  }
  cout << (ans ? "POSSIBLE" : "IMPOSSIBLE") << endl;
  return 0;
}
