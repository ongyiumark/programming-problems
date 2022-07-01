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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while (t--){
    ll n, m; cin >> n >> m;

    ll x, y;
    x = 0; y = 0;
    for (int i = 1; i <= m; i++) {
      x += i;
      y += i+(n-1)*m;
    }
    for (int i = 1; i < n; i++) {
      x += i*m+m;
      y += (i-1)*m + 1;
    }
    cout << min(x,y) << endl;
  }
  return 0;
}
