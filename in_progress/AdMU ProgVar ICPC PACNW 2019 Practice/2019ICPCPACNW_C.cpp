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

const int N = 1e5+5;
vector<int> graph[N];
int n;

int bfs(int s, int t) {
  queue<int> q;
  vector<bool> vis(n);
  vis[s] = 1; q.push(s);

  int moves = 0;
  int currnodes = 1;
  int nextnodes = 0;
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    if (u == t) return moves;
    for (int v : graph[u]) {
      if (vis[v]) continue;
      nextnodes++;
      q.push(v);
      vis[v] = 1;
    }
    currnodes--;
    if (currnodes == 0) {
      currnodes = nextnodes;
      nextnodes = 0;
      moves++;
    }
  }
  return -1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  int d = bfs(1, n);
  cout << d-1 << endl;
  return 0;
}
