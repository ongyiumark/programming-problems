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

ld dist(pair<ld,ld> a, pair<ld,ld> b) {
  return sqrtl((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

void testcase() {
  ld x1, y1, x2, y2, xs, ys, xt, yt;
  cin >> x1 >> y1 >> x2 >> y2 >> xs >> ys >> xt >> yt;

  if (y1*x2 < y2*x1) {
    swap(x1, x2);
    swap(y1, y2);
  }

  vector<pair<ld,ld>> s;
  vector<pair<ld,ld>> t;

  s.push_back({xs, ys});
  t.push_back({xt, yt});

  // parallel
  //s.push_back({xs+x2, ys+y2});
  //t.push_back({xt+x2, yt+y2});

  // accross
  s.push_back({x1-(xs-x2), y1+(ys-y2)});
  t.push_back({x1-(xt-x2), y1+(yt-y2)});

  s.push_back({x2-(xs-x1), y2+(ys-y1)});
  t.push_back({x2-(xt-x1), y2+(yt-y1)});



  ld ans = 1e18;
  for (auto &a : s) {
    cout << a.first << " " << a.second << endl;
    ans = min(ans, dist(make_pair(xt, yt), a));
  }
  for (auto &b : t) {
    ans = min(ans, dist(make_pair(xs, ys), b));
  }

  cout << ans << "\n";

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(20) << fixed;
  int t; cin >> t;
  while(t--){
    testcase();
  }
  
  return 0;
}
