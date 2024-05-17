#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct Point {
  int x, y;
  char align;
  Point(int x, int y) : x(x), y(y) {}
  Point(int x, int y, char align) : x(x), y(y), align(align) {}
  Point rotate() const {
    return Point(x+y, x-y, align);
  }
  Point reverse() const {
    return Point((x+y)/2, (x-y)/2, align);
  }
};

vector<Point> get_between(Point &a, Point &b) {
  vector<Point> ret;
  if (a.x != b.x && a.y != b.y) return ret;
  if (a.x == b.x) {
    for (int i = min(a.y,b.y); i <= max(a.y,b.y); i++) {
      ret.push_back(Point(a.x, i));
    }
  }
  if (a.y == b.y) {
    for (int i = min(a.x,b.x); i <= max(a.x,b.x); i++) {
      ret.push_back(Point(i,a.y));
    }
  }
  return ret;
}

const int N = 1e6+2;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m; cin >> n >> m;
  vector<Point> poly;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    poly.push_back(Point(x,y));
  }
  int xs, ys; cin >> xs >> ys;
  Point s(xs, ys);

  vector<Point> rboundary;
  for (int i = 0; i < n; i++) {
    Point a = poly[i], b = poly[(i+1)%n];
    for (Point &p : get_between(a, b)) {
      Point pp = Point(p.x, p.y, (a.x == b.x) ? 'H' : 'V');
      rboundary.push_back(pp.rotate());
    }
  }
  vector xPoints(2*N, vector<pair<int,char>>());
  vector yPoints(2*N, vector<pair<int,char>>());
  for (Point &p : rboundary) {
    xPoints[p.x+N].push_back({p.y, p.align});
    yPoints[p.y+N].push_back({p.x, p.align});
  }
  for (int i = 0; i < 2*N; i++) {
    sort(xPoints[i].begin(), xPoints[i].end());
    sort(yPoints[i].begin(), yPoints[i].end());
  }

  auto find_point_higher = [](vector<pair<int,char>> &ar, int x) {
    int n = ar.size();
    int lo = 0;
    int hi = n-1;
    int ans = -1;
    while (lo <= hi) {
      int mid = hi - (hi-lo)/2;
      if (ar[mid].first > x) {
        ans = mid;
        hi = mid-1;
      }
      else lo = mid+1;
    }
    return ar[ans];
  };
  auto find_point_lower = [](vector<pair<int,char>> &ar, int x) {
    int n = ar.size();
    int lo = 0;
    int hi = n-1;
    int ans = -1;
    while (lo <= hi) {
      int mid = hi - (hi-lo)/2;
      if (ar[mid].first < x) {
        ans = mid;
        lo = mid+1;
      }
      else hi = mid-1;
    }
    return ar[ans];
  };

  vector<Point> ans;
  Point curr = s.rotate();
  int d = 0;
  
  for (int i = 0; i < m; i++) {
    pair<int, char> x, y;
    switch (d) {
      case 0: 
        x = find_point_higher(yPoints[curr.y+N], curr.x);
        curr = Point(x.first, curr.y);
        if (x.second == 'H') d = (d+1)%4;
        else d = (d-1+4)%4;
        break;
      case 1:
        y = find_point_lower(xPoints[curr.x+N], curr.y);
        curr = Point(curr.x, y.first);
        if (y.second == 'V') d = (d+1)%4;
        else d = (d-1+4)%4;
        break;
      case 2:
        x = find_point_lower(yPoints[curr.y+N], curr.x);
        curr = Point(x.first, curr.y);
        if (x.second == 'H') d = (d+1)%4;
        else d = (d-1+4)%4;
        break;
      case 3:
        y = find_point_higher(xPoints[curr.x+N], curr.y);
        curr = Point(curr.x, y.first);
        if (y.second == 'V') d = (d+1)%4;
        else d = (d-1+4)%4;
        break;
    }
    ans.push_back(curr.reverse());
  }

  for (auto p : ans) {
    cout << p.x << " " << p.y << "\n";
  }
  return 0;
}