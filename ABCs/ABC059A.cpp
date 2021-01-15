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

  string a, b, c; cin >> a >> b >> c;
  int diff = 'A'-'a';
  cout << (char)(a[0]+diff) << (char)(b[0]+diff) << (char)(c[0]+diff) << endl;
  return 0;
}
