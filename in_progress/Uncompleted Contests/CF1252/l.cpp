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

const int N = 2005;
const ll INF = 1e18;
int A[N], M[N], C[N];
vector<int> B[N];
vector<int> graph[N];
bool vis[N];
int par[N];

map<int,int> mat2idx; 
map<int,int> matcnt;
vector<int> mats;

set<pii> cycle;
map<pii, int> road2idx;

struct edge {
  int u, v;
  ll cap, flow;
  edge(int u, int v, ll cap) :
    u(u), v(v), cap(cap), flow(0) {}
};

struct flow_network{
  int n, s, t, *adj_ptr, *par;
  ll *dist;
  vector<edge> edges;
  vector<int> *adj;
  flow_network(int n, int s, int t) : n(n), s(s), t(t) {
    adj = new vector<int>[n];
    adj_ptr = new int[n];
    par = new int[n];
    dist = new ll[n];
  }

  void add_edge(int u, int v, ll cap, bool bi=false) {
    adj[u].push_back(edges.size());
    edges.push_back(edge(u,v, cap));
    adj[v].push_back(edges.size());
    edges.push_back(edge(v,u, (bi ? cap : 0LL)));
  }

  ll res (edge &e) {
    return e.cap - e.flow;
  }

  bool make_level_graph() {
    for (int u = 0; u < n; u++) dist[u] = -1;
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
      int u = q.front(); q.pop();
      for (int i : adj[u]){
        edge &e = edges[i];
        if (dist[e.v] < 0 && res(e)) {
          dist[e.v] = dist[u] + 1;
          q.push(e.v);
        }
      }
    }

    return dist[t] != -1;
  }

  bool is_next(int u, int v) {
    return dist[v] == dist[u] + 1;
  }

  bool dfs(int u) {
    if (u == t) return true;
    for (int &ii = adj_ptr[u]; ii < adj[u].size(); ii++) {
      int i = adj[u][ii];
      edge &e = edges[i];
      if (is_next(u, e.v) && res(e) > 0 && dfs(e.v)) {
        par[e.v] = i;
        return true;
      }
    }
    return false;
  }

  bool aug_path() {
    for (int u = 0; u < n; u++) par[u] = -1;
    return dfs(s);
  }

  ll calc_max_flow() {
    ll total_flow = 0;
    while(make_level_graph()) {
      for (int u = 0; u < n; u++) adj_ptr[u] = 0;
      while(aug_path()) {
        //cout << "test" << endl;
        ll flow = INF;
        for (int i = par[t]; i != -1; i = par[edges[i].u]) {
          flow = min(flow, res(edges[i]));
        }
        for (int i = par[t]; i != -1; i = par[edges[i].u]) {
          edges[i].flow += flow;
          edges[i^1].flow -= flow;
        }
        total_flow += flow;
      }
    }
    return total_flow;
  }
};

pii dfs(int u, int p){
  vis[u] = 1;
  for (int v : graph[u]){
    if (v == p) continue;
    if (vis[v]) return {u,v};
    par[v] = u;
    return dfs(v, u);
  }
  return {-1,-1};
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k; cin >> n >> k;
  int idx = -1;
  for (int i = 1; i <= n; i++){
    cin >> A[i] >> M[i];
    for (int j = 0; j < M[i]; j++){
      int tmp; cin >> tmp;
      if (mat2idx.find(tmp) == mat2idx.end()) {
        idx++;
        mat2idx[tmp] = idx;
        mats.push_back(tmp);
      }
      B[i].push_back(tmp);
    }
    graph[i].push_back(A[i]);
    graph[A[i]].push_back(i);
    road2idx[{min(A[i],i), max(A[i],i)}] = i;
  }

  pii st = dfs(1, -1);
  cycle.insert({min(st.first, st.second), max(st.first, st.second)});
  while(st.first != st.second) {
    cycle.insert({min(st.first, par[st.first]), max(st.first, par[st.first])});
    st.first = par[st.first];
  }

  for (int i = 0; i < k; i++){
    cin >> C[i];
    if (mat2idx.find(C[i]) == mat2idx.end()) {
      idx++;
      mat2idx[C[i]] = idx;
      mats.push_back(C[i]);
    }
    matcnt[C[i]]++;
  }

  int matsz = mats.size();
  // source: 0
  // constraint layer: 1, 2 
  // roads: 3 to n+2
  // mats: n+3 to n+matsz+2
  // sink: n+matsz+3

  flow_network fn(n+matsz+4, 0, n+matsz+3);
  fn.add_edge(0,1,(int)cycle.size()-1);
  fn.add_edge(0,2,n-(int)cycle.size());
  for (auto p : cycle){
    int a = p.first; int b = p.second;
    if (a > b) swap(a,b);
    int v = road2idx[{a,b}]+2;
    fn.add_edge(1,v,1); 
    //cout << a << " " << b << endl;
  }

  for (int i = 1; i <= n; i++){
    int a = i; int b = A[i];
    if (a > b) swap(a,b);
    if (cycle.find({a,b}) != cycle.end()) continue;
    int v = road2idx[{a,b}]+2;
    fn.add_edge(2,v,1);
    //cout << a << " " << b << endl;
  }

  for (int i = 1; i <= n; i++){
    for (int j = 0; j < M[i]; j++){
      int u = i+2;
      int v = mat2idx[B[i][j]]+n+3;
      int cap = matcnt[B[i][j]];
      //cout << cap << endl;
      fn.add_edge(u,v,cap);
    }
  }
  for (int i = 0; i < matsz; i++){
    int v = i+n+3;
    fn.add_edge(v,n+matsz+3,1);
  }

  int res = fn.calc_max_flow();
  if (res < n-1) {
    cout << -1 << endl;
    return 0;
  }
  
  queue<int> workers[matsz];
  for (int i = 0; i < k; i++){
    workers[mat2idx[C[i]]].push(i);
  }

  pii ans[k];
  for (int i = 0; i < k; i++) ans[i] = {0,0};

  for (int u = 3; u <= n+2; u++){
    for (int &ii = fn.adj_ptr[u]; ii < fn.adj[u].size(); ii++) {
      int i = fn.adj[u][ii];
      edge &e = fn.edges[i];
      if (e.flow > 0) {
        int matidx = e.v-n-3;
        while(e.flow--){
          int x = workers[matidx].front();
          workers[matidx].pop();
          ans[x] = {e.u-2, A[e.u-2]};
        }
      }
    }
  }

  for (int i = 0; i < k; i++){
    cout << ans[i].first << " " << ans[i].second << endl;
  }


  //cout << res << endl;
  return 0;
}
