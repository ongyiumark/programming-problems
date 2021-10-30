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

const int N = 2e5+5;
int n, m;
int u[N], s[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> u[i];
  for (int i = 0; i < m; i++) cin >> s[i];

  for (int i = 0; i < m; i++) {
    int cnt = 0;
    for (int j = 0; j <= i; j++){
      cnt += min(u[j], s[i]);
      u[j] = max(0, u[j]-s[i]);
    }
    cout << cnt;
    if (i == m-1) cout << "\n";
    else cout << " ";
  }
  return 0;
}
