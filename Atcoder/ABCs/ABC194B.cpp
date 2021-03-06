/*
  Brute force is also possible because of the low constraints.
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

const int N = 1e4;
pii a[N], b[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < n; i++){
    int x, y; cin >> x >> y;
    a[i] = {x,i};
    b[i] = {y,i};
  }
  sort(a, a+n);
  sort(b, b+n);

  if (a[0].second == b[0].second) cout << min({a[0].first+b[0].first, max(a[0].first, b[1].first), max(a[1].first, b[0].first)});
  else cout << max(a[0].first, b[0].first);
  cout << endl;

  return 0;
}
