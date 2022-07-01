/*
  Snake pattern.
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int h, w; cin >> h >> w;
  int n; cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];

  int grid[h][w];
  int idx = 0;
  while(a[idx] == 0) idx++;
  for (int i = 0; i < h; i++) {
    for (int j = (i%2 ? w-1 : 0); 0 <= j && j < w; j += (i%2 ? -1 : 1)) {
      grid[i][j] = idx+1;
      a[idx]--;
      while (a[idx] == 0) idx++; 
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << grid[i][j];
      if (j != w-1) cout << " ";
      else cout << endl;
    }
  }

  return 0;
}
