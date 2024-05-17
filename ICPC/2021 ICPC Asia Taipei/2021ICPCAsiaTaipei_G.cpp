#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

vector<vector<int>> grid;
vector<int> k;
vector<vector<ii>> patrol;
vector<vector<vector<bool>>> state;
vector<vector<vector<int>>> memo;

void testcase() {
  int n, m; cin >> n >> m;
  grid.assign(m, vector(n, 0));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }
  int xs, ys; cin >> xs >> ys;
  int g; cin >> g;
  k.assign(g, 0);
  patrol.assign(g, vector<ii>());
  for (int i = 0; i < g; i++) {
    cin >> k[i];
    patrol[i].resize(k[i]);
    for (int j = 0; j < k[i]; j++) {
      int x, y; cin >> x >> y;
      patrol[i][j] = {x,y};
    }
  }
  function<int(int,int)> gcd = [&](int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
  };
  auto lcm = [&](int a, int b) { return a/gcd(a,b)*b; };
  int L = 1;
  for (int i = 0; i < g; i++) L = lcm(L, k[i]);

  memo.assign(L, vector(n, vector(m, -1)));
  auto has_guard = [&](int t, int x, int y) {
    int &ret = memo[t][x][y];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < g; i++) {
      auto [gx, gy] = patrol[i][t%k[i]];
      if (x == gx && y == gy) ret = 1;
    }
    return ret;
  };

  state.assign(L, vector(n, vector(m, false)));
  queue<tuple<int,int,int>> q;
  q.push({0, xs, ys});
  state[0][xs][ys] = 1;
  int moves = 0;
  int next_layer = 0;
  int current_layer = 1;

  int di[] = {0,0,-1,1,0};
  int dj[] = {-1,1,0,0,0};
  while (!q.empty()) {
    auto [ct, cx, cy] = q.front();
    q.pop();
    if (grid[cy][cx] == 0) {
      cout << moves << "\n";
      return;
    } 

    int c_alt = grid[cy][cx];
    for (int kk = 0; kk < 5; kk++) {
      int nx = cx + di[kk];
      int ny = cy + dj[kk];
      int nt = (ct + 1)%L;

      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (state[nt][nx][ny]) continue;
      if (has_guard(ct,nx,ny) || has_guard(nt,nx,ny)) continue;
      if (grid[ny][nx] > c_alt) continue;

      state[nt][nx][ny] = true;
      q.push({nt,nx,ny});
      next_layer++;
    }

    current_layer--;
    if (current_layer == 0) {
      moves++;
      current_layer = next_layer;
      next_layer = 0;
    }
  }

  cout << -1 << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  while(n--) testcase();

  return 0;
}