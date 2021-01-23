/*
  Try all L's and R's. O(n^2)
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
int a[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  ll ans = 0;
  for (int l = 0; l < n; l++){
    int currmin = 1e9;
    for (int r = l; r < n; r++){
      currmin = min(currmin, a[r]);
      ans = max(ans, (ll)currmin*(r-l+1));
    }
  }
  cout << ans << endl;
  return 0;
}
