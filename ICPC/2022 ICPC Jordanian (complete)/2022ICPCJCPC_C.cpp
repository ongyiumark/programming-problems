#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> match, inv_match;
vector<bool> vis, reachable;
vector<vector<bool>> adj;

int aug(int L, int n) {
  if (vis[L]) return 0;
  vis[L] = 1;
  for (int R = 0; R < n; R++) {
    if (!adj[L][R]) continue;
    if ((match[R] == -1) || aug(match[R], n)) {
      inv_match[L] = R;
      match[R] = L;
      return 1;
    }
  }
  return 0;
}

void dfs(int R, int n, int i) {
  if (reachable[R]) return;
  reachable[R] = 1;
  for (int L = i+1; L < n; L++) {
    if (!adj[L][R]) continue;
    dfs(inv_match[L], n, i);
  }
}

int update(int R, int T, int n, int i) {
  if (vis[R]) return 0;
  vis[R] = 1;
  if (R == T) return 1;
  for (int L = i+1; L < n; L++) {
    if (!adj[L][R]) continue;
    if (update(inv_match[L], T, n, i)) {
      inv_match[L] = R;
      match[R] = L;
      return 1;
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ifstream cin("disney.in");
  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    adj.assign(n, vector<bool>(n, true));
    for (int i = 0; i < m; i++) {
      int x, y; cin >> x >> y;
      x--; y--;
      adj[x][y] = false;
    }
    match.assign(n, -1);
    inv_match.assign(n, -1);

    int mcbm = 0;
    for (int L = 0; L < n; L++) {
      vis.assign(n, 0);
      mcbm += aug(L, n);
    } 

    if (mcbm < n) {
      cout << -1 << "\n";
      continue;
    }

    for (int L = 0; L < n; L++) {
      reachable.assign(n, 0);
      dfs(inv_match[L], n, L);
      for (int i = 0; i < n; i++) {
        if (reachable[i] && match[i] >= L && adj[L][i]) {
          vis.assign(n, 0);
          update(inv_match[L], i, n, L);

          inv_match[L] = i;
          match[i] = L;
          break;
        }
      }
    }

    for (int L = 0; L < n; L++) {
      cout << inv_match[L]+1;
      cout << (L+1 < n ? " " : "\n");
    }
  }

  return 0;
}