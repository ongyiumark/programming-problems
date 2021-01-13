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

  int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;

  int y = ty-sy;
  int x = tx-sx;

  string ans;
  ans.append(y, 'U');
  ans.append(x, 'R');
  ans.append(y, 'D');
  ans.append(x+1, 'L');
  ans.append(y+1, 'U');
  ans.append(x+1, 'R');
  ans.append(1, 'D');
  ans.append(1, 'R');
  ans.append(y+1, 'D');
  ans.append(x+1, 'L');
  ans.append(1, 'U');
  
  cout << ans << endl;
  return 0;
}
