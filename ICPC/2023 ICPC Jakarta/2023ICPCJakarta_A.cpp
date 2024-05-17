#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);

  vector<vector<char>> grid(3, vector<char>(3, '.'));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> grid[i][j];
    }
  }
  int di[] = {1,1,1,0,0,-1,-1,-1};
  int dj[] = {1,0,-1,1,-1,1,0,-1};

  vector<string> words;
  string tmp;
  function<void(int,int,int,int,int)> dfs = [&](int i, int j, int dep, int pi, int pj) {
    if (dep == 3) {
      words.emplace_back(tmp);
      return;
    }

    for (int k = 0; k < 8; k++) {
      int x = i+di[k];
      int y = j+dj[k];
      if (x < 0 || x >= 3 || y < 0 || y >= 3) continue;
      if (x == pi && y == pj) continue;
      tmp.push_back(grid[x][y]);
      dfs(x, y, dep+1, i, j);
      tmp.pop_back();
    }
  };

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      tmp.push_back(grid[i][j]);
      dfs(i, j, 1, -1, -1);
      tmp.pop_back();
    }
  }

  sort(words.begin(), words.end());
  cout << words[0] << "\n";
  return 0;
}