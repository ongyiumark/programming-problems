#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<vector<char>> grid;

ll manhattan (pii a, pii b){
  return abs(a.first-b.first) + abs(a.second-b.second);
}

void testcase() {
  int r, c; cin >> r >> c;
  grid.resize(r);

  pii curr;
  map<char, pii> loc;
  for (int i = 0; i < r; i++) {
    grid[i].resize(c);
    for (int j = 0; j < c; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == '*') {
        curr = {i,j};
      }
      if (grid[i][j] != '.') {
        loc[grid[i][j]] = {i, j};
      }
    }
  }

  ll ans = 0;
  for (int i = 0; i < 26; i++) {
    if (loc.find('A'+i) != loc.end()){
      pii victim = loc['A'+i];
      pii home = loc['a'+i];
      ans += manhattan(curr, victim);
      curr = victim;
      ans += manhattan(curr, home);
      curr = home;
    }
  }
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T; cin >> T;
  for (int i = 0; i < T; i++){
    testcase();
  }
  return 0;
}
