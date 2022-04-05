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

void testcase() {
  int r, c; cin >> r >> c;
  string one = "|";
  string two = "+";
  for (int i = 0; i < c; i++) {
    one += ".|";
    two += "-+";
  }

  string grid[2*r+1];
  grid[0] = two;
  for (int i = 1; i < 2*r+1; i+=2){
    grid[i] = one;
    grid[i+1] = two;
  }

  grid[0][0] = grid[0][1] = grid[1][0] = '.';

  for (int i = 0; i < 2*r+1; i++) {
    for (int j = 0; j < grid[i].size(); j++){
      cout << grid[i][j];
    }
    cout << "\n";
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  for (int x = 1; x <= t; x++) {
    cout << "Case #" << x << ":\n";
    testcase(); 
  }
  return 0;
}
