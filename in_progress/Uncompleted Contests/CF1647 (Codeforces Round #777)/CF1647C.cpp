/*
  Color each black square one by one, going from bottom left to top right.
  Use 2x1 or 1x2 rectangles.

  It's impossible if (1,1) is black.
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

vector<vector<bool>> grid;

struct rect {
  int a, b, c, d;
};
void testcase(){
  int n, m; cin >> n >> m;
  grid.resize(n);
  for (int i = 0; i < n; i++){
    grid[i].resize(m);
    for (int j = 0; j < m; j++) {
      char c; cin >> c;
      grid[i][j] = (c == '1');
    }
  }

  if (grid[0][0])  {
    cout << -1 << endl;
    return;
  }

  vector<rect> ans;
  for (int i = n-1; i >= 0; i--) {
    for (int j = m-1; j >= 0; j--){
      if (grid[i][j]) {
        if (j > 0) ans.push_back({i+1, j, i+1, j+1});
        else ans.push_back({i, j+1, i+1, j+1});
      }
    }
  }
  cout << ans.size() << endl;
  for (rect r : ans) {
    cout << r.a << " " << r.b << " " << r.c << " " << r.d << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--){
    testcase();
  }
  return 0;
}
