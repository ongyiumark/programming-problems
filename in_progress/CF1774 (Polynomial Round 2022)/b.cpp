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
    int n, m, k; cin >> n >> m >> k;
   
    vi a(m);
    int hi = -1e9;
    for (int &x : a) {
      cin >> x;
      hi = max(x, hi);
    }
    sort(a.rbegin(), a.rend());

    int cnt = 0;
    bool valid = 1;
    for (int i = 0; i < m && valid; i++) {
      if (a[i] > n/k+1) {
        valid = 0;
        break;
      }

      if (a[i] > n/k) cnt++;
    }   
    if (cnt > n%k) valid = 0;


    cout << (valid ? "YES" : "NO") << "\n";
  }
  
  return 0;
}
