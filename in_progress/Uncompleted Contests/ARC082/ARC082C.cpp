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

const int N = 1e5+5;
int a[N];
int cnt[N];
int n;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; i++) {
    cnt[a[i]]++;
    cnt[a[i]+1]++;
    if (a[i] > 0) cnt[a[i]-1]++;
  }
  
  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans = max(ans, cnt[i]);
  }
  cout << ans << endl;
  return 0;
}
