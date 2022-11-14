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

const ld EPS = 1e-9;
struct circ {
  ld x, y, r, s;
  bool alive;

  circ() : alive(1) {}

  void merge (vector<circ*>& others) {
    ld nx, ny, nr, ns;
    int n = others.size();
    nx = x; ny = y; nr = r*r; ns = s;
    for (int i = 0; i < n; i++) {
      nx += others[i]->x;
      ny += others[i]->y;
      nr += others[i]->r*others[i]->r;
      ns = max(ns, others[i]->s);
      others[i]->alive = 0;
    }

    x = nx/(n+1);
    y = ny/(n+1);
    r = sqrtl(nr);
    s = ns;
  }

  bool check(circ &other) {
    ld dx = x-other.x;
    ld dy = y-other.y;
    bool res = sqrtl(dx*dx + dy*dy)+EPS < (r+other.r);
    return res;
  }

  ld get_time(const circ& other) {
    ld dx = x-other.x;
    ld dy = y-other.y;
    ld d = sqrtl(dx*dx+dy*dy);
    return (d-r-other.r)/(s+other.s);
  }
};

istream& operator>>(istream &is, circ &circ) {
  is >> circ.x >> circ.y >> circ.r >> circ.s;
  return is;
}

ostream& operator<<(ostream &os, circ &circ) {
  os << " " << circ.x << " " << circ.y << " " << circ.r << " " << circ.s;
  return os;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;  
  vector<circ> c(n);
  for (int i = 0; i < n; i++) cin >> c[i];
  cout << setprecision(10) << fixed;
  
  ld total = 0;
  int alive = n;
  while(alive > 1) {
    ld best = 2e10;
    int a, b;
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        if (c[i].alive == 0 || c[j].alive == 0) continue;
        ld time = c[i].get_time(c[j]);
        if (best > time) {
          best = time;
          a = i;
          b = j;
        }
      }
    }

    for (int i = 0; i < n; i++) {
      c[i].r += (c[i].s)*best+EPS;
    }
    
    while(true) {
      vector<circ*> to_merge;
      for (int i = 0; i < n; i++) {
        if (c[i].alive == 0) continue;
        if (i == a) continue;
        if (c[a].check(c[i])) {
          to_merge.push_back(&c[i]);
        }
      }
      if (to_merge.size() > 0) {
        c[a].merge(to_merge);
        alive -= to_merge.size();
      }
      else break;
    }
  }

  int idx = 0;
  for (int i = 0; i < n; i++) {
    if (c[i].alive) idx = i;
  }
  cout << c[idx].x << " " << c[idx].y << endl; 
  cout << c[idx].r << endl;
  
  return 0;
}
