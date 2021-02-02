/*
  From the previous problem, we reduce this problem to that of counting coprimes.
  For each b in B, we want to know how many k's are coprime with b.

  We can prime factorize b. Suppose its prime factors are x and y.
  If we know how many elements k in K are divisible by x, divisible by y, and divisible by xy, 
    we can do inclusion-exclusion to count this.
  
  This isn't the intended solution though.
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

const int N = 3e5;
int K[N], B[N];

const int P = 1e6;
int factors[P];
bool is_composite[P];
vector<ll> primes;

void sieve(){
  memset(is_composite, 0, sizeof is_composite);
  for (int i = 2; i < P; i++){
    if (!is_composite[i]) primes.push_back(i);
    for (int j = 0; j < primes.size() && i*primes[j] < P; j++){
      is_composite[i*primes[j]] = 1;
      if (i%primes[j] == 0) break;
    }
  }
}

void factorize(ll x){
  vector<ll> curr_primes;
  for (ll p : primes){
    if (p*p > x) break;
    if (x % p == 0) curr_primes.push_back(p);
    while(x % p == 0){
      x /= p;
    }
  }
  if (x > 1) curr_primes.push_back(x);

  int n = curr_primes.size();
  for (int i = 1; i < (1<<n); i++){
    ll mod = 1;
    for (int j = 0; j < n; j++){
      if ((1<<j)&i) mod *= curr_primes[j]; 
    }
    factors[mod]++;
  }
}

ll solve(ll x){
  vector<ll> curr_primes;
  for (ll p : primes){
    if (p*p > x) break;
    if (x % p == 0) curr_primes.push_back(p);
    while(x % p == 0){
      x /= p;
    }
  }
  if (x > 1) curr_primes.push_back(x);

  int n = curr_primes.size();
  ll ret = 0;
  for (int i = 1; i < (1<<n); i++){
    ll mod = 1;
    int cnt = 0;
    for (int j = 0; j < n; j++){
      if ((1<<j)&i) {
        mod *= curr_primes[j]; 
        cnt++;
      }
    }
    if (cnt&1) ret += factors[mod];
    else ret -= factors[mod];
  }  
  return ret;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  sieve();
  memset(factors, 0, sizeof factors);
  ll k, b; cin >> k >> b;
  for (int i = 0; i < k; i++){
    cin >> K[i];
    factorize(K[i]);
  }

  ll div = 0;
  for (int i = 0; i < b; i++){
    cin >> B[i];
    B[i]--;
    div += solve(B[i]);
  }

  cout << k*b-div << "\n";
  return 0;
}
