#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const int N = 1001;
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};

int bfs(int si, int sj, vector<vector<bool>> &vis, vector<vector<vector<bool>>> &blocked) {
  queue<ii> q;
  q.push({si, sj});
  vis[si][sj] = true;

  int cnt = 0;
  while(!q.empty()) {
    auto [ci, cj] = q.front();
    q.pop();
    cnt++;

    for (int k = 0; k < 4; k++) {
      int ni = ci + di[k];
      int nj = cj + dj[k];
      if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
      if (vis[ni][nj] || blocked[ci][cj][k]) continue;
      q.push({ni, nj});
      vis[ni][nj] = true;
    }
  }

  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<vector<bool>> vis(N, vector<bool>(N));
  vector<vector<vector<bool>>> blocked(N, vector<vector<bool>>(N, vector<bool>(4)));

  int cx, cy; cin >> cx >> cy;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    if (cx == x) {
      int l = min(y, cy), r = max(y, cy);
      for (int j = l; j < r; j++) {
        blocked[cx-1][j][1] = true;
        blocked[cx][j][0] = true;
      }
    }
    else {
      int l = min(x, cx), r = max(x, cx);
      for (int j = l; j < r; j++) {
        blocked[j][cy-1][3] = true;
        blocked[j][cy][2] = true;
      }
    }
    cx = x;
    cy = y;
  }

  bfs(0, 0, vis, blocked);
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (vis[i][j]) continue;
      ans = max(ans, bfs(i, j, vis, blocked));
    }
  }
  cout << ans << "\n";
  return 0;
}