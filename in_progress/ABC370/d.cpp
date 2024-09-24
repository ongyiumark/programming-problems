#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
int main() {
  cin.tie(0)->sync_with_stdio(false);

  int h, w, q;
  cin >> h >> w >> q;
  vector<vector<bool>> grid(h, vector<bool>(w, true));

  vector<vector<ii>> up(h, vector<ii>(w)), down(h, vector<ii>(w)),
    left(h, vector<ii>(w)), right(h, vector<ii>(w));

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      up[i][j] = make_pair(i-1, j);
      down[i][j] = make_pair(i+1, j);
      left[i][j] = make_pair(i, j-1);
      right[i][j] = make_pair(i, j+1);
    }
  }

  auto is_valid = [&](int r, int c) {
    return (0 <= r && r < h && 0 <= c && c < w);
  };

  auto find = [&](vector<vector<ii>> &ar, int r, int c) {
    auto [pos_r, pos_c] = ar[r][c];
    while (is_valid(pos_r, pos_c) && !grid[pos_r][pos_c]) {
      auto [n_pos_r, n_pos_c] = ar[pos_r][pos_c];
      pos_r = n_pos_r;
      pos_c = n_pos_c;
    }
    ar[r][c] = make_pair(pos_r, pos_c);
    return ar[r][c];
  };

  auto destroy_wall = [&](int r, int c) {
    if (!is_valid(r, c)) return;
    grid[r][c] = false;

    auto [left_r, left_c] = find(left, r, c);
    auto [right_r, right_c] = find(right, r, c);
    auto [up_r, up_c] = find(up, r, c);
    auto [down_r, down_c] = find(down, r, c);

    if (is_valid(left_r, left_c))
      right[left_r][left_c] = make_pair(right_r, right_c);
    
    if (is_valid(right_r, right_c))
      left[right_r][right_c] = make_pair(left_r, left_c);
    
    if (is_valid(down_r, down_c))
      up[down_r][down_c] = make_pair(up_r, up_c);
  
    if (is_valid(up_r, up_c))
      down[up_r][up_c] = make_pair(down_r, down_c);
  };

  while(q--) {
    int r, c; cin >> r >> c;
    r--; c--;

    // has wall
    if (grid[r][c]) destroy_wall(r, c);
    else {
      auto [left_r, left_c] = find(left, r, c);
      auto [right_r, right_c] = find(right, r, c);
      auto [up_r, up_c] = find(up, r, c);
      auto [down_r, down_c] = find(down, r, c);

      destroy_wall(left_r, left_c);
      destroy_wall(down_r, down_c);
      destroy_wall(right_r, right_c);
      destroy_wall(up_r, up_c);
    }
  }
  
  int ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      ans += grid[i][j];
    }
  }
  cout << ans << "\n";

  return 0;
}