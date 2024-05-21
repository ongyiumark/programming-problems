/*
  Keep pushing the odd numbers to the next cell.
  Do this in a zigzag formation.
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

const int N = 500;
int grid[N][N];

struct moves{
  int a,b,c,d;
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int h, w; cin >> h >> w;
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      cin >> grid[i][j];
    }
  }
  vector<moves> ans;
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w && i%2==0; j++){
      int ni = i;
      int nj = j;
      if (j < w-1) nj++;
      else ni++;
      if (ni >= h) break;
      if (grid[i][j]&1) {
        grid[i][j]--;
        grid[ni][nj]++;
        ans.push_back({i,j, ni,nj});
      }
    }

    for (int j = w-1; j >= 0 && i%2==1; j--){
      int ni = i;
      int nj = j;
      if (j > 0) nj--;
      else ni++;
      if (ni >= h) break;
      if (grid[i][j]&1) {
        grid[i][j]--;
        grid[ni][nj]++;
        ans.push_back({i,j, ni,nj});
      }
    }
  }

  cout << ans.size() << endl;
  for (auto m : ans){
    cout << m.a+1 << " " << m.b+1 << " " << m.c+1 << " " << m.d+1 << endl;
  }
  return 0;
}
