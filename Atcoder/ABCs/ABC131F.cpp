/*
  Notice that disconnected components can never form rectangles.
  Any connected component will be fully connected: num_of_x * num_of_y
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

const int N = 1e5+5;
int x[N], y[N];

struct DSU{
  vector<pair<ll,ll>> p;
  DSU(ll n) : p(2*n+1) {
    for (int i = 1; i <= n; i++){
      p[i] = {-1, 0};
      p[i+n] = {0, -1};
    }
  }

  pair<ll,ll> find (ll x){
    if (p[x].first < 0 || p[x].second < 0) return {x,x};
    return p[x] = find(p[x].first);
  }

  ll size(ll x) {
    x = find(x).first;
    return -(p[x].first+p[x].second);
  }

  void unite (ll a, ll b){
    a = find(a).first;
    b = find(b).first;
    if (a == b) return;

    if (size(a) > size(b)) {
      p[a].first += p[b].first;
      p[a].second += p[b].second;
      p[b] = {a,a};
    }
    else {
      p[b].first += p[a].first;
      p[b].second += p[a].second;
      p[a] = {b,b};
    }
  }

  ll compute(ll x){
    if (p[x].first > 0) return 0;
    return p[x].first*p[x].second;
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll n; cin >> n;
  DSU dsu = DSU(1e5);
  for (int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
    dsu.unite(x[i],y[i]+1e5);
  }

  ll ans = 0;
  for (int i = 1; i <= 2e5; i++){
    ans += dsu.compute(i);
  }

  cout << ans - n << endl;
  return 0;
}
