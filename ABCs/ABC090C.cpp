/*
  The number of times its flipped is the number of neighboring cells.
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll n, m; cin >> n >> m;
  if (n == 1 & m == 1) cout << 1 << endl;
  else if (n == 1) cout << max(m-2, 0LL) << endl;
  else if (m == 1) cout << max(n-2, 0LL) << endl;
  else cout << max(n-2,0LL)*max(m-2,0LL) << endl;
  return 0;
}
