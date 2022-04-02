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

bool issqrt(int x) {
  for (int i = 1; i*i <= x; i++) {
    if (i*i == x) return true;
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--) {
    int x, y; cin >> x >> y;
    if (x == 0 && y == 0) {
      cout << 0 << endl;
      continue;
    }
    if (issqrt(x*x+y*y)) {
      cout << 1 << endl;
      continue;
    }
    cout << 2 << endl;
  }
  return 0;
}
