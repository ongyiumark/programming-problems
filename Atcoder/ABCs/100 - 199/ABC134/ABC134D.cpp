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

  int n; cin >> n;
  vector<bool> a(n+1);
  for (int i = 1; i <= n; i++) {
    bool tmp; cin >> tmp;
    a[i] = tmp;  
  }
  
  vector<bool> current(n+1);
  for (int i = 1; i <= n; i++) current[i] = n/i%2;
  vector<bool> ans(n+1, 1);
  for (int i = n; i >= 1; i--) {
    if (a[i] != current[i]) {
      ans[i] = 0;

      for (int j = 1; j*j <= i; j++) {
        if (i%j != 0) continue;
        current[j] = !current[j];
        if (j*j != i) current[i/j] = !current[i/j];
      }
    }
  }

  vector<int> b;
  for (int i = 1; i <= n; i++) {
    if (not ans[i]) continue;
    b.push_back(i);
  }

  int sz = b.size();
  cout << sz << "\n";
  for (int i = 0; i < sz; i++) {
    cout << b[i] << (i+1 < sz ? " " : "\n");
  }

  return 0;
}
