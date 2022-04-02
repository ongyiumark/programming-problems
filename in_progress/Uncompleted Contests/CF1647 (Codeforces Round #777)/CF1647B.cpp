/*
  Check every 2x2 square. Check if there are exactly three 1's.
  If there is at least one 2x2 square with exactly three 1's, then its not elegant.
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
  if (n == 1 || m == 1) {
    cout << "YES" << endl;
    return;
  }

  bool elegant = true;
  for (int i = 0; i < n-1; i++){
    for (int j = 0; j < m-1; j++) {
      int cnt = 0;
      for (int di = 0; di < 2; di++){
        for (int dj = 0; dj < 2; dj++){
          cnt += grid[i+di][j+dj];
        }
      }
      if (cnt == 3) elegant = false;
    }
  }

  cout << (elegant ? "YES" : "NO") << endl;
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
