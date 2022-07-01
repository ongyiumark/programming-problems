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

vector<vector<int>> perms = {{0,1,2}, {0,2,1}, {1,0,2}, {1,2,0}, {2,0,1}, {2,1,0}};

void solve(int i) {
  for (int j = 0; j < 6; j++) {
    
  }
}

void testcase(){
  int E, W; cin >> E >> W;
  if (W > 3 || E > 10) {
    // Ignore hidden test
    cout << 0 << endl;
    return;
  }
  int exer[E][W];
  for (int i = 0; i < E; i++){
    for (int j = 0; j < W; j++) {
      cin >> exer[i][j];
    }
  }

  solve(0)
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  for (int x = 1; x <= t; x++) {
    cout << "Case #" << x << ": ";
    testcase();
  }
  
  return 0;
}
