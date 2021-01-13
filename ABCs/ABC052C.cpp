/*
  Prime factorize the factorial.
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

const int MOD = 1e9+7;
const int N = 1001;
bool is_composite[N];
vector<int> primes;
map<int, int> factors;

void sieve(){
  memset(is_composite, 0, sizeof is_composite);
  for (int i = 2; i < N; i++){
    if (!is_composite[i]) primes.push_back(i);
    for (int j = 0; j < primes.size() && i*primes[j] < N; j++){
      is_composite[i*primes[j]] = true;
      if (i % primes[j] == 0) break;
    }
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  sieve();

  int n; cin >> n;
  for (int i = 0; i < primes.size(); i++){
    int x = primes[i];
    int cnt = 0;
    while(x <= n){
      cnt += n/x;
      x *= primes[i];
    }

    factors[primes[i]] = cnt;
  }

  ll ans = 1;
  for (int i = 0; i < primes.size(); i++){
    ans = (ans * (factors[primes[i]]+1))%MOD;
  }
  cout << ans << endl;
  return 0;
}
