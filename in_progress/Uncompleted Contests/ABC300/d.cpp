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

const int N = 3e5+5;
bitset<N> isc;
vector<ll> primes;

void sieve() {
    for (int i = 2; i < N; i++) {
        if (!isc[i]) primes.push_back(i);
        for (int j = 0; j < (int)primes.size() && i*primes[j] < N; j++) {
            isc.set(i*primes[j]);

            if (i % primes[j] == 0) break;
        } 
    }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sieve();

  ll n; cin >> n;
  ll res = 0;
  for (int i = 0; i < (int)primes.size(); i++) {
    int k = primes.size()-1;
    for (int j = i+1; j < k; j++) {
        
        __int128 currN = (__int128)primes[i]*primes[i]*primes[j]*primes[k]*primes[k];
        while(currN > n && j < k) {
            k--;
            currN = (__int128)primes[i]*primes[i]*primes[j]*primes[k]*primes[k];
        }
        res += k-j;
    }
  }
  cout << res << "\n";
  
  return 0;
}
