/*
  Standard Binary Lifting.
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
ll lca[40][N], total[40][N], lo[40][N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  memset(total, 0, sizeof total);
  ll n, K; cin >> n >> K;
  for (int i = 0; i < n; i++) {
    cin >> lca[0][i];
  }
  for (int i = 0; i < n; i++) {
    cin >> lo[0][i];
    total[0][i] = lo[0][i];
  }

  for (int k = 1; k < 40; k++) {
    for (int i = 0; i < n; i++) {
      lca[k][i] = lca[k-1][lca[k-1][i]];
      total[k][i] = total[k-1][i] + total[k-1][lca[k-1][i]];
      lo[k][i] = min(lo[k-1][i], lo[k-1][lca[k-1][i]]);
      //cout << k << " " << i << ": " << total[k][i] << endl;
    }
  }

  for (int i = 0; i < n; i++) {
    ll atotal = 0;
    ll alo = 1e18;
    int u = i;
    for (ll k = 40-1; k >= 0; k--) {
      if ((1LL<<k)&K) {

        atotal += total[k][u];
        alo = min(alo, lo[k][u]);
        u = lca[k][u];
      }
    }
    cout << atotal << " " << alo << endl;
  }
  return 0;
}
