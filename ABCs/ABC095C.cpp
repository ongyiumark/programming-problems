/*
  Let m = min(x,y).
  First, you need m A-pizzas and m B-pizzas. 
  You can either buy m A-pizzas and m B-pizzas or 2m AB-pizzas.

  WLOG suppose x >= y.
  Next, you need to buy x-m A-pizzas.
  The optimal x-m A-pizzas or 2*(x-m) AB-pizzas.
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
  
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int lo = min(x,y);
  ll ans = lo*min(a+b,2*c);
  x -= lo;
  y -= lo;

  ans += x*min(a, 2*c);
  ans += y*min(b, 2*c);
  cout << ans << endl;
  return 0;
}
