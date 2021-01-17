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

  int group[13] = {0, 1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1};
  int x, y; cin >> x >> y;
  cout << (group[x] == group[y] ? "Yes" : "No") << endl;
  return 0;
}
