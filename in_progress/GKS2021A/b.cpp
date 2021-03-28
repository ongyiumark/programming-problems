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

const int N = 1000;
bool grid[N][N];
int pref[N][N];
int r, c;

bool checkseg(int i, int j, int l, bool row){
  int total = 0;
  if (row){
    if (i+l-1 >= r) return false;
    total = pref[i+l-1][j];
    if (i > 0) total -= pref[i-1][j];
    if (j > 0) total -= pref[i+l-1][j-1];
    if (i > 0 && j > 0) total += pref[i-1][j-1];
  }
  else {
    if (j+l-1 >= c) return false;
    total = pref[i][j+l-1];
    if (j > 0) total -= pref[i][j-1];
    if (i > 0) total -= pref[i-1][j+l-1];
    if (i > 0 && j > 0) total += pref[i-1][j-1];
  }
  return total == l;
}

void testcase(){
  cin >> r >> c;
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      cin >> grid[i][j];
      pref[i][j] = 0;
    }
  }

  pref[0][0] = grid[0][0];
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      if (i == 0 && j == 0) continue;
      if (i == 0) pref[i][j] = pref[i][j-1] + grid[i][j];
      else if (j == 0) pref[i][j] = pref[i-1][j] + grid[i][j];
      else pref[i][j] = pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1] + grid[i][j];
    }
  }


  int cnt = 0;

  for (int l = 2; l <= c && 2*l <= r; l++){
    for (int i = 0; i < r; i++){
      if (!(i+1 >= 2*l || r-i >= 2*l)) continue;
      for (int j = 0; j+l-1 < c; j++){
        if (checkseg(i, j, l, 0)){
          if (r-i >= 2*l){
            if (checkseg(i, j, 2*l, 1)) cnt += 1;
            if (checkseg(i, j+l-1, 2*l,1)) cnt += 1;
          }
          
          if (i+1 >= 2*l){
            if (checkseg(i-2*l+1, j, 2*l, 1)) cnt += 1;
            if (checkseg(i-2*l+1, j+l-1, 2*l,1)) cnt += 1;
          }
        }
      }
    }
  }

  for (int l = 2; l <= r && 2*l <= c; l++){
    for (int j = 0; j < c; j++){
      if (!(j+1 >= 2*l || c-j >= 2*l)) continue;
      for (int i = 0; i+l-1 < r; i++){
        if (checkseg(i, j, l, 1)){
          if (c-j >= 2*l){
            if (checkseg(i, j, 2*l, 0)) cnt += 1;
            if (checkseg(i+l-1, j, 2*l, 0)) cnt += 1;
          }
          
          if (j+1 >= 2*l){
            if (checkseg(i, j-2*l+1, 2*l, 0)) cnt += 1;
            if (checkseg(i+l-1, j-2*l+1, 2*l, 0)) cnt += 1;
          }
        }
      }
    }
  }
  cout << cnt << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  for (int x = 1; x <= t; x++){
    cout << "Case #" << x << ": ";
    testcase();
  }
  return 0;
}
