/*
  Use a difference array to increment a range of values.
  A value of x would increase x-1, x, and x+1 by 1.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5;
int cnt[N+5];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for (int i = 0; i < n; i++){
    int a; cin >> a;
    if (a-1 >= 0) cnt[a-1]++;
    else cnt[a]++;
    cnt[a+2]--;
  }

  for (int i = 1; i <= N; i++){
    cnt[i] += cnt[i-1];
  }

  int ans = 0;
  for (int i = 0; i <= N; i++){
    ans = max(ans, cnt[i]);
  }
  cout << ans << endl;
  return 0;
}
