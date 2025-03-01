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
  int n; cin >> n;
  vector<int> t(n+1);
  int total = 0;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
    total += t[i];
  }
  int m; cin >> m;
  for (int i = 0; i < m; i++){
    int p, x; cin >> p >> x;
    cout << total - t[p] + x << endl;
  }
  return 0;
}
