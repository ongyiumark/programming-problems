/*
  Suppose g is the gcd of the list, then g^n divides P.
  We prime factorize P and multiply all the primes with multiplicity n.
    We include each prime (mult/n) times.
*/
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

ll fastpow(ll b, ll e){
  ll ans = 1;
  while(e > 0){
    if (e&1) ans *= b;
    e >>= 1;
    b *= b;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, p; cin >> n >> p;

  unordered_map<ll,int> factor;
  for (ll d = 2; d*d <= p; d++){
    while(p%d == 0){
      p/=d;
      factor[d]++;
    }
  }
  if (p > 1) factor[p]++;


  ll ans = 1;
  for (auto it : factor){
    ll cnt = it.second/n;
    ans *= fastpow(it.first, cnt);
  }

  cout << ans << endl;
  return 0;
}
