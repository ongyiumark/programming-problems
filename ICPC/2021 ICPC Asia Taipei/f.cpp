#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

struct Rect {
  int x1, y1, x2, y2;
  int c;

  Rect() {}
  friend istream& operator>>(istream &is, Rect &r);
};
istream& operator>>(istream &is, Rect &r) {
  is >> r.x1 >> r.y1 >> r.x2 >> r.y2 >> r.c;
  return is;
}

const int INF = 1e9;
struct SegmentTree {
  vector<int> st, lazy;
  int n;
  SegmentTree(int n) : n(n), st(4*n), lazy(4*n) {}
  void push(int p, int i, int j) {
    if (lazy[p] != 0) {
      st[p] = lazy[p];
      if (i != j) {
        lazy[p<<1] = lazy[p];
        lazy[p<<1|1] = lazy[p];
      }
      lazy[p] = 0;
    }
  }

  void update(int l, int r, int v) { update(l, r, v, 1, 0, n-1); }
  void update(int l, int r, int v, int p, int i, int j) {
    push(p, i, j);
    if (l <= i && j <= r) {
      lazy[p] = v;
      push(p, i, j);
    }
    else if (j < l || r < i) ;
    else {
      int k = (i+j)/2;
      update(l, r, v, p<<1, i, k);
      update(l, r, v, p<<1|1, k+1, j);
    }
  }

  int query(int x) { return query(x, 1, 0, n-1); }
  int query(int x, int p, int i, int j) {
    push(p, i, j);
    if (i == j) return st[p];
    
    int k = (i+j)/2;
    if (i <= x && x <= k) return query(x, p<<1, i, k);
    else return query(x, p<<1|1, k+1, j);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;
  vector<int> x_coords, y_coords;

  vector<Rect> rects(n);
  for (int i = 0; i < n; i++) {
    cin >> rects[i];
    x_coords.push_back(rects[i].x1);
    x_coords.push_back(rects[i].x2);
    y_coords.push_back(rects[i].y1);
    y_coords.push_back(rects[i].y2);
  }

  sort(x_coords.begin(), x_coords.end());
  sort(y_coords.begin(), y_coords.end());
  x_coords.erase(unique(x_coords.begin(), x_coords.end()), x_coords.end());
  y_coords.erase(unique(y_coords.begin(), y_coords.end()), y_coords.end());

  unordered_map<int,int> x_compress, y_compress;
  int x_sz = x_coords.size(), y_sz = y_coords.size();
  for (int i = 0; i < x_sz; i++) x_compress[x_coords[i]] = i;
  for (int i = 0; i < y_sz; i++) y_compress[y_coords[i]] = i;


  vector<vector<tuple<int,int,int,int>>> to_add(y_sz);
  for (int ii = 0; ii < n; ii++) {
    auto [x1, y1, x2, y2, c] = rects[ii];
    x1 = x_compress[x1];
    y1 = y_compress[y1];
    x2 = x_compress[x2];
    y2 = y_compress[y2];

    for (int i = min(y1,y2); i <= max(y1,y2)-1; i++) {
      to_add[i].push_back({min(x1,x2), -ii, max(x1,x2)-1, c});
    }
  }

  vector<int> colors(x_sz*y_sz);
  for (int i = 0; i < y_sz; i++) {
    auto &xs = to_add[i];
    sort(xs.begin(), xs.end());

    int sz = xs.size();
    if (sz == 0) continue;
    auto [x1, x2, c, z] = xs[i];
    for (int j = 1; j < sz; i++) {

    } 
  }

  sort(colors.begin(), colors.end());
  colors.erase(unique(colors.begin(), colors.end()), colors.end());
  cout << colors.size() - (colors[0] == 0) << "\n";
  return 0;
}