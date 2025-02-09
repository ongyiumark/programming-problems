#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  vector<ll> A(n);
  ll S = 0;
  for (ll &x: A) cin >> x, S ^= x;
  
  ll mask = 0;
  int q = 61;
  // remove bits where XOR is 1
  for (int i = 0; i < q; i++) if (((S>>i)&1) == 0) mask |= (1LL<<i);
  for (ll &x : A) x &= mask;

  // maximize bits where XOR is 0
  int ci = 0;
  for (int i = q; i >=0; i--) {
    int p = -1;
    for (int j = ci; j < n; j++) if ((A[j]>>i)&1) p = j;
    if (p == -1) continue;
    swap(A[ci], A[p]);
    for (int j = 0; j < n; j++) {
      if (j == ci) continue;
      if (((A[j]>>i)&1)) A[j] ^= A[ci];
    }
    ci++;
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) ans ^= A[i];
  ans <<= 1;
  ans += S;
  cout << ans << "\n";

  
  return 0;
}
