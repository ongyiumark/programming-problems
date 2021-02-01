/*
  Simple BFS from 1 while counting the moves.
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

const int N = 2e5;
vector<int> adj[N];
bool vis[N];

bool bfs(int s, int t){
  memset(vis, 0, sizeof vis);
  queue<int> q;
  q.push(s);
  vis[s] = 1;
  int currlayer = 1;
  int nextlayer = 0;
  int moves = 0;
  bool found = 0;
  while(!q.empty()){
    int u = q.front();
    q.pop();
    if (u == t) {
      found = 1;
      break;
    }
    for (int v : adj[u]){
      if (vis[v]) continue;
      vis[v] = 1;
      q.push(v);
      nextlayer++;
    }
    currlayer--;
    if (!currlayer){
      currlayer = nextlayer;
      nextlayer = 0;
      moves++;
      if (moves > 2) break;
    }
  }
  return found;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  cout << (bfs(0, n-1) ? "POSSIBLE" : "IMPOSSIBLE") << endl;
  return 0;
}
