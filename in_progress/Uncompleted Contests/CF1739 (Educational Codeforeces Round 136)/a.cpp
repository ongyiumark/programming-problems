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

bool valid(int i, int j, int n, int m) {
  int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
  int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

  for (int d = 0; d < 8; d++) {
    int x = i+dx[d];
    int y = j+dy[d];
    if (x < 0 || x >= n || y < 0 || y >= m) continue;
    return true;
  }
  return false;
}

void testcase() {
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!valid(i, j, n, m)) {
        cout << i+1 << " " << j+1 << endl;
        return;
      }
    }
  }
  cout << 1 << " " << 1 << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--) testcase();
  return 0;
}
