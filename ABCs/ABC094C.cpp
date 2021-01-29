/*
  If we remove something on or before the n/2-th element, the median becomes the n/2+1-th element.
  Otherwise, the median remains the n/2-th element.
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
using ordered_set = __gnu_pbds::tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5+1;
pii x[N];
int ans[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  ordered_set<int> arr;
  for (int i = 1; i <= n; i++){
    int c; cin >> c;
    x[i] = {c,i};
  }
  sort(x+1, x+n+1);

  for (int i = 1; i <= n; i++){
    if (i <= n/2) ans[x[i].second] = x[n/2+1].first;
    else ans[x[i].second] = x[n/2].first;
  }
  for (int i = 1; i <= n; i++){
    cout << ans[i] << endl;
  }
  return 0;
}
