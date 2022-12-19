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

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vi a(n);
    for (int &x : a) cin >> x;
    int hians = 0;
    int loans = 0;
    for (int k = 0; k < 10; k++) {
      int hi = 0;
      int lo = 1;
      for (int i = 0; i < n; i++) {
        if ((1<<k)&a[i]) hi = 1;
        else lo = 0;
      }

      if (hi) hians |= (1<<k);
      if (lo) loans |= (1<<k);

      //if (hi || lo) cout << k << " " << lo << " " << hi << endl;
    }
    cout << hians - loans << "\n";
  }

  
  return 0;
}
