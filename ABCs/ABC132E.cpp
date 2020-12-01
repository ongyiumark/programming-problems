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
vector<int> graph[3*N];

int solve(int s, int t){
  vector<bool> vis(3*N);
  
  int moves = 0;
  int nodesCurr = 1;
  int nodesNext = 0;

  queue<int> q;
  q.push(s);
  vis[s] = true;

  while(!q.empty()){
    int u = q.front();
    q.pop();
    if (u == t) {
      return moves/3;
    }
    for (auto v : graph[u]){
      if (vis[v]) continue;
      q.push(v);
      vis[v] = true;
      nodesNext++;
    }
    nodesCurr--;
    if (nodesCurr == 0){
      nodesCurr = nodesNext;
      nodesNext = 0;
      moves++;
    }
  }

  return -1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    u--; v--;
    u *= 3;
    v *= 3;
    graph[u].push_back(v+1);
    graph[u+1].push_back(v+2);
    graph[u+2].push_back(v);
  }

  int s, t; cin >> s >> t;
  s--; t--;
  s *= 3; t *= 3;
  cout << solve(s, t) << endl;
  return 0;
}
