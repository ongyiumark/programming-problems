/*
  Sort the blue points by x.
  Out of all the red points that can be paired with our current point,
  we always choose the red point with the highest y-value.

  This maximizes the number of pairs.
*/
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

struct point{
  int x, y, type;

  bool operator<(const point& other) const {
    return x < other.x;
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  vector<point> points;
  for (int i = 0; i < n; i++){
    int x, y; cin >> x >> y;
    points.push_back({x,y,1});
  }
  for (int i = 0; i < n; i++){
    int x, y; cin >> x >> y;
    points.push_back({x,y,2});
  }

  sort(points.begin(), points.end());
  bool ys[2*n];
  memset(ys, 0, sizeof ys);
  int cnt = 0;
  for (point &p : points){
    if (p.type == 1) ys[p.y] = 1;
    else {
      for (int i = p.y-1; i >= 0; i--){
        if (ys[i]){
          ys[i] = 0;
          cnt++;
          break;
        }
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
