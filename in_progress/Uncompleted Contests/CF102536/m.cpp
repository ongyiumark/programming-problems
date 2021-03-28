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

int r, c, i, j;
const int N = 1e4;
bool grid[N];
int deg[N];

int dx[] = {-1,1, 0,0};
int dy[] = {0,0,-1,1};
char moves[] = {'U', 'D', 'L', 'R'};
vector<char> ans;
int cnt;
bool found;

int convert(int i, int j){
  return i*c+j;
}

bool check_deg(int i, int j){
  for (int k = 0; k < 4; k++){
    int x = i+dx[k];
    int y = j+dy[k];
    if (x < 0 || x >= r || y < 0 || y >= c) continue;
    if (deg[convert(x,y)] >= 3 && cnt+1 != r*c) return true;
  }
  return false;
}

void update_deg(int i, int j, int n){
  for (int k = 0; k < 4; k++){
    int x = i+dx[k];
    int y = j+dy[k];
    if (x < 0 || x >= r || y < 0 || y >= c) continue;
    deg[convert(x,y)] += n;
  }
}
void solve(int i, int j){
  if (cnt == r*c){
    for (char v : ans) cout << v;
    cout << endl;
    found = 1;
    return;
  }
  if (found == 1) return;
  for (int k = 0; k < 4; k++){
    int x = i+dx[k];
    int y = j+dy[k];
    if (x < 0 || x >= r || y < 0 || y >= c) continue;
    if (grid[convert(x,y)]) continue;
    if (check_deg(x,y)) continue;
    update_deg(x,y,1);
    grid[convert(x,y)] = 1;
    ans.push_back(moves[k]);
    cnt++;
    solve(x,y);
    cnt--;
    ans.pop_back();
    grid[convert(x,y)] = 1;
    update_deg(x,y,1);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--){
    cin >> r >> c >> i >> j;
    i--; j--;
    memset(grid, 0, sizeof grid);
    memset(deg, 0, sizeof deg);
    cnt = 1;
    grid[convert(i,j)] = 1;
    found = 0;
    solve(i,j);
    if (!found) cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
