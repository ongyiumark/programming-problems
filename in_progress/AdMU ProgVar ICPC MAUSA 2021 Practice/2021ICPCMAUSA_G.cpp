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

int r, c;
int p2idx(int i, int j) {
  return i*c+j;
}

pii idx2p(int x) {
  return {x/c, x%c};
}

const int N = 55;
vector<pair<int,ld>> graph[N*N];
vector<vector<char>> grid(N, vector<char>(N,'.'));

ld dist(int u, int v) {
  auto [a,b] = idx2p(u);
  auto [c,d] = idx2p(v);

  return sqrtl((a-c)*(a-c) + (b-d)*(b-d));
}

int cross(pii left, pii right) {
  return left.first*right.second - left.second*right.first;
}

struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2>& p) const
  {
    return p.first*c+p.second;
  }
};

bool dfs(int u, int p, int start, int goal) {
  if(u == goal) return true;
  auto [a,b] = idx2p(start);
  auto [d,e] = idx2p(goal);

  auto [ci,cj] = idx2p(u);

  //cout << a << " " << b << " " << c << " " << d << endl;
  pii vec = {d-a, e-b};
  //cout << ci << " " << cj << endl;

  if (grid[ci][cj] == '#') return false;
  bool found = false;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      int x = ci+i;
      int y = cj+j;
      if (x < 0 || x >= r || y < 0 || y >= c) continue;
      if (x < min(a,d) || x >= max(a,d) || y < min(b,e) || y >= max(b,e)) continue;
      //if (b < e && (x < min(a,d) || x >= max(a,d) || y < min(b,e) || y >= max(b,e))) continue;
      if (p == p2idx(x,y)) continue;

      if (abs(i)+abs(j) == 2) {
        if (i == -1 && j == -1 && cross(vec, {ci-a, cj-b}) == 0) found = true;
        else if (i == -1 && j == 1 && cross(vec, {ci-a, cj-b+1}) == 0) found = true;
        else if (i == 1 && j == -1 && cross(vec, {ci-a+1, cj-b}) == 0) found = true;
        else if (i == 1 && j == 1 && cross(vec, {ci-a+1, cj-b+1}) == 0) found = true;
      }
      else if (abs(i)+abs(j) == 1) {
        //cout << " " << x << " " << y << endl;
        if (i == 1 && cross(vec, {ci+1-a, cj-b})*cross(vec, {ci+1-a, cj+1-b}) < 0) found = true;
        else if (i == -1 && cross(vec, {ci-a, cj-b})*cross(vec, {ci-a, cj+1-b}) < 0) found = true;
        else if (j == 1 && cross(vec, {ci-a, cj+1-b})*cross(vec, {ci+1-a, cj+1-b}) < 0) found = true;
        else if (j == -1 && cross(vec, {ci-a, cj-b})*cross(vec, {ci+1-a, cj-b}) < 0) found = true;

        //cout << cross(vec, {ci-a, cj+1-b}) << " " << cross(vec, {ci+1-a, cj+1-b}) << endl;
      }

      if (found) return dfs(p2idx(x,y), u, start, goal);
    }
  }

  //cout << ci << " " << cj << endl;
  //cout << "YEET" << endl;
  return true;
}

ld djikstra(int s) {
  priority_queue<pair<ld, int>, vector<pair<ld, int>>, greater<pair<ld,int>>> pq;
  pq.push({0,s});
  
  ld dist[N*N];
  for (int i = 0; i < N*N; i++) dist[i] = 1e18;
  dist[0] = 0;

  while(!pq.empty()) {
    auto [currw,u] = pq.top();
    pq.pop();
    if (dist[u] < currw) continue;

    for (auto [v, w] : graph[u]) {
      if (dist[u]+w < dist[v]) {
        dist[v] = dist[u]+w;
        pq.push({dist[v],v});
      } 
    }
  }
  return dist[p2idx(r-1, c-1)];
}

bool check(int u, int v) {
  if (u > v) swap(u,v);
  auto [a,b] = idx2p(u);
  auto [d,e] = idx2p(v);
  if (b > e) return dfs(u-1, -1, u, v);
  else return dfs(u, -1, u, v);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> grid[i][j];
    }
  }
  c++; r++;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      int u = p2idx(i, j);
      for (int k = 0; k < r; k++) {
        for (int l = 0; l < c; l++) {
          int v = p2idx(k, l);
          if (v <= u) continue;
          if (i == k) {
            graph[u].push_back({v, abs(j-l)});
            graph[v].push_back({u, abs(j-l)});
          }
          else if (j == l) {
            graph[u].push_back({v, abs(i-k)});
            graph[v].push_back({u, abs(j-l)});
          }
          else if (check(u,v)) {
            graph[u].push_back({v,dist(u,v)});
            graph[v].push_back({u, abs(j-l)});
          }
        }
      }
    }
  }

  cout << setprecision(10) << fixed << djikstra(0) << endl;

  return 0;
}
