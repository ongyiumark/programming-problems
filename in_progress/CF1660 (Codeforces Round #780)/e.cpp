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

void testcase() {
  int n; cin >> n;
  vector<vector<bool>> grid(n, vector<bool>(n,0));
  int total = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c; cin >> c;
      grid[i][j] = (c == '1');
      total += grid[i][j];
    }
  }
  /*
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << grid[i][j];
    }
    cout << endl;
  }*/

  int diags[n];
  memset(diags, 0, sizeof diags);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int idx = i-j;
      if (idx < 0) idx += n;
      diags[idx] += (grid[i][j]);
    }
  }

  int ans = 1e9;
  for (int i = 0; i < n; i++) {
    int rem = total - diags[i];
    ans = min(ans,rem+n-diags[i]);
    //cout << i << " " << rem << " " << diags[i] << endl;
  }
  cout << ans << endl;
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
