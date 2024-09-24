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

typedef long long ll;

int main(){
  cin.tie(0)->sync_with_stdio(false);
  
  int n; cin >> n;
  vector<ll> A(n+1), B(n);
  for (ll &x : A) cin >> x;
  for (ll &x : B) cin >> x;

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll mn = min(A[i], B[i]); 
    ans += mn;
    A[i] -= mn;
    B[i] -= mn;

    mn = min(A[i+1], B[i]);
    ans += mn;
    A[i+1] -= mn;
    B[i] -= mn;
  }
  cout << ans << "\n";
  
  return 0;
}
