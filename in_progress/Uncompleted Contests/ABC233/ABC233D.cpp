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
ll A[N];
ll pref[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, k; cin >> n >> k;
  for (int i = 0; i < n; i++){
    cin >> A[i];
  }

  pref[0] = 0;
  for (int i = 0; i < n; i++) {
    pref[i+1] = pref[i] + A[i];
  }
  map<ll,int> cnt;
  ll ans = 0;
  for (int i = 0; i < n+1; i++){
    ans += cnt[pref[i]-k];
    cnt[pref[i]]++;
  }
  cout << ans << endl;
  return 0;
}
