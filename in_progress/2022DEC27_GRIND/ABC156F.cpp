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
  
  int k, q ; cin >> k >> q;
  vi d(k);
  for (int &x : d) cin >> x;
  while(q--) {
    ll n, x, m; cin >> n >> x >> m;
    vector<ll> nd(k);
    for (int i = 0; i < k; i++) {
      nd[i] = d[i]%m;
    }
    x %= m;

    ll cnt0 = 0;
    ll S = 0;
    for (int i = 0; i < k; i++) {
      S += nd[i];
      cnt0 += (nd[i] == 0);
    }
    ll y = x+S*((n-1)/k);
    cnt0 *= ((n-1)/k);
    for (int i = 0; i < (n-1)%k; i++) {
      y += nd[i];
      cnt0 += (nd[i] == 0);
    }

    cout << (n - 1) - y/m - cnt0 << "\n";

  }
  return 0;
}
