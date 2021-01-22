/*
  O(n^4) works.
  Fix a left and right edge, then fix a top and bottom edge.
  However, we need to choose the top and bottom edges such that it includes the points on the left and right edge.

  An O(n^5) solution wouldve worked as well.
  In this solution, you can sort x and y separately, and simply count how many points are inside the rectangle.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 50;
pair<ll,ll> points[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k, n;
  cin >> n >> k;
  for (int i = 0; i < n; i++){
    int x, y; cin >> x >> y;
    points[i] = {x,y};
  }
  sort(points, points+n);

  ll ans = 9e18;
  for (int r = 0; r < n; r++){
    for (int l = 0; l < r; l++){
      if (r-l+1 < k) continue;
      vector<int> ys;
      for (int i = l; i <= r; i++){
        ys.push_back(points[i].second);
      }
      sort(ys.begin(), ys.end());
      int m = ys.size();
      for (int u = 0; u < m; u++){
        for (int d = 0; d < u; d++){
          if (u-d+1 < k) continue;
          if (ys[d] > min(points[l].second, points[r].second)) continue;
          if (ys[u] < max(points[l].second, points[r].second)) continue;
          ll curr = (ys[u]-ys[d])*(points[r].first-points[l].first);
          ans = min(curr, ans);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
