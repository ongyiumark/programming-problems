/*
  Group each cell into contiguous rows and contiguous columns with DSU.
  The answer is [count of row group] + [count of column group] - 1.
*/
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

const int N = 2000+1;
bool grid[N][N];

struct dsu{
  vector<int> p;
  dsu(int n) : p(n, -1){}

  int find(int x){
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
  }

  bool unite(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (p[a] < p[b]) swap(a,b);
    p[b] += p[a];
    p[a] = b;
    return true;
  }
};

dsu row(N*N);
dsu col(N*N);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; i++){
    string s; cin >> s;
    for (int j = 0; j < w; j++){
      grid[i][j] = (s[j] == '#');
    }
  }

  for (int i = 0; i < h; i++){
    for (int j = 1; j < w; j++){
      if (grid[i][j]) continue;
      if (grid[i][j-1]) continue;
      row.unite(i*w+j, i*w+j-1); 
    }
  }

  for (int j = 0; j < w; j++){
    for (int i = 1; i < h; i++){
      if (grid[i][j]) continue;
      if (grid[i-1][j]) continue;
      col.unite((i-1)*w+j, i*w+j); 
    }
  }

  int best = 0;
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      if (grid[i][j]) continue;
      int a = col.find(i*w+j);
      int b = row.find(i*w+j);
      best = max(best, -col.p[a]-row.p[b]-1);
    }
  }

  cout << best << endl;
  return 0;
}
