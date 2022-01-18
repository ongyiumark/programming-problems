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

const int N = 6e5;
ll ans[N];
ll pref[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string x; cin >> x;
  int n = x.size();
  memset(ans, 0, sizeof ans);
  for (int i = 0; i < n; i++){
    pref[i] = x[i]-'0';
    if (i != 0) pref[i] += pref[i-1];
  }

  for (int i = n-1; i >=0; i--) {
    ans[n-i-1] += pref[i];
  }
  int last = 0;
  int carry = 0;
  for (int i = 0; i < N; i++){
    ans[i] += carry;
    carry = ans[i]/10;
    ans[i] %= 10;
    if (ans[i] != 0) last = i;
  }
  for (int i = last; i >= 0; i--) {
    cout << ans[i];
  }
  cout << endl;
  return 0;
}
