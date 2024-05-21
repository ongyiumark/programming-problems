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
  int n, m; cin >> n >> m;
  int count[n];
  memset(count, 0, sizeof count);
  for (int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--; b--;
    count[a]++;
    count[b]++;
  }
  for (int i = 0; i < n; i++){
    cout << count[i] << endl;
  }
  return 0;
}
