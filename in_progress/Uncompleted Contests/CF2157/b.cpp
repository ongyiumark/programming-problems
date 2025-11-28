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

int main(){
  cin.tie(0)->sync_with_stdio(false);

  int t; cin >> t;
  while (t--) {
    int n; ll x, y;
    cin >> n >> x >> y;
    ll man_dist = abs(x)+abs(y);
    ll x_dist = abs(x);
    ll y_dist = abs(y);
    string s; cin >> s;

    for (int i = 0; i < n; i++) {
      x_dist -= 1;
      y_dist -= 1;
      man_dist -= 1;
      if (s[i] == '8') man_dist -= 1;
    }
    if (x_dist <= 0 && y_dist <= 0 && man_dist <= 0) cout << "YES\n";
    else cout << "NO\n";
  }
  
  return 0;
}
