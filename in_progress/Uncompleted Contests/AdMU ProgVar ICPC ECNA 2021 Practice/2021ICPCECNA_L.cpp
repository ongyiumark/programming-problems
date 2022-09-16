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

void fliph(vector<vector<int>> &g) {
  int n = g.size();
  int m = g[0].size();
  for (int i = 0; i < n/2; i++) {
    swap(g[i],g[n-1-i]);
  }
}

void flipv(vector<vector<int>> &g) {
  int n = g.size();
  int m = g[0].size();
  for (int j = 0; j < m/2; j++) {
    for (int i = 0; i < n; i++) {
      swap(g[i][j],g[i][m-1-j]);
    }
  }
}

int solve(vector<vector<int>> &labels, vector<int> &ar, vector<vector<int>> &grid) {
  int n = labels.size();
  int m = labels[0].size();

  map<int,int> idx;
  int cnt[n+m-1];
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == -1) continue;
      idx[grid[i][j]] = labels[i][j];
      cnt[labels[i][j]]++;
    }
  }

  queue<int> q[n+m-1];
  int cidx = 0;
  for (int k = 0; k < n+m-1; k++) {
    for (int x = 0; x < cnt[k]; x++) {
      q[k].push(ar[cidx++]);
    }
  }

  map<int,int> nidx;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == -1) continue;
      nidx[q[labels[i][j]].front()] = labels[i][j];
      q[labels[i][j]].pop();
    }
  }

  int res = 0;
  for (int i = 0; i < ar.size(); i++) {
    res += (nidx[ar[i]] != idx[ar[i]]);
  }
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m; cin >> n >> m;
  vector<vector<int>> grid(n,vector<int>(m));

  vector<int> ar;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] != -1) ar.push_back(grid[i][j]);
    }
  }

  sort(ar.begin(), ar.end());

  vector<vector<int>> labels(n,vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      labels[i][j] = i+j;
    }
  }

  int ans = 1e9;
  ans = min(ans,solve(labels, ar, grid));

  fliph(labels);
  ans = min(ans,solve(labels, ar, grid));

  flipv(labels);
  ans = min(ans,solve(labels, ar, grid));

  fliph(labels);
  ans = min(ans,solve(labels, ar, grid));
  
  cout << ans << endl;

  return 0;
}
