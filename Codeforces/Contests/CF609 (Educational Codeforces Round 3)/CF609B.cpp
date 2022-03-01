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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  int cnt[m];
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; i++){
    int a; cin >> a;
    a--;
    cnt[a]++;
  }

  int ans = 0;
  for (int i = 0; i < m; i++){
    for (int j = i+1; j < m; j++){
      ans += cnt[i]*cnt[j];
    }
  }
  cout << ans << endl;
  return 0;
}
