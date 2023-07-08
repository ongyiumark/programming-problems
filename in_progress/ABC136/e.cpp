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

bool solve(ll d, ll k, vector<ll> &A) {
  int n = A.size();
  vector<ll> rem(n);
  for (int i = 0; i < n; i++) rem[i] = A[i]%d;
  sort(rem.rbegin(), rem.rend());

  if (all_of(rem.begin(), rem.end(), [](ll r){ return r == 0; })) return true;

  vector<ll> pr(n);
  pr[0] = rem[0];
  for (int i = 1; i < n; i++) pr[i] = pr[i-1] + rem[i];

  for (ll i = 0; i < n; i++) {
    if ((i+1)*d == pr[n-1] && (pr[n-1]-pr[i] <= k)) return true;
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, k; cin >> n >> k;
  vector<ll> A(n);
  for (ll &x : A) cin >> x;
  ll S = 0;
  for (ll &x: A) S += x;

  ll ans = 0;
  for (ll d = 1; d*d <= S; d++) {
    if (S % d != 0) continue;
    if (solve(d, k, A)) ans = max(ans, d);
    if (d*d != S && solve(S/d, k, A)) ans = max(ans, S/d);
  }
  cout << ans << "\n";
  
  return 0;
}
