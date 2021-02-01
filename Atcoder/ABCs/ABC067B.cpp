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

  int n, k; cin >> n >> k;
  int l[n];
  for (int i = 0; i < n; i++){
    cin >> l[i];
  }
  sort(l, l+n, greater<int>());
  int total = 0;
  for (int i = 0; i < k; i++){
    total += l[i];
  }
  cout << total << endl;
  return 0;
}
