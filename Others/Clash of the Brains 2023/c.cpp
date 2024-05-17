#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int di[] = {0,0,-1,1,1,1,-1,-1};
const int dj[] = {-1,1,0,0,1,-1,1,-1};
vector<vector<ii>> all_shapes;
set<ii> current_shape_set;
vector<ii> current_shape;

void generate(int d) {
  if (d == 6) {
    all_shapes.push_back(current_shape);
    return;
  }
  for (int dd = 0; dd < d; dd++) {
    auto [i, j] = current_shape[dd];
    for (int k = 0; k < 4; k++) {
      int x = i+di[k], y = j+dj[k];
      //if (x < 0 || y < 0) continue;
      if (current_shape_set.find({x,y}) != current_shape_set.end()) continue;
      current_shape_set.insert({x,y});
      current_shape.push_back({x,y});
      generate(d+1);
      current_shape.pop_back();
      current_shape_set.erase(current_shape_set.find({x,y}));
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  current_shape.push_back({0,0});
  current_shape_set.insert({0,0});
  generate(1);

  vector<set<vector<ii>>> shapes(6);
  for (int sz = 1; sz <= 6; sz++) {
    for (auto shape : all_shapes) {
      vector<ii> tmp;
      for (int i = 0; i < sz; i++) tmp.push_back(shape[i]);
      sort(tmp.begin(), tmp.end());
      shapes[sz-1].insert(tmp);
    }
  }

  int t; cin >> t;
  while (t--) {
    int w, h, d; cin >> w >> h >> d;
    if (w*h <= d) {
      cout << 0 << "\n";
      continue;
    }

    vector grid(h, vector(w, 'X'));
    auto print_grid = [&](){
      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          cout << grid[i][j];
        }
        cout << endl;
      }
      cout << endl;
    };


    auto valid = [&](vector<ii> &ar) -> bool {
      for (auto &[i,j] : ar) grid[i][j] = 'O';
 
      int cnt = 0;
      int si, sj;
      for (auto &[i,j] : ar) {
        for (int k = 0; k < 8; k++) {
          int x = i+di[k], y=j+dj[k];
          if (x < 0 || x >= h || y < 0 || y >= w) continue;
          if (grid[x][y] == 'O') continue;
          if (grid[x][y] == '.') continue;
          grid[x][y] = '.';
          si = x, sj = y;
          cnt++;
        }
      }
      queue<ii> q;
      q.push({si, sj});
      grid[si][sj] = 'X';
      while(!q.empty()) {
        auto [ci, cj] = q.front();
        q.pop();
        cnt--;
        for (int k = 0; k < 4; k++) {
          int x = ci+di[k], y=cj+dj[k];
          if (x < 0 || x >= h || y < 0 || y >= w) continue;
          if (grid[x][y] != '.') continue;
          q.push({x,y});
          grid[x][y] = 'X';
        } 
      }

      for (auto &[i,j] : ar) {
        for (int k = 0; k < 8; k++) {
          int x = i+di[k], y=j+dj[k];
          if (x < 0 || x >= h || y < 0 || y >= w) continue;
          if (grid[x][y] == 'O') continue;
          if (grid[x][y] == 'X') continue;
          grid[x][y] = 'X';
        }
      }
      for (auto &[i,j] : ar) grid[i][j] = 'X';
      return (cnt == 0);
    };


    int ans = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (i+d < h-1 && i-d > 0 && j+d < w-1 && j-d > 0) {
          ans += shapes[d-1].size();
          continue;
        }

        for (auto &shape : shapes[d-1]) {
          vector<ii> tmp;
          for (auto &[x,y] : shape) tmp.push_back({x+i, y+j});

          if (count_if(tmp.begin(), tmp.end(), [&](const ii &p) {
            auto &[x,y] = p;
            return (x < 0 || x >= h || y < 0 || y >= w);
          })) continue;
          // if (0 < i && i < h && 0 < j && j < w) {
          //   ans++;
          //   continue;
          // }
          
          if (valid(tmp)) ans++;
          else {
          // for (auto &[x,y] : tmp) grid[x][y] = 'O';
          // print_grid();
          // for (auto &[x,y] : tmp) grid[x][y] = 'X';
          }
          //cout << ans << endl;

        }
      }
    }
    cout << ans/d << endl;
  }

  return 0;
}