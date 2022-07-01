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
    if (n > m) swap(n, m);
    if (n == 1) {
      if (m == 1) cout << 0 << endl;
      else if (m == 2) cout << 1 << endl;
      else cout << -1 << endl;
      continue;
    }

    // (n,n) takes 2n
    ll cnt = 2*(n-1);
    m -= n;
    cnt += 2*m-m%2;
    cout << cnt << endl;
  }

  return 0;
}
