#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ll,pair<ll,ll>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int M = 998244353;
const int N = 2e5+5;

ll modpow(ll b, ll e) {
  ll ans = 1;
  while(e > 0) {
    if (e&1) ans = ans*b%M;
    b = b*b%M;
    e >>= 1;
  }
  return ans;
}

ll modinv(ll x){
  return modpow(x, M-2);
}

ll gcd(ll a, ll b){
  if (b == 0) return a;
  return gcd(b, a%b);
}

ll lcm(ll a, ll b){
  return a/gcd(a,b)*b;
}

ll modlcm(ll a, ll b){
  return a*modinv(gcd(a,b))%M*b%M;
}

vector<piii> graph[N];
bool vis[N];
bool valid;

ll solve(int u, ll l) {
  vis[u] = 1;
  ll ans = l%M;
  for (piii p : graph[u]){
    int v = p.first;
    ll x = p.second.first;
    ll y = p.second.second;
    if (vis[v]) continue;
    if (l%x != 0) valid = false;
    ans += solve(v,l/x*y);
    ans %= M;
  }
  return ans;
}

void testcase(){
  int n; cin >> n;
  ll alllcm = 1;
  for (int i = 0; i < n-1; i++) {
    ll u, v, x, y; cin >> u >> v >> x >> y;
    graph[u].push_back({v,{x,y}});
    graph[v].push_back({u,{y,x}});
  }

  int i = 1;
  while(true) {
    memset(vis, 0, sizeof vis);
    valid = 1;
    ll ans = solve(1, graph[1][0].second.first*i);
    if (valid) {
      cout << ans << endl;
      cout << i << endl;
      return;
    }
    //cout << i << " " << valid << endl;
    i++;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while (t--){
    testcase();
  }
  
  return 0;
}
