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

bool parity(ii a, ii b) {
  return ((a.first%2 == b.first%2) || (a.second%2 == b.second%2));
}
void testcase() {
  int n; cin >> n;
  ii p[3];
  for (int i = 0; i < 3; i++) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p, p+3);
  int type = 0;
  if (p[0].first == p[1].first) {
    if (p[0].second == p[2].second) type = 4;
    else type = 2;
  }
  else {
    if (p[0].second == p[1].second) type = 1;
    else type = 3;
  }

  int x, y; cin >> x >> y;
  bool val = 0;
  if (type == 1) {
    if (p[1].first == n && p[1].second == 1) {
      if (x == n || y == 1) val = 1;
    }
    else {
      if (parity(p[1], {x,y})) val = 1;
    }
  }
  else if (type == 2) {
    if (p[1].first == 1 && p[1].second == n) {
      if (x == 1 || y == n) val = 1;
    }
    else {
      if (parity(p[1], {x,y})) val = 1;
    }
  }
  else if (type == 3) {
    if (p[2].first == n && p[2].second == n) {
      if (x == n || y == n) val = 1;
    }
    else {
      if (parity(p[2], {x,y})) val = 1;
    }
  }
  else {
    if (p[0].first == 1 && p[0].second == 1) {
      if (x == 1 || y == 1) val = 1;
    }
    else {
      if (parity(p[0], {x,y})) val = 1;
    }
  }

  if (val) cout << "YES";
  else cout << "NO";
  cout << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--) testcase();
  return 0;
}
