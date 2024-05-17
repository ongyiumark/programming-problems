#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

struct Point {
  static inline ld EPS = 1e-9;
  ld x, y;
  Point(ld x, ld y) : x(x), y(y) {}
  Point() : x(0), y(0) {}
  bool operator<(const Point& other) const {
    if (fabsl(x-other.x) > EPS) return x < other.x;
    return y < other.y;
  }
  bool operator==(const Point& other) const {
    return (fabsl(x-other.x) < EPS) 
      && (fabsl(y-other.y) < EPS);
  }
};

struct Vec {
  ld x, y;
  Vec(ld x, ld y) : x(x), y(y) {}
  Vec(const Point &a) : x(a.x), y(a.y) {}
  Vec(const Point &a, const Point &b) {
    x = b.x-a.x;
    y = b.y-a.y;
  }
  Vec scale(ld s) { return Vec(x*s, y*s); }
  ld norm_sq() { return x*x + y*y; }
};

Point translate(const Point &p, const Vec &v) {
  return Point(p.x+v.x, p.y+v.y);
}

ld dot(const Vec &a, const Vec& b) { return a.x*b.x + a.y*b.y; }
ld cross(const Vec &a, const Vec &b) { return a.x*b.y - a.y*b.x; }

Point get_centroid(vector<Point>& points) {
  int n = points.size();
  ld x = 0, y = 0;

  ld z = 0;
  for (int i = 0; i < n; i++) {
    ld cp = cross(Vec(points[i]), Vec(points[(i+1)%n]));
    x += (points[i].x + points[(i+1)%n].x)*cp;
    y += (points[i].y + points[(i+1)%n].y)*cp;
    z += cp;
  }
  ld six_area = z*3;
  return Point(x/six_area, y/six_area);
}

ld angle(Point &a, Point &o, Point &b) {
  Vec oa(o, a), ob(o, b);
  return acosl(dot(oa, ob)/
    sqrtl(oa.norm_sq()*ob.norm_sq()));  
}

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n; cin >> n;
  vector<Point> points(n);
  for (int i = 0; i < n; i++) {
    ll x, y; cin >> x >> y;
    points[i] = Point(x, y);
  }

  Point centroid = get_centroid(points);
  vector<int> roll_edge(n);
  for (int i = 0; i < n; i++) {
    Point &cur = points[i];
    Point &nxt = points[(i+1)%n];
    
    ld l2_edge = dot(Vec(cur,nxt), Vec(cur,nxt));
    if (dot(Vec(cur, centroid), Vec(cur, nxt)) > l2_edge) roll_edge[i] = (i+1)%n;
    else if (dot(Vec(nxt, centroid), Vec(nxt, cur)) > l2_edge) roll_edge[i] = (i-1+n)%n;
    else roll_edge[i] = i;
  }

  function<int(int)> find_edge = [&](int x) {
    if (roll_edge[x] == x) return x;
    return roll_edge[x] = find_edge(roll_edge[x]);
  };

  vector<ld> ans(n);
  for (int i = 0; i < n; i++) {
    int j = find_edge(i);
    
    ld ang = angle(points[i], centroid, points[(i+1)%n]);
    ans[j] += ang/(2*M_PIl);
  }

  cout << setprecision(20) << fixed;
  for (int i = 0; i < n; i++) {
    cout << ans[i] << "\n";
  }
}