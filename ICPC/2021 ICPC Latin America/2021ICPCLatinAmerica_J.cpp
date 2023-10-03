#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct points {
  int x, y, id;
};

bool border(int x, int y, int h, int w) {
  return 0 == x || x == w || y == 0 || y == h;
}

int categorize(int x, int y, int h, int w) {
  if (y == h) return 0;
  if (x == w) return 1;
  if (y == 0) return 2;
  if (x == 0) return 3;
  return -1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  vector<points> trbl[4];

  int h, w; cin >> w >> h;
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    if (!border(x1, y1, h, w) || !border(x2, y2, h, w)) continue;

    int cat1 = categorize(x1, y1, h, w);
    int cat2 = categorize(x2, y2, h, w);

    trbl[cat1].push_back({x1, y1, i});
    trbl[cat2].push_back({x2, y2, i});
  }

  sort(trbl[0].begin(), trbl[0].end(), [](const points &left, const points &right) {
    return left.x < right.x;
  });
  sort(trbl[1].begin(), trbl[1].end(), [](const points &left, const points &right) {
    return left.y > right.y;
  });
  sort(trbl[2].begin(), trbl[2].end(), [](const points &left, const points &right) {
    return left.x > right.x;
  });
  sort(trbl[3].begin(), trbl[3].end(), [](const points &left, const points &right) {
    return left.y < right.y;
  });


  stack<int> current;
  vector<bool> vis(n);
  bool valid = true;
  for (int i = 0; i < 4 && valid; i++) {
    for (int j = 0; j < trbl[i].size() && valid; j++) {
      auto [x, y, id] = trbl[i][j];
      if (!vis[id]) {
        vis[id] = true;
        current.push(id);
        continue;
      }

      if (current.top() == id) current.pop();
      else valid = false;
    }
  }

  cout << (valid ? "Y" : "N") << "\n";
  return 0;
}
