#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ll,ll> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  vector<ii> edges(n);
  for (int i = 0; i < n-1; i++) {
    ll u, v; cin >> u >> v;
    if (u > v) swap(u, v);
    edges.push_back({u,v});
  }

  ll total = 0;

  // contibution of vertex v
  for (ll v = 1; v <= n; v++) {
    total += (v-1+1)*(n-v+1);
  }

  // contribution of edge u, v
  for (auto [u,v] : edges) {
    total -= (u-1+1)*(n-v+1);
  }

  cout << total << "\n";

  return 0;
}
