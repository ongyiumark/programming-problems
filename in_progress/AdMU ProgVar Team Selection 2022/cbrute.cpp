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

const int maxM = 1e5+5;
const int maxN = 3e3+5;
const int INF = 1e9;

vector<pii> graph[maxN];
int S[maxN];

int dist[maxN][maxN];

int solve(int a, int b, int d) {
  if (a > b) swap(a,b);
  int diff = b-a;
  a += min(diff, d);
  d -= min(diff, d);
  
  return min(a+(d+1)/2, b+(d+1)/2);
}

void djikstra(int s, int n) {
  //cout << s << endl;
  for (int i = 0; i < n; i++) dist[s][i] = INF;
  dist[s][s] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({dist[s][s], s});

  
  while(!pq.empty()) {
    auto [d,u] = pq.top();
    pq.pop();
    if (dist[s][u] < d) continue;
    dist[s][u] = d;
    for (auto [v,w] : graph[u]) {
      //cout << s << " " << u << " " << v << endl;
      if (dist[s][v] > dist[s][u]+w) {
        dist[s][v] = dist[s][u]+w;
        //cout << v << " from " << u << " " << dist[s][u]+w << endl; 
        pq.push({dist[s][v], v});
      }
    }
  } 
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k; cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int u, v, l; cin >> u >> v >> l;
    u--; v--;
    graph[u].push_back({v,l});
    graph[v].push_back({u,l});
  }

  for (int i = 0; i < k; i++) {
    cin >> S[i];
    S[i]--;
    djikstra(S[i], n);

    /*
    cout << S[i] << ": ";
    for (int j = 0; j < n; j++) {
      cout << dist[S[i]][j] << " ";
    }
    cout << endl;
    */
  }


  int ans = -INF;

  vector<int> closest(n, INF);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      closest[i] = min(closest[i], dist[S[j]][i]);
    }
  }
  /*
  for (int i = 0; i < n; i++) {
    cout << i+1 << ": " << closest[i] << endl; 
  }*/
  
  for (int u = 0; u < n; u++) {
    for (auto [v,l] : graph[u]) {
      int tmp = solve(closest[u], closest[v], l);
      ans = max(ans, tmp);

      //cout << u+1 << " " << v+1 << " " << tmp << endl;
    }
  }

  for (int i = 0; i < n; i++) ans = max(ans, closest[i]);

  cout << ans << endl;


  
  
  return 0;
}
