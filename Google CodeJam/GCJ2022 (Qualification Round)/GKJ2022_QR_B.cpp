/*
  Get the minimum for each color.
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

void testcase(){
  int arr[3][4];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> arr[i][j];
      if (i > 0) {
        arr[i][j] = min(arr[i-1][j], arr[i][j]);
      }
    }
  } 

  int ans[4];
  int need = 1e6;
  for (int i = 0; i < 4; i++) {
    ans[i] = min(need,arr[2][i]);
    need -= min(need,arr[2][i]);
  }
  if (need > 0) cout << "IMPOSSIBLE\n";
  else {
    for (int i = 0; i < 4; i++) {
      cout << ans[i];
      if (i == 3) cout << "\n";
      else cout << " ";
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  for (int x = 1; x <= t; x++) {
    cout << "Case #" << x << ": ";
    testcase();
  }
  return 0;
}
