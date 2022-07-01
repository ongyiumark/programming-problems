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

const int N = 1e4;
int grid[N][N], moves[N][N];
short par[N][N];
bool vis[N][N];
vector<int> di = {0,1,0,-1};
vector<int> dj = {1,0,-1,0};

void bfs(int si, int sj, int n) {
  queue<int> qi, qj;
  qi.push(si);
  qj.push(sj);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      moves[i][j] = n*n;
      par[i][j] = -1;
      vis[i][j] = 0;
    }
  }
  par[si][sj] = 0;
  vis[si][sj] = 1;

  int currlayer = 1;
  int nextlayer = 0;
  int m = 0;

  while (!qi.empty()){
    int ci = qi.front();
    int cj = qj.front();
    qi.pop(); qj.pop();

    for (int d = 0; d < 4; d++) {
      int ni = ci+di[d];
      int nj = cj+dj[d];
      if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
      if (grid[ni][nj] > grid[ci][cj]) continue;
      if (vis[ni][nj]) continue;
      if (moves[ni][nj] < m+1) continue;
      vis[ni][nj] = 1;
      par[ni][nj] = (d+2)%4;
      qi.push(ni); qj.push(nj);
      nextlayer++;
      moves[ni][nj] = m+1;
    }

    currlayer--;
    if (currlayer==0){
      currlayer = nextlayer;
      nextlayer = 0;
      m++;
    }
  }
}

void testcase() {
  int n, k; cin >> n >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      grid[i][j] = -1;
    }
  }

  int cdir = 0;
  int cnt = 1;
  int ci = 0, cj = 0;
  while (cnt <= n*n){
    grid[ci][cj] = cnt;
    //cout << ci <<  " " << cj << " "  << grid[ci][cj] << endl;
    cnt++;
    int ni = ci+di[cdir];
    int nj = cj+dj[cdir];
    if (ni < 0 || ni >= n || nj < 0 || nj >= n) {
      cdir++;
      cdir%=4;
      ni = ci+di[cdir];
      nj = cj+dj[cdir];
    }
    else if (grid[ni][nj] != -1) {
      cdir++;
      cdir%=4;
      ni = ci+di[cdir];
      nj = cj+dj[cdir];
    }
    ci = ni;
    cj = nj;
  }
  if (k < n-1) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  if (k%2 == 1) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  bfs(n/2, n/2, n);
  /*
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << moves[i][j] << " ";
    }
    cout << endl;
  }
  */
  
  vector<int> ans;
  ci = 0; cj = 0;
  cdir = 0;
  while (moves[ci][cj] != k){
    int ni = ci+di[cdir];
    int nj = cj+dj[cdir];
    ans.push_back(grid[ci][cj]);
    if (ni < 0 || ni >= n || nj < 0 || nj >= n) {
      cdir++;
      cdir%=4;
      ni = ci+di[cdir];
      nj = cj+dj[cdir];
    }
    else if (grid[ni][nj] != grid[ci][cj]+1) {
      cdir++;
      cdir%=4;
      ni = ci+di[cdir];
      nj = cj+dj[cdir];
    }
    ci = ni;
    cj = nj;
    k--;
    //cout << "Moves: " << moves[ci][cj] << " " << k << endl;
  }
  
  ans.push_back(grid[ci][cj]);
  while(ans.back() != n*n) {
    int ni = ci + di[par[ci][cj]];
    int nj = cj + dj[par[ci][cj]];
    ci = ni; cj = nj;
    ans.push_back(grid[ci][cj]);
    //cout << ans.back() << endl;
  }

  int sz = ans.size();
  vector<pii> res;
  for (int i = 1; i < sz; i++) {
    if (ans[i] != ans[i-1]+1){
      res.push_back({ans[i-1], ans[i]});
    }
  }

  cout << res.size() << endl;
  for (auto p : res) {
    cout << p.first << " " << p.second << endl;
  }
  

  
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  for (int x = 1; x <= t; x++) {
    cout << "Case #" << x << ": ";
    testcase();
  }
  
  return 0;
}
