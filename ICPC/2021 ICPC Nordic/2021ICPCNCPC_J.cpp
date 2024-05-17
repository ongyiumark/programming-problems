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

struct point {
  ll x, y;
};

istream &operator>>(istream &is, point &p) {
  is >> p.x >> p.y;
  return is;
}

ld dist(point &a, point &b) {
  ll dx = a.x-b.x;
  ll dy = a.y-b.y;
  return sqrtl(dx*dx+dy*dy);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  point a, b, c, d; cin >> a >> b >> c >> d;

  cout << setprecision(12) << fixed << max(dist(a,b), dist(c,d)) << endl;
  return 0;
}
