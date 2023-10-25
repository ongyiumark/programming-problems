#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 51;
string dstr = "NESW";
int di[] = {0,1,0,-1};
int dj[] = {1,0,-1,0};
map<char,int> d2idx;
bool blocked[N][N][4];

vector<int> k1(4), k2(4);
int E;

struct Node {
  array<int, 4> ar;
  Node(int x1, int y1, int x2, int y2) : ar({x1, y1, x2, y2}) {}
  pair<Node,bool> move(int k) {
    auto [x1, y1, x2, y2] = ar;
    if (blocked[x1][y1][k1[k]] && blocked[x2][y2][k2[k]])
      return {Node(x1,y1,x2,y2), 2};
    
    int nx1 = x1+di[k1[k]];
    int ny1 = y1+dj[k1[k]];
    int nx2 = x2+di[k2[k]];
    int ny2 = y2+dj[k2[k]];

    if (blocked[x1][y1][k1[k]])
      return {Node(x1,y1,nx2,ny2), (x1 != E) || (y1 != 0)};
    
    if (blocked[x2][y2][k2[k]])
      return {Node(nx1,ny1,x2,y2), (x2 != E) || (y2 != 0)};
    return {Node(nx1,ny1,nx2,ny2), 0};
  }
  bool operator<(const Node &other) const {
    return ar < other.ar;
  }
  bool operator==(const Node &other) const {
    return ar == other.ar;
  }
  bool same_place() const {
    return (ar[0] == ar[2]) && (ar[1] == ar[3]) && !((ar[0] == E)&&(ar[1]==0));
  }
  int to_idx() {
    int base = 1;
    int res = 0;
    for (int i = 0; i < 4; i++) {
      res += ar[i]*base;
      base *= N;
    }
    return res;
  }
  friend ostream& operator<<(ostream& os, const Node& node);
};

ostream& operator<<(ostream& os, const Node& node) {
  for (int i = 0; i < 4; i++) {
    os << node.ar[i];
    if (i+1 < 4) os << " ";
  }
  return os;
}

struct Weight {
  array<int, 2> ar;
  Weight() : ar({INF, INF}) {}
  Weight(int a, int b) : ar({a,b}) {}
  bool operator<(const Weight &other) const {
    return ar < other.ar;
  }
  Weight operator+(const Weight &other) const {
    return Weight(ar[0]+other.ar[0], ar[1]+other.ar[1]);
  }
  friend ostream& operator<<(ostream& os, const Weight& weight);
};
ostream& operator<<(ostream& os, const Weight& w) {
  for (int i = 0; i < 2; i++) {
    os << w.ar[i];
    if (i+1 < 2) os << " ";
  }
  return os;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int i = 0; i < 4; i++) d2idx[dstr[i]] = i;
  
  int c, r; cin >> c >> r >> E;
  int c1, r1, c2, r2;
  char d1, d2;
  cin >> c1 >> r1 >> d1 >> c2 >> r2 >> d2;

  memset(blocked, 0, sizeof blocked);
  // horizontal walls
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    blocked[x][y][d2idx['N']] = 1;
    blocked[x][y+1][d2idx['S']] = 1;
  }

  // vertical walls
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    blocked[x][y][d2idx['E']] = 1;
    blocked[x+1][y][d2idx['W']] = 1;
  }

  // boundary
  for (int i = 1; i <= r; i++) {
    blocked[1][i][d2idx['W']] = 1;
    blocked[c][i][d2idx['E']] = 1;
  }
  for (int i = 1; i <= c; i++) {
    blocked[i][1][d2idx['S']] = 1;
    blocked[i][r][d2idx['N']] = 1;
  }

  // goal
  blocked[E][1][d2idx['S']] = 0;
  for (int i = 0; i < 4; i++) blocked[E][0][i] = 1;

  // lock in turns
  k1[0] = d2idx[d1];
  k2[0] = d2idx[d2];
  for (int i = 1; i < 4; i++) {
    k1[i] = (k1[i-1]+1)%4;
    k2[i] = (k2[i-1]+1)%4;
  }

  // perform dijkstra
  Node s = Node(c1, r1, c2, r2);
  vector<Weight> dist(N*N*N*N, Weight(INF,INF));
  priority_queue<pair<Weight, Node>, vector<pair<Weight, Node>>, greater<pair<Weight, Node>>> pq;
  dist[s.to_idx()] = Weight(0,0);
  pq.push({dist[s.to_idx()], s});


  while (!pq.empty()) {
    auto [cw, u] = pq.top();
    pq.pop();
    if (dist[u.to_idx()] < cw) continue;
    
    for (int k = 0; k < 4; k++) {
      auto [v, b] = u.move(k);
      if (v.same_place()) continue;
      Weight w(1, b);
      if (dist[u.to_idx()]+w < dist[v.to_idx()]) {
        dist[v.to_idx()] = dist[u.to_idx()]+w;
        pq.push({dist[v.to_idx()], v});
      }
    }
  }  

  Node t = Node(E, 0, E, 0);
  auto [move, bump] = dist[t.to_idx()].ar;
  cout << move << " " << bump << "\n";

  return 0;
}