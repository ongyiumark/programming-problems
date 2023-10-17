#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 35;
vector<vector<int>> grid(N, vector<int>(N, 0));
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
string com[] = {"left", "right", "down", "up"};

pair<int,int> find_path(pair<int,int> s, pair<int,int> t, bool ignore=false) {
  vector<vector<bool>> vis(N, vector<bool>(N));
  vector<vector<int>> par(N, vector<int>(N));
  queue<pair<int,int>> q;
  auto [sx, sy] = s;
  q.push(s);
  vis[sx][sy] = 1;
  
  while(!q.empty()) {
    auto [cx, cy] = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int x = cx + dx[i];
      int y = cy + dy[i];
      if (x < 0 || x >= N || y < 0 || y >= N) continue;
      if (vis[x][y]) continue;
      if (!ignore && grid[x][y]) continue;

      vis[x][y] = 1;
      q.push({x,y});
      par[x][y] = (i^1);
    }
  }

  vector<string> res;
  auto [tx, ty] = t;
  while (!((tx == sx) && (ty == sy))) {
    int i = par[tx][ty];
    res.push_back(com[i^1]);
    tx = tx+dx[i];
    ty = ty+dy[i];
  }

  reverse(res.begin(), res.end());
  for (string &s : res) cout << s << "\n";
  return t;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  int x0, y0, xt, yt; cin >> x0 >> y0 >> xt >> yt;

  // move outside the grid
  for (int i = 0; i < x0+1; i++) cout << "left\n"; // x = -1
  cout << "up\n"; 
  for (int i = 0; i < x0+1; i++) cout << "left\n"; 
  cout << "down\n";
  for (int i = 0; i < x0+1; i++) cout << "right\n"; // return displaced

  // move to lower left
  for (int i = 0; i < y0; i++) cout << "down\n"; // x = -1, y = 0

  // clear the depot row
  for (int i = 0; i < yt; i++) cout << "up\n";
  for (int i = 0; i < 32; i++) cout << "right\n";
  cout << "up\n";
  for (int i = 0; i < 32; i++) cout << "right\n";
  cout << "down\n";
  for (int i = 0; i < 32; i++) cout << "left\n";
  for (int i = 0; i < 32; i++) cout << "left\n";
  for (int i = 0; i < yt; i++) cout << "down\n";

  // snake going up
  for (int k = 0; k < yt; k++) {
    for (int i = 0; i < 31*(k+1); i++) cout << (k%2 == 0 ? "right\n" : "left\n"); 
    for (int i = 0; i < 31*(k+1); i++) {
      cout << "down\n";
      cout << (k%2 == 0 ? "right\n" : "left\n");
      cout << "up\n";
    }
    cout << (k%2 == 0 ? "right\n" : "left\n");
    cout << "up\n";
  } 
  for (int i = 0; i < 31*(yt+1); i++) cout << (yt%2 == 0 ? "right\n" : "left\n"); 
  if (yt%2 == 0) for (int i = 0; i < 31; i++) cout << "left\n";
  else cout << "left\n";

  // go to top left
  for (int i = 0; i < 30-yt; i++) cout << "up\n";

  // snake going down
  for (int k = 0; k < 30-yt; k++) {
    for (int i = 0; i < 31*(k+1); i++) cout << (k%2 == 0 ? "right\n" : "left\n"); 
    for (int i = 0; i < 31*(k+1); i++) {
      cout << "up\n";
      cout << (k%2 == 0 ? "right\n" : "left\n");
      cout << "down\n";
    }
    cout << (k%2 == 0 ? "right\n" : "left\n");
    cout << "down\n";
  }
  for (int i = 0; i < 31*(30-yt+1); i++) cout << ((30-yt)%2 == 0 ? "right\n" : "left\n"); 


  return 0;
}