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
    return (fabsl(x-other.x) < EPS) && (fabsl(y-other.y) < EPS);
  }
};

ld dist(const Point &a, const Point &b) {
  return hypotl(a.x-b.x, a.y-b.y);
}

const ld INF = 1e18;
ld closest_pair(vector<Point>& points) {
  points.erase(unique(points.begin(), points.end()), points.end());
  sort(points.begin(), points.end()); // sort by x

  vector<Point> y_sorted = points;  // sort by y
  sort(y_sorted.begin(), y_sorted.end(),
    [](const Point &left, const Point &right) {
      if (fabsl(left.y-right.y) > Point::EPS) 
        return left.y < right.y;
      return left.x < right.x;
    });
  
  function<ld(int, int, vector<Point>&)> solve = 
    [&](int l, int r, vector<Point>& ys) {
    if (l == r) return INF;

    int k = (l+r)/2;
    vector<Point> yleft(k-l+1), yright(r-k);
    int i = 0, j = 0;
    for (auto &p : ys) {
      if (points[k] < p) yright[i++] = p;
      else yleft[j++] = p;
    }
    
    ld d = min(solve(l, k, yleft), solve(k+1, r, yright));

    vector<Point> strip;
    int sz = ys.size();
    auto &[midx, midy] = points[k];
    for (int i = 0; i < sz; i++) {
      if (fabsl(midx-ys[i].x) < d) {
        strip.push_back(ys[i]);
      }
    }

    int strip_sz = strip.size();
    for (int i = 0; i < strip_sz; i++) {
      for (int j = i+1; j < strip_sz && (strip[j].y - strip[i].y) < d; j++) {
        d = min(d, dist(strip[i], strip[j]));
      }
    }

    return d;
  };
  int n = points.size();
  return solve(0, n-1, y_sorted);
}

struct planet {
  ll r, theta, t;
  planet(ll r, ll theta, ll t) : r(r), theta(theta), t(t) {}
  planet() : r(0), theta(0), t(0) {}
  bool operator<(const planet& other) const {
    return r < other.r;
  }
  Point to_point() const {
    ld x = r*cosl((ld)theta*M_PIl/180000);
    ld y = r*sinl((ld)theta*M_PIl/180000);
    return Point(x, y);
  }

  friend istream& operator>>(istream &is, planet &p);
};

istream& operator>>(istream &is, planet &p) {
  is >> p.r >> p.theta >> p.t;
  return is;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;
  vector<planet> planets(n);
  for (planet &p : planets) cin >> p;
  sort(planets.begin(), planets.end());

  ld ans = INF;
  vector<vector<Point>> planet_by_rev;
  planet_by_rev.push_back(vector(1, planets[0].to_point()));
  for (int i = 1; i < n; i++) {
    if (planets[i].t == planets[i-1].t) {
      auto &last = planet_by_rev.back();
      last.push_back(planets[i].to_point());
      continue;
    }
    ans = min(ans, (ld)planets[i].r-planets[i-1].r);
    planet_by_rev.push_back(vector(1, planets[i].to_point()));
  }

  for (auto &points : planet_by_rev) {
    if (points.size() == 1) continue;
    ans = min(ans, closest_pair(points));
  }
  cout << setprecision(20) << fixed;
  cout << (long double)ans << "\n";

  return 0;
}