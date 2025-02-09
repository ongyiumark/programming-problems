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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m, k; cin >> n >> m >> k;
  vector<ll> A(n), B(m);
  for (ll &x : A) cin >> x;
  for (ll &x : B) cin >> x;

  vector<ll> PA(n+1), PB(m+1);
  for (int i = 0; i < n; i++) PA[i+1] = PA[i] + A[i];
  for (int i = 0; i < m; i++) PB[i+1] = PB[i] + B[i];

  int ans = 0;
  for (int i = 0; i <= n; i++) {
    if (PA[i] > k) break;
    int lo = 0;
    int hi = m;
    int j = 0;
    while (lo <= hi) {
      int mid = hi - (hi-lo)/2;
      if (PA[i]+PB[mid] <= k) {
        j = mid;
        lo = mid+1;
      }
      else hi = mid-1;
    }

    ans = max(i + j, ans);
  }

  cout << ans << "\n";
  
  return 0;
}
