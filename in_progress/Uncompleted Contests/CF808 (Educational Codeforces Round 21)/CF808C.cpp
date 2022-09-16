/*
  Greedily add half, then add starting from the highest.
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

const int N = 105;
pair<int,int> a[N];
int ans[N], res[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, w; cin >> n >> w;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    a[i] = {x,i};
  }
  sort(a, a+n);
  for (int i = 0; i < n; i++) {
    ans[i] = (a[i].first+1)/2;
    w -= (a[i].first+1)/2;
  }
  if (w < 0) {
    cout << -1 << endl;
    return 0;
  }

  for (int i = n-1; i >= 0; i--) {
    int need = a[i].first/2;
    ans[i] += min(need, w);
    w -= min(need, w);
    if (w == 0) break;
  }

  if (w > 0) {
    cout << -1 << endl;
    return 0;
  }


  for (int i = 0; i < n; i++) {
    res[a[i].second] = ans[i];
  }

  for (int i = 0; i < n; i++) {
    cout << res[i];
    if (i != n-1) cout << " ";
    else cout << endl;
  }


  return 0;
}
