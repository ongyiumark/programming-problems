#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void testcase(){
  int n, k; cin >> n >> k;
  if (k == 1) {
    cout << "YES\n";
    for (int i = 1; i <= n; i++){
      cout << i << '\n';
    }
    return;
  }
  if (n%2 == 0) {
    int a[n][k];
    int curr = 0;
    for (int j = 0; j < k; j++){
      for (int i = 0; i < n; i++){
        curr += 1;
        a[i][j] = curr;
      }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++){
      for (int j = 0; j < k; j++){
        cout << a[i][j] << " ";
      }
      cout << "\n";
    }
    return;
  }
  cout << "NO\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  for (int i = 0; i < t; i++) {
    testcase();
  }
  return 0;
}
