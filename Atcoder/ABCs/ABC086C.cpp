/*
  It's possible to go from point a to point b if the following are true:
    (1) the time is greater than or equal to the manhanttan distance
    (2) the time and the manhattan distance have the same parity
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
  
  int n; cin >> n;
  int cx, cy, ct;
  cx = cy = ct = 0;
  bool valid = 1;
  for (int i = 0; i < n; i++){
    int t, x, y;
    cin >> t >> x >> y;
    int nt = t-ct;
    int dist = abs(cx-x)+abs(cy-y);

    if (nt < dist || nt%2 != dist%2) valid = 0;
    ct = t;
    cx = x;
    cy = y;
  }
  cout << (valid ? "Yes" : "No") << endl;
  return 0;
}
