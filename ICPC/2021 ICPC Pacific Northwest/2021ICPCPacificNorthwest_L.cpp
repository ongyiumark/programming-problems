#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __float128 ld;
typedef pair<ll,ll> point;
typedef pair<ld,ld> pointd;

ostream& operator<<(ostream& os, ld x) { os << (long double)x; return os; }

ll cross(point a, point b) { return a.first*b.second - b.first*a.second; }
ld cross(pointd a, pointd b) { return a.first*b.second - b.first*a.second; }
pointd midpoint(pointd &a, pointd &b) { return {(a.first+b.first)/2, (a.second+b.second)/2}; } 

ld get_area(vector<point> &p, int k, pointd* ex) {
  ll partial_ans = 0;
  ld ans = 0;
  int n = k+1;
  for (int i = 0; i < n-1; i++) partial_ans += cross(p[i], p[i+1]);
  
  if (ex == nullptr) partial_ans += cross(p[n-1], p[0]);
  else ans += cross((pointd)p[n-1], *ex) + cross(*ex, (pointd)p[0]);

  return ans + partial_ans;
} 

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<point> p(n);
  for (auto &[x, y] : p) cin >> x >> y;

  ld total_area = get_area(p, n-1, nullptr);

  int lo = 1;
  int hi = n-1;
  int idx = -1;
  while (lo <= hi) {
    int mid = hi - (hi-lo)/2;
    if (2*get_area(p, mid, nullptr) <= total_area) {
      idx = mid;
      lo = mid+1;
    }
    else hi = mid-1;
  }

  pointd a = p[idx];
  pointd b = p[(idx+1)%n];

  int iter = 100;
  while(iter--) {
    pointd mp = midpoint(a, b);
    if (2*get_area(p, idx, &mp) <= total_area) a = mp;
    else b = mp;
  }

  cout << setprecision(15) << fixed;
  cout << a.first << " " << a.second << "\n";
  

  return 0;
}