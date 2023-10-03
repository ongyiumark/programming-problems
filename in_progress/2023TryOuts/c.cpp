#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, p, s; cin >> n >> p >> s;
  for (int i = 0; i < s; i++) {
    int m; cin >> m;

    bool found = false;
    for (int j = 0; j < m; j++) {
      int x; cin >> x;
      if (x == p) found = true;
    }
    cout << (found ? "KEEP" : "REMOVE") << "\n";
  }
  return 0;
}
