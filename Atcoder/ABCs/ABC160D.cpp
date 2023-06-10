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

const int INF = 1e9;
void bfs(int s, int x, int y, vector<int> &ans) {
  int n = ans.size();
  queue<int> q; q.push(s);
  vector<int> dist(n+1, INF);
  dist[s] = 0;
  while(q.size()) {
    int u = q.front();
    q.pop();

    if (u == x and dist[y] == INF) {
      dist[y] = dist[u]+1;
      q.push(y);
    }

    if (u == y and dist[x] == INF) {
      dist[x] = dist[u]+1;
      q.push(x);
    }

    if (u+1 <= n and dist[u+1] == INF) {
      dist[u+1] = dist[u]+1;
      q.push(u+1);
    }

    if (u-1 >= 1 and dist[u-1] == INF) {
      dist[u-1] = dist[u]+1;
      q.push(u-1);
    }
  }

  for (int r = s+1; r <= n; r++) {
    ans[dist[r]]++;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x, y; cin >> n >> x >> y;

  
  vector<int> ans(n);
  for (int l = 1; l <= n; l++) {
    bfs(l, x, y, ans);
  }

  for (int k = 1; k < n; k++) {
    cout << ans[k] << "\n";
  }

  return 0;
}
