#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long ld;

vector<string> commands = {"GOTO", "IF-OPEN", "FORWARD", "LEFT", "RIGHT"};
vector<string> grid, comm, ans;
int s, t;
int n, m;

int di[] = {1, 0, -1, 0};
int dj[] = {0, -1, 0, 1};

bool check() {
  int csz = comm.size();
  queue<tuple<int,int,int,int>> q;
  q.push({0, s, 0, 0});

  bool vis[n][m][4][csz];
  memset(vis, 0, sizeof vis);
  vis[0][s][0][0] = true;

  while(!q.empty()) {
    auto [ci, cj, k, pc] = q.front();
    q.pop();
    if (ci == n-1 && cj == t) {
      ans = comm;
      return true;
    }

    if (comm[pc] == "FORWARD") {
      int ni = ci+di[k];
      int nj = cj+dj[k];
      int nk = k;
      int npc = (pc+1)%csz;

      if (ni < 0) ni = 0;
      if (ni >= n) ni = n-1;
      if (nj < 0) nj = 0;
      if (nj >= m) nj = m-1;
      if (grid[ni][nj] == '#') ni = ci, nj = cj;

      if (!vis[ni][nj][nk][npc]) {
        vis[ni][nj][nk][npc] = true;
        q.push({ni, nj, nk, npc});
      }
    }
    else if (comm[pc] == "RIGHT") {
      int nk = (k+1)%4;
      int npc = (pc+1)%csz;
      if (!vis[ci][cj][nk][npc]) {
        vis[ci][cj][nk][npc] = true;
        q.push({ci, cj, nk, npc});
      }
    }
    else if (comm[pc] == "LEFT") {
      int nk = (k-1)%4;
      if (nk < 0) nk += 4;
      int npc = (pc+1)%csz;
      if (!vis[ci][cj][nk][npc]) {
        vis[ci][cj][nk][npc] = true;
        q.push({ci, cj, nk, npc});
      }
    }
    else if (comm[pc][0] == 'G') {
      stringstream ss(comm[pc]);
      string tmp; int l;
      ss >> tmp >> l;

      int npc = l-1;
      if (!vis[ci][cj][k][npc]) {
        vis[ci][cj][k][npc] = true;
        q.push({ci, cj, k, npc});
      }
    }
    else {
      stringstream ss(comm[pc]);
      string tmp; int l;
      ss >> tmp >> l;

      int ni = ci+di[k];
      int nj = cj+dj[k];
      if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
        int npc = (pc+1)%csz;
        if (!vis[ci][cj][k][npc]) {
          vis[ci][cj][k][npc] = true;
          q.push({ci, cj, k, npc});
        }
      }
      else if (grid[ni][nj] == '#') {
        int npc = (pc+1)%csz;
        if (!vis[ci][cj][k][npc]) {
          vis[ci][cj][k][npc] = true;
          q.push({ci, cj, k, npc});
        }
      }
      else {
        int npc = l-1;
        if (!vis[ci][cj][k][npc]) {
          vis[ci][cj][k][npc] = true;
          q.push({ci, cj, k, npc});
        }
      }
    }

  }
  return false;
}

bool solve(int sz) {
  int csz = comm.size();
  if (csz == sz) return check();

  bool res = false;
  for (int i = 0; i < 5; i++) {
    string t = commands[i];
    if (i < 2) {
      for (int j = 1; j <= sz; j++) {
        comm.push_back(t + " " + to_string(j));
        res |= solve(sz);
        comm.pop_back();
      }
    }
    else {
      comm.push_back(t);
      res |= solve(sz);
      comm.pop_back();
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  grid.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'S') s = j;
      if (grid[i][j] == 'G') t = j; 
    }
  }  

  int sz = 1;
  while(!solve(sz)) sz++;
  
  cout << ans.size() << "\n";
  for (string &s : ans) cout << s << "\n";
  
  return 0;
}