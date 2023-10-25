#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const ll INF = 1e18;
struct point {
  ll x, y;
  point() : x(0), y(0) {}
  point(int _x, int _y) : x(_x), y(_y) {}

  bool operator<(const point &other) const {
    if (x == other.x) return y < other.y;
    return x < other.x;
  }
  bool operator==(const point &other) const {
    return (x == other.x) && (y == other.y);
  }
};

struct segment {
  point a, b;
  segment() : a(point()), b(point()) {}
  segment(point _a, point _b) {
    if (_b < _a) swap(_a, _b);
    a = _a; b = _b;
  }
  bool operator<(const segment &other) const {
    if (a == other.a) return b < other.b;
    return a < other.a;
  }

  friend istream& operator>>(istream &is, point &p);
};

ll cross(point a, point b) {
  return a.x*b.y - a.y*b.x;
}
struct triangle {
  point a, b, c;
  triangle() : a(point()), b(point()), c(point()) {}
  triangle(point _a, point _b, point _c) : a(_a), b(_b), c(_c) {}
  auto get_segments() {
    return tuple(segment(a, b), segment(b, c), segment(c, a));
  }
  auto get_twice_area() {
    ll total = cross(a, b) + cross(b, c) + cross(c, a);
    total = abs(total);
    return total;
  }
  friend istream& operator>>(istream& is, triangle &tri);
};

istream& operator>>(istream& is, point &p) {
  is >> p.x >> p.y;
  return is;
} 

istream& operator>>(istream& is, triangle &tri) {
  is >> tri.a >> tri.b >> tri.c;
  return is;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;

  vector<triangle> tris(n);
  for (int i = 0; i < n; i++) cin >> tris[i];
  map<segment, vector<int>> triangle_by_segment;
  for (int i = 0; i < n; i++) {
    auto [ab, bc, ca] = tris[i].get_segments();
    triangle_by_segment[ab].push_back(i);
    triangle_by_segment[bc].push_back(i);
    triangle_by_segment[ca].push_back(i);
  }

  vector adj(n, vector<int>());
  vector degree(n, 0);
  for (auto [segment, triangles] : triangle_by_segment) {
    int sz = triangles.size();
    if (sz == 1) continue;
    int u = triangles[0], v = triangles[1];
    degree[u]++; degree[v]++;
  }

  for (auto [segment, triangles] : triangle_by_segment) {
    int sz = triangles.size();
    if (sz == 1) continue;
    int u = triangles[0], v = triangles[1];
    if (degree[u] < 3 || degree[v] < 3) continue;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  vector memo(n, vector<ll>(2, -1));
  function<ll(int, bool, int)> solve = [&](int u, bool included, int p) {
    ll &ans = memo[u][included];
    if (ans != -1) return ans;
    if (!included) {
      ans = 0;
      for (int v : adj[u]) {
        if (v == p) continue;
        ans += solve(v, true, u);
      }
    }
    else {
      ans = tris[u].get_twice_area();
      int sz = adj[u].size();
      ll r_ans = INF;
      for (int mask = 0; mask < (1<<sz); mask++) {
        ll tmp = 0;
        for (int j = 0; j < sz; j++) {
          bool bit = (mask>>j)&1;
          int v = adj[u][j];
          if (v == p) continue;
          tmp += solve(v, bit, u);
        }
        r_ans = min(r_ans, tmp);
      }
      ans += r_ans;
    }
    return ans;
  };

  ll total = 0;
  for (int i = 0; i < n; i++) {
    if (degree[i] < 3) total += tris[i].get_twice_area();
  }
  for (int i = 0; i < n; i++) {
    if (degree[i] < 3) continue;
    if (memo[i][0] != -1) continue;
    total += min(solve(i, 0, -1), solve(i, 1, -1));
  }

  function<string(ll)> half = [&](ll x) {
    ostringstream os;
    os << x/2 << "." << (x%2 ? '5' : '0');
    return os.str();
  };
  cout << half(total) << "\n";

  return 0;
}