/*
  Every operation will subtract 2 from the deck, so the parity never changes.
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

  set<int> distinct;
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    distinct.insert(a);
  }
  int m = distinct.size();
  if ((n&1)^(m&1)) cout << m - 1;
  else cout << m; 
  cout << endl;
  return 0;
}
