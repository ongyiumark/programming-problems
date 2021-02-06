/* 
  Carefully check the number of edges from the top, below, left, and right.
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

bool grid[10][10];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int h, w; cin >> h >> w;
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      char c; cin >> c;
      grid[i][j] = (c=='#');
    }
  }

  int cnt = 0;
  for (int i = 0; i < h; i++){
    if(i < h-1){
      for (int j = 0; j < w; j++){
        if (!grid[i+1][j] || grid[i][j]) continue;
        cnt++;
        while(j < w && grid[i+1][j] && !grid[i][j]) j++;
        j--;
      }
    }
    if (i > 0){
      for (int j = 0; j < w; j++){
        if (!grid[i-1][j] || grid[i][j]) continue;
        cnt++;
        while(j < w && grid[i-1][j] && !grid[i][j]) j++;
        j--;
      }
    }
  }

  for (int j = 0; j < w; j++){
    if (j < w-1){
      for (int i = 0; i < h; i++){
        if (!grid[i][j+1] || grid[i][j]) continue;
        cnt++;
        while(i < h && grid[i][j+1] && !grid[i][j]) i++;
        i--;
      }
    }

    if (j > 0){
      for (int i = 0; i < h; i++){
        if (!grid[i][j-1] || grid[i][j]) continue;
        cnt++;
        while(i < h && grid[i][j-1] && !grid[i][j]) i++;
        i--;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
