/*
  Binary search to count how many are less or equal.
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

const int N = 2e5+5;
int a[N], b[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(a, a+n);

  for (int i = 0; i < m; i++) {
    int lo = 0;
    int hi = n-1;
    int ans = -1;
    while (lo <= hi) {
      int mid = hi - (hi-lo)/2;
      if (a[mid] <= b[i]) {
        ans = mid;
        lo = mid+1;
      }
      else hi = mid-1;
    }
    cout << ans + 1;
    if (i == m-1) cout << endl;
    else cout << " ";
  }
  
  return 0;
}
