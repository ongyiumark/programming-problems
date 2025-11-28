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

struct Rect {
  ll xl, xh, yl, yh;

  Rect move(char c, ll b) {
    if (c == 'X') return {xl, xh, yl+b, yh+b};
    if (c == 'Y') return {xl+b, xh+b, yl, yh};
    return Rect();
  }

  pair<Rect, Rect> split(char c, ll a) {
    if (c == 'X' && xl < a && a <= xh) {
      return {{xl, a-1, yl, yh},{a, xh, yl, yh}};
    }
    if (c == 'Y' && yl < a && a <= yh) {
      return {{xl, xh, yl, a-1},{xl, xh, a, yh}};
    }
    return {Rect(), Rect()};
  }

  ll get_low(char c) {
    if (c == 'X') return xl;
    if (c == 'Y') return yl;
    return 0;
  }
  ll get_high(char c) {
    if (c == 'X') return xh;
    if (c == 'Y') return yh;
    return 0;
  }

  ll area() {
    return (xh-xl+1)*(yh-yl+1);
  }
};

struct UnionFind {
  vector<int> p;
  UnionFind(int n) : p(n, -1) {}

  int find(int x) { 
    return p[x] < 0 ? x : p[x] = find(p[x]); }
  bool is_same(int a, int b) { return find(a) == find(b); }
  int size(int a) { return -p[find(a)]; }

  bool unite(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return false;
    if (p[a] > p[b]) swap(a, b);
    p[a] += p[b]; p[b] = a;
    return true;
  }
};

bool is_touching(Rect &r1, Rect &r2) {
  bool x_overlap = (r1.xh+1 > r2.xl)&&(r2.xh+1 > r1.xl);
  bool x_touch = (r1.xh+1 >= r2.xl)&&(r2.xh+1 >= r1.xl);
  bool y_overlap = (r1.yh+1 > r2.yl)&&(r2.yh+1 > r1.yl);
  bool y_touch = (r1.yh+1 >= r2.yl)&&(r2.yh+1 >= r1.yl);
 
  return (x_touch&&y_overlap)||(y_touch&&x_overlap);
}

int main(){
  cin.tie(0)->sync_with_stdio(false);
  int n; ll x, y; cin >> n >> x >> y;
  vector<char> c(n);
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i] >> a[i] >> b[i];
  }

  vector<Rect> rectangles;
  vector<Rect> prev_rect;

  rectangles.push_back({0, x-1, 0, y-1});

  for (int i = 0; i < n; i++) {
    prev_rect = rectangles;
    rectangles.clear();

    for (Rect &r : prev_rect) {
      if (r.get_high(c[i]) < a[i]) rectangles.push_back(r.move(c[i], -b[i]));
      else if (r.get_low(c[i]) >= a[i]) rectangles.push_back(r.move(c[i], b[i]));
      else {
        pair<Rect,Rect> p = r.split(c[i], a[i]);
        rectangles.push_back(p.first.move(c[i], -b[i]));
        rectangles.push_back(p.second.move(c[i], b[i]));
      }
    }
  }

  int sz = rectangles.size();
  UnionFind uf(sz);
  for (int i = 0; i < sz; i++) {
    for (int j = 0; j < i; j++) {
      if (is_touching(rectangles[i], rectangles[j])) {
        uf.unite(i, j);
      }
    }
  }

  vector<ll> areas(sz);
  vector<int> pars;
  vector<ll> result;
  for (int i = 0; i < sz; i++) {
    areas[uf.find(i)] += rectangles[i].area();
    if (uf.p[i] < 0) pars.push_back(i);
  }
  for (int &p : pars) result.push_back(areas[p]);
  sort(result.begin(), result.end());
  cout << result.size() << "\n";
  for (int i = 0; i < (int)result.size(); i++) {
    cout << result[i] << " \n"[i+1>=(int)result.size()];
  }
  
  return 0;
}
