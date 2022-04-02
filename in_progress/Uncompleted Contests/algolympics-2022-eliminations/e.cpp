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

vector<vector<char>> grid1, grid2, ans;

void testcase(){
  int r, c; cin >> r >> c;
  grid1.resize(r);
  for (int i = 0; i < r; i++) {
    grid1[i].resize(c);
    for (int j = 0; j < c; j++) {
      cin >> grid1[i][j];
    }
  }

  grid2.resize(r);
  for (int i = 0; i < r; i++) {
    grid2[i].resize(c);
    for (int j = 0; j < c; j++) {
      cin >> grid2[i][j];
    }
  }

  ans.resize(r);
  for (int i = 0; i < r; i++) {
    ans[i].resize(c);
    for (int j = 0; j < c; j++) {
      if (grid1[i][j] == 'B') ans[i][j] = 'B';
      else if (grid2[i][j] == 'G') ans[i][j] = 'G';
      else ans[i][j] = 'R';
      cout << ans[i][j];
    }
    cout << endl;
  }

  /*
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << grid1[i][j];
    }
    cout << endl;
  }
  cout << endl;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << grid2[i][j];
    }
    cout << endl;
  }
  cout << endl;
  */
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    testcase();
    if (i != T-1) cout << endl;
  }
  return 0;
}
