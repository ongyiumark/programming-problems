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
  int t; cin >> t;
  while(t--){
    int m; cin >> m;

    if (m%4 == 0){
      cout << m << endl;
      cout << 1;
      for (int i = 2; i <= m ; i++){
        cout << " " << i;
      }
      cout << endl;
    }
    else if (m%4 == 1){
      cout << (m == 1 ? 1 : m-1) << endl;
      for (int i = 1; i < m-1; i++){
        cout << i << " ";
      }
      cout << m << endl;
    }
    else if (m%4 == 2) {
      cout << m-1 << endl;

      for (int i = 2; i <= m; i++){
        cout << i;
        if (i == m) cout << endl;
        else cout << " "; 
      }
    }
    else {
      cout << m-1 << endl;
      for (int i = 1; i < m; i++){
        cout << i;
        if (i == m-1) cout << endl;
        else cout << " "; 
      }
    }
  }
  return 0;
}
