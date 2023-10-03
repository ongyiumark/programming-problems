#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

bool solve(vector<int> &cols, vector<string> &grid, int h, int w) {
  queue<int> qi, qj;
  qi.push(0); qj.push(0);
  bool res = false;
  while(!qi.empty()) {
    int ci = qi.front(); int cj = qj.front();
    qi.pop(); qj.pop();
    if (cj >= w) break;

    int idx = -1;
    while (cols[cj] > ci) {
      cols[cj]--;
      if (idx == -1 && grid[cols[cj]][cj] == 'C') {
        res = true;
        idx = cols[cj];
      }
    }

    if (idx == -1) {
      qi.push(ci);
      qj.push(cj+1);
    }
    else {
      qi.push(idx);
      qj.push(cj);
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int h, w; cin >> h >> w;
  vector<string> grid(h);
  for (string &s : grid) cin >> s;

  vector<int> cols(w, h);

  int ans = 0;
  while(solve(cols, grid, h, w)) ans++;
  cout << ans << "\n";
  return 0;
}