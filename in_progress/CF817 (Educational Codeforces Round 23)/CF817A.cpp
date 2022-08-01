/*
  It's possible iff the difference is divisible and the quotients have the same parity.
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
  int a, b, c, d; cin >> a >> b >> c >> d;
  int x,y; cin >> x >> y;
  if ((a-c)%x == 0 && (b-d)%y == 0 && (abs(b-d)/y)%2 == (abs(a-c)/x)%2) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
