#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;
  int a[n], b[n];
  for (int i = 0; i < n; i++){
    cin >> a[i] >> b[i];
  }

  pair<int,int> ans[n];
  memset(ans, 127, sizeof ans);
  for (int i = 0; i < m; i++){
    int c, d; cin >> c >> d;
    for (int j = 0; j < n; j++){
      int x = abs(c-a[j]);
      int y = abs(d-b[j]);
      if(ans[j].second > x+y){
        ans[j] = {i, x+y};
      }
    }
  }

  for (int i = 0; i < n; i++){
    cout << ans[i].first+1 << endl;
  }
  return 0;
}
