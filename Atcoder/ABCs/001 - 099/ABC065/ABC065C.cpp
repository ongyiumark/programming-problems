/*
  It's impossible if abs(n-m) > 1.
  If abs(n-m) == 1, fact(n)*fact(m).
  if abs(n-m) == 0, fact(n)*fact(m)*2.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 1e9+7;
const int N = 1e5+1;
ll fact[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fact[0] = 1;
  for (int i = 1; i < N; i++){
    fact[i] = i*fact[i-1]%MOD;
  }
  int n, m; cin >> n >> m;
  if (abs(n-m) > 1) cout << 0 << endl;
  else if (n != m) cout << fact[n]*fact[m]%MOD << endl;
  else cout << fact[n]*fact[m]*2%MOD << endl;
  return 0;
}
