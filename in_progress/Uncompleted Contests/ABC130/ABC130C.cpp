/*
  You can always split the rectangle in half my making the line pass through the center.
  Thus, the line is unique if (x,y) is anything but the center.
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
  ll w, h, x, y; cin >> w >> h >> x >> y;

  cout << (ld)w*h/2 << " " << (int)(2*x == w && 2*y == h) << endl;
  return 0;
}
