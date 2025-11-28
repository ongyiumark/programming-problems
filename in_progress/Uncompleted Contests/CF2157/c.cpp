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
  cin.tie(0)->sync_with_stdio(false);
  
  int t; cin >> t;
  while (t--) {
    int n, k, q;
    cin >> n >> k >> q;
    vector<tuple<int,int,int>> constraints(q);
    vector<int> a(n,-1);

    vector<bool> no_k(n,0);
    vector<bool> bigger_k(n,0);
    for (int i = 0; i < q; i++) {
      int c, l, r; cin >> c >> l >> r;
      l--; r--;
      constraints[i] = {c,l,r};
    }

    for (int i = 0; i < q; i++) {
      auto [c,l,r] = constraints[i];
      for (int j = l; j <= r; j++) {
        if (c == 1) bigger_k[j] = 1;
        if (c == 2) no_k[j] = 1;
      }
    }

    for (int j = 0; j < n; j++) {
      // a[j] >= k but a[j] != k
      if (bigger_k[j] && no_k[j]) a[j] = k+1;
      else if (bigger_k[j]) a[j] = k;
      else if (no_k[j]) a[j] = -1;
      else a[j] = k+1;
    }



    for (int i = 0; i < q; i++) {
      auto [c,l,r] = constraints[i];
      if (c == 2) {
        vector<bool> has_val(k);
        for (int j = l; j <= r; j++) {
          if (a[j] == -1) continue;
          if (a[j] >= k) continue;
          has_val[a[j]] = 1;
        }

    cout << l << " " << r << ":" << endl; 
    for (int j = 0; j < n; j++) {
      cout << a[j] << " \n"[j+1>=n];
    }
        for (int j = l, v = 0; j <= r; j++) {
          while(v < k && has_val[v]) v++;
          if (a[j] == -1) {
            if (v != k) {
              a[j] = v;
              has_val[v] = 1;
            }
          }
        }
      }
    }

    for (int j = 0; j < n; j++) {
      if (a[j] == -1) a[j] = k+1;
    }

    for (int j = 0; j < n; j++) {
      cout << a[j] << " \n"[j+1>=n];
    }

    //verify
    // for (int i = 0; i < q; i++) {
    //   auto [c,l,r] = constraints[i];
    //   if (c == 1) {
    //     int min_a = 1e9;
    //     for (int j = l; j <= r; j++) {
    //       min_a = min(min_a, a[j]);
    //     }
    //     assert(min_a == k);
    //   }
    //   if (c == 2) {
    //     vector<bool> has_val(k);
    //     for (int j = l; j <= r; j++) {
    //       assert(a[j] != k);
    //       if (a[j] < k) has_val[a[j]] = 1;
    //     }
    //     bool valid = true;
    //     for (int v = 0; v < k; v++) {
    //       valid &= has_val[v];
    //     }

    //     assert(valid);
    //   }
    // }
  }
  return 0;
}
