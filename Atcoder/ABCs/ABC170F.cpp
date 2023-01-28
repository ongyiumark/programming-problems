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

int h, w, k;
int x1, x2, z1, z2;
vector<vector<ll>> dist[4];
vector<vector<char>> grid;
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};

const ll INF = 1e18;

typedef tuple<ll, int, int, int>  state;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> h >> w >> k;
  cin >> x1 >> z1 >> x2 >> z2;
  x1--; z1--; x2--; z2--;
  grid.resize(h);
  for (int i = 0; i < h; i++) {
    grid[i].resize(w);
    for (int j = 0; j < w; j++) {
      cin >> grid[i][j];
    }
  }

  for (int d = 0; d < 4; d++) {
    dist[d].resize(h);
    for (int i = 0; i < h; i++) {
      dist[d][i].resize(w);
      for (int j = 0; j < w; j++) {
        dist[d][i][j] = INF;
      }
    }
  }

  priority_queue<state, vector<state>, greater<state>> pq;
  for (int d = 0; d < 4; d++) {
    pq.push({0, d, x1, z1});
    dist[d][x1][z1] = 0;
  }

  while(!pq.empty()) {
    auto [ww, d, i, j] = pq.top();
    pq.pop();

    if (dist[d][i][j] < ww) continue;

    for (int dd = 0; dd < 4; dd++) {
      int x = i + di[dd];
      int y = j + dj[dd];
      if (x < 0 || x >= h || y < 0 || y >= w) continue;

      if (grid[x][y] == '@') continue;

      ll nw = (d == dd ? dist[d][i][j]+1 : (dist[d][i][j]+k-1)/k*k+1);
      if (dist[dd][x][y] > nw) {
        pq.push({nw,dd,x,y});
        dist[dd][x][y] = nw;
      }
    }
  }
  
  ll ans = INF;
  for (int d = 0; d < 4; d++) {
    ans = min(dist[d][x2][z2], ans);
  }
  cout << (ans < INF ? (ans+k-1)/k : -1) << "\n";
  
  return 0;
}