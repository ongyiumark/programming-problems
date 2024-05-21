/* 
  This can be answered with prefix sums.
    But we have to careful when the left edge is between an 'AC'.
    This can be fixed by having a separate prefix sum for the left edge that adds 1 on the 'A' instead of on the 'C'.
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

const int N = 1e5+5;
int prefr[N], prefl[N];
string s;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q; cin >> n >> q;
  cin >> s;
  memset(prefl, 0, sizeof prefl);
  memset(prefr, 0, sizeof prefr);
  for (int i = 1; i < n; i++){
    prefr[i] = (s[i-1] == 'A' && s[i] == 'C') + prefr[i-1];
    prefl[i-1] = (s[i-1] == 'A' && s[i] == 'C');
    if (i > 1) prefl[i-1] += prefl[i-2]; 
  }
  while(q--){
    int l, r; cin >> l >> r;
    l--; r--;
    int ans = prefr[r];
    if (l > 0) ans -= prefl[l-1];
    cout << ans << endl;
  }
  return 0;
}
