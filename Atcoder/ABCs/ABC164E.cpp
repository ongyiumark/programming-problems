/*
  Dijkstra with (city, current_coins) as the nodes. 
  Clamp the current_coins.
  Since A_i <= 50 and  N <= 50, current_coins <= 2500.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 51;
const int S = 2501;
ll n, m, s;

struct edge {
  pair<ll,ll> to;
  ll w;
};

vector<edge> graph[N][S];

ll c[N];
ll d[N];

void solve(){
  priority_queue<pair<ll, pair<int,int>>, vector<pair<ll, pair<int,int>>>, greater<pair<ll, pair<int,int>>> > pq;
  ll dist[N][S];
  
  for (int i = 0; i < N; i++){
    for (int j = 0; j < S; j++){
      dist[i][j] = 1e18;
    }
  };

  dist[1][s] = 0;
  pq.push({dist[1][s], {1, s}});

  while(!pq.empty()){
    auto curr = pq.top();
    pq.pop();

    int u = curr.second.first;
    int ucoin = curr.second.second;

    for (auto e : graph[u][ucoin]){
      int v = e.to.first;
      int vcoin = e.to.second;

      if (dist[u][ucoin] + e.w < dist[v][vcoin]){
        dist[v][vcoin] = dist[u][ucoin] + e.w;
        pq.push({dist[v][vcoin], {v, vcoin}});
      }
    }

    ll newcoin = min(ucoin+c[u], 2500LL);
    if (dist[u][ucoin] + d[u] < dist[u][newcoin]){
      dist[u][newcoin] = dist[u][ucoin] + d[u];
      pq.push({dist[u][newcoin], {u, newcoin}});
    }
  }

  for (int i = 2; i <= n; i++){
    ll ans = 1e18;
    for (int j = 0; j <= 2500; j++){
      ans = min(ans, dist[i][j]);
    }
    cout << ans << "\n";
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> s;

  s = min(s, 2500LL);
  for (int i = 0; i < m; i++){
    ll u, v, a, b;
    cin >> u >> v >> a >> b;
    for (int j = a; j <= 2500; j++){
      graph[u][j].push_back({{v, j-a}, b});
      graph[v][j].push_back({{u, j-a}, b});
    }
  }

  for (int i = 1; i <= n; i++){
    cin >> c[i] >> d[i];
  }
  solve();
  return 0;
}
