/*
  We simply assign colors to vertices. 
  For each vertices, we need to count how many other vertices (of distance 2 away) have colors assigned.
  Vertices of distance 2 away are either grandparents (unique), parents (unique) or siblings.
  
  We do BFS to assign grandparents and parents first. Then, we simply count starting from 2 with the siblings.
  Edge case: Start counting from 1 if there is no grandparent (i.e. parent is root node) 
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

const ll MOD = 1e9+7;
const int N = 1e5+5;
int a[N], b[N];
vector<int> graph[N];
int num[N];
bool vis[N];

void bfs() {
  queue<int> q;
  q.push(0);
  memset(vis, 0, sizeof vis);

  vis[0] = 1;
  num[0] = 0;
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    int cnt = (num[u] == 0 ? 1 : 2);
    for (int v : graph[u]) {
      if (vis[v]) continue;
      num[v] = cnt++;
      vis[v] = 1;
      q.push(v);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k; cin >> n >> k;
  for (int i = 0; i < n-1; i++){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    graph[a[i]].push_back(b[i]);
    graph[b[i]].push_back(a[i]);
  }

  bfs();
  ll ans = 1;
  for (int i = 0; i < n; i++) {
    if (num[i] >= k) {
      cout << 0 << endl;
      return 0;
    }
    ans = ans*(k-num[i])%MOD;
  }
  cout << ans << endl;
  return 0;
}
