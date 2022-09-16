#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5+5;
ll l[N], f[N];
stack<string> ans;

struct query {
  char type;
  ll t, l, f;
  int i;
  query() {}
  query(ll t, ll l, ll f) : t(t), l(l), f(f), type('c'), i(-1) {}
  query(int i) : t(-1), l(-1), f(-1), type('q'), i(i) {}
};

query queries[N];
bool quit[N];

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
  return a/gcd(a,b)*b;
}

struct point {
  ll x, y, t;
  
  bool operator<(const point &other) const {
    if (x*other.t == other.x*t) return y*other.t < other.y*t;
    return x*other.t < other.x*t;
  }

  bool operator==(const point &other) const {
    return x*other.t == other.x*t && y*other.t == other.y*t;
  }

  void reduce() {
    ll g = gcd(t,gcd(abs(x),abs(y)));
    x /= g; y /= g; t /= g;
  }

  point operator-(const point &other) const {
    ll L = lcm(t, other.t);
    point res = {L/t*x-L/other.t*other.x, L/t*y-L/other.t*other.y, L};
    res.reduce();
    return res;
  }
};

ll cross(const point &a, const point &b) {
  return a.x*b.y - a.y*b.x;
}

struct conhull {
  set<point> hull;
  conhull() {
    set<point>().swap(hull);
  }

  void add(point p) {
    int n = hull.size();
    if (n == 0) {
      hull.insert(p);
      return;
    }

    // No need to add if point is inside.
    if (inside(p)) return;

    auto it = hull.lower_bound(p);
    // Remove points below p.
    while (it != hull.begin() && prev(it)->y <= p.y) hull.erase(prev(it));

    // Remove points from the left
    while (it != hull.begin() && prev(it) != hull.begin() && cross(p-*prev(prev(it)), *prev(it)-*prev(prev(it))) <= 0) {
      hull.erase(prev(it));
    }

    // Remove points from the right
    while (it != hull.end() && next(it) != hull.end() && cross(*next(it)-p, *it-p) <= 0){
      auto nxtit = next(it);
      hull.erase(it);
      it = nxtit;
    }

    hull.insert(p);
  }

  bool inside(point p) {
    int n = hull.size();
    if (n == 0) return false;

    auto it = hull.lower_bound(p);
    if (it == hull.end()) return false;

    if (it == hull.begin()) {
      point tmp = *it;
      return p.t*tmp.y >= p.y*tmp.t;
    }

    point right = *it;
    point left = *(--it);

    ll val = cross(right-left, p-left);
    return val <= 0;
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> l[i] >> f[i];
  int e; cin >> e;

  memset(quit, 0, sizeof quit);
  for (int i = 0; i < e; i++) {
    char type; cin >> type;
    if (type == 'c') {
      ll t, l, f; cin >> t >> l >> f;
      queries[i] = query(t,l,f);
    }
    else {
      int x; cin >> x; x--;
      queries[i] = query(x);
      quit[x] = 1;
    }
  }

  // Build convex hull
  conhull ch;
  for (int i = 0; i < n; i++) {
    if (quit[i]) continue;
    ch.add({l[i], f[i], 1});
  }

  for (int i = e-1; i >= 0; i--) {
    if (queries[i].type == 'c') 
      ans.push((ch.inside({queries[i].l, queries[i].f, queries[i].t}) ? "no" : "yes"));
    else 
      ch.add({l[queries[i].i], f[queries[i].i], 1});
  }

  while (!ans.empty()) {
    cout << ans.top() << endl;
    ans.pop();
  }
  
  return 0;
}
