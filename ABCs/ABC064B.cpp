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
  int lo = 1e9;
  int hi = 0;
  for (int i = 0; i < n; i++){
    int a; cin >> a;
    lo = min(lo,a);
    hi = max(hi,a);
  }
  cout << hi-lo << endl;
  return 0;
}
