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

ll solve(ll S, ll k, ll a_max) {
  // k = a^b
  // S = a+b = (a^b) + 2*(a&b)
  if ((S-k)&1) return -1; // S-k is odd
  ll a = (S-k)/2;

  // If a bit is in both, then it can't be in XOR
  if (a&k) return -1;

  if (a > a_max) return -1; // minimum 'a' is too large

  for (ll i = 60; i >= 0; i--) {
    if ((1LL<<i)&k and (a + (1LL<<i) <= a_max)) {
      a += (1LL<<i);
    } 
  }

  // cannot move all
  if (a == 0) return -1;
  return a_max-a;
} 

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  vector<ll> A(n);
  for (ll &x : A) cin >> x;
  ll k = 0;
  for (int i = 2; i < n; i++) k ^= A[i];

  ll S = A[0]+A[1];

  cout << solve(S, k, A[0]) << "\n";
  return 0;
}
