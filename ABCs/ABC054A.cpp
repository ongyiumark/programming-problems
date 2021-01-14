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

  int a, b; cin >> a >> b;
  if (a == 1) a = 14;
  if (b == 1) b = 14;

  if (a > b) cout << "Alice";
  else if (a < b) cout << "Bob";
  else cout << "Draw";
  cout << endl;
  return 0;
}
