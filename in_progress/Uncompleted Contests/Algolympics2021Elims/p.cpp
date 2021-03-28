/*
  We just need to precompute the number of divisors from n to n+3e6.
  We can do this by sieving the primes up to 1e6.
  Then, for every number between n and n+3e6, we divide out all primes below 1e6.
  We can efficiently do this by starting at ceil(n/p)*p and incrementing by p.
    This way, we guarantee that the number we're currently deadling with is divisible by p.
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

const ll LIM = 1e12;
const int N = 1e6+1;
const int K = 5e6+5;
bool is_composite[N];
ll nums[K], ans[K];
vector<ll> primes;
ll hi, n;
ll lim = 3000005;

void sieve(){
  memset(is_composite, 0, sizeof is_composite);
  for (int i = 2; i < N; i++){
    if (!is_composite[i]) primes.push_back(i);
    for (int j = 0; j < (int)primes.size() && i*primes[j] < N; j++){
      is_composite[i*primes[j]] = 1;
      if (i % primes[j] == 0) break;
    }
  }
}

void precompute(ll n, ll k){
  for (int i = 0; i < lim; i++) {
    nums[i] = n+i;
    ans[i] = 1;
  }
  for (ll p : primes){ 
    ll start = (n+p-1)/p*p;
    for (int i = start-n; i < lim; i+=p){
      ll tmp = 1;
      while(nums[i] % p == 0){
        nums[i]/=p;
        tmp++;
      }
      ans[i] *= tmp;
    }
  }

  for (int i = 0; i < lim; i++){
    if (nums[i] == n+i) ans[i] = 2;
    else if (nums[i] > 1) ans[i] *= 2;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);  
  srand(time(NULL));
  sieve();
  
  int t; cin >> t;
  while(t--){
    ll k; cin >> n >> k;
    if (n == 1){
      cout << "SWINDLED" << "\n";
      continue;
    }

    precompute(n,k);
    int cnt = 0;
    ll tmp = n;
    hi = ans[0];
    while(cnt<k){
      tmp++;
      if (ans[tmp-n] <= hi) cnt++; 
    }
    cout << tmp << "\n";
  }
  return 0;
}
