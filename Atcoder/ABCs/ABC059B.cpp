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
  string a, b; cin >> a >> b;
  int n = a.size();
  int m = b.size();
  int ans = 0;
  if (n > m) ans = 1;
  else if (n < m) ans = -1;
  else {
    for (int i = 0; i < n; i++){
      if (a[i] > b[i]) {
        ans = 1;
        break;
      }
      if (a[i] < b[i]) {
        ans = -1;
        break;
      }
    }
  }

  if (ans == 1) cout << "GREATER";
  else if (ans == -1) cout << "LESS";
  else cout << "EQUAL";
  cout << endl; 
  return 0;
}
