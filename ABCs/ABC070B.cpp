/*
   Go through 0 to 100 and count if its between both constraints.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int cnt = 0;
  for (int i = 0; i <= 100; i++){
    cnt += (a <= i && c <= i && i < b && i < d);
  }
  cout << cnt << endl;
  return 0;
}
