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

const ll M = 1e9+7;
ll modpow(ll b, ll e) {
  ll ans = 1;
  while(e > 0) {
    if (e&1) ans = ans*b%M;
    b = b*b%M;
    e >>= 1;
  }
  return ans;
}

ll inv(ll x) {
  return modpow(x, M-2);
}



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k; cin >> n >> k;
  vector<vector<int>> adj_list(n, vector<int>());
  for (int i = 0; i < n-1; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }

  if (k == 1) {
    cout << 1 << "\n";
    return 0;
  }

  if (k == 2) {

    return 0;
  }

  if (k == 3) {
    cout << 1 << "\n";
    return 0;
  }

  
  return 0;
}
