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

const ll N = 1e5+5;
const ll LOG = 20;
ll a[N], b[N], c[N], d[N];

struct edge {
  ll to, c, d;

  edge(ll _to, ll _c, ll _d) : to(_to), c(_c), d(_d) {}
};

vector<edge> graph[N];
ll par[N][LOG];
ll dist[N];
ll dep[N];

vector<edge> topo;
vector<pii> color[N];
vector<ll> prefCol[N], cntCol[N];
map<ll,ll> v2idx;

void dfs(ll u, ll p){
  for (edge e : graph[u]) {
    ll v = e.to;
    if (v == p) continue;
    ll c = e.c; ll d = e.d;
    par[v][0] = u;
    dist[v] = dist[u]+d;
    dep[v] = dep[u]+1;

    v2idx[v] = topo.size();
    topo.push_back(edge(v, c, d));
    dfs(v,u);
    topo.push_back(edge(v, c, -d));
  }
}

ll lca(ll a, ll b) {
  if (dep[a] > dep[b]) swap(a,b);
  ll k = dep[b]-dep[a];
  for (ll j = LOG; j >= 0; j--) {
    if (k & (1<<j)) {
      b = par[b][j];
    }
  }
  if (a == b) return a;

  for (ll j = LOG; j >= 0; j--) {
    if (par[a][j] != par[b][j]) {
      a = par[a][j];
      b = par[b][j];
    }
  }
  return par[a][0];
}

pii getcolor(ll u, ll c) {
  if (u == 0) return {0,0};
  ll cn = color[c].size();
  ll hi = cn-1;
  ll lo = 0;

  ll ans = -1;
  while(lo <= hi){
    ll mid = hi - (hi-lo)/2;
    if (color[c][mid].first <= v2idx[u]) {
      lo = mid+1;
      ans = mid;
    }
    else hi = mid-1;
  }
  if (ans == -1) return {0,0};
  else return {prefCol[c][ans], cntCol[c][ans]};
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, q; cin >> n >> q;
  for (ll i = 0; i < n-1; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i]--;
    b[i]--;
    graph[a[i]].push_back(edge(b[i],c[i],d[i]));
    graph[b[i]].push_back(edge(a[i],c[i],d[i]));
  }

  memset(par, 0, sizeof par);
  memset(dist, 0, sizeof dist);
  memset(dep, 0, sizeof dep);
  dfs(0, -1);
  // Binary lifting.
  for (ll k = 1; k < LOG; k++) {
    for (ll i = 0; i < n; i++) {
      par[i][k] = par[par[i][k-1]][k-1];
    }
  }

  // Segmenting colors
  for (ll i = 0; i < topo.size(); i++) {
    edge e = topo[i];
    ll v = e.to; ll c = e.c; ll d = e.d;
    color[c].push_back({i, d});
  }

  // Prefix colors 
  for (ll c = 1; c < n; c++) {
    ll cn = color[c].size();
    if (cn == 0) continue;
    for (ll i = 0; i < cn; i++) {
      prefCol[c].push_back(color[c][i].second);
      cntCol[c].push_back(color[c][i].second > 0 ? 1 : 0);
      if (i != 0) {
        prefCol[c][i] += prefCol[c][i-1];
        cntCol[c][i] += cntCol[c][i-1];
      }
    }
  }

  while(q--){
    ll x, y, u, v; cin >> x >> y >> u >> v;
    u--; v--;
    ll d = dist[u] + dist[v] - 2*dist[lca(u,v)];
    pii ucol = getcolor(u, x);
    pii vcol = getcolor(v, x);
    pii lcacol = getcolor(lca(u,v), x);

    ll colorTotal = ucol.first + vcol.first - 2*lcacol.first;
    ll cntTotal = ucol.second + vcol.second - 2*lcacol.second;
    
    //cout << u+1 << " " << v+1 << " " << lca(u,v)+1 << endl;
    //cout << ucol.first << " " << vcol.first << " " << lcacol.first << endl;
    //cout << d << " " << colorTotal << " " << cntTotal << endl;
    //cout << endl;
    cout << d-colorTotal+cntTotal*y << endl;
  }
  return 0;
}
