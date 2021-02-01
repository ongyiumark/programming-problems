/*
  If all the primes chosen have the same last digit, the sum of any 5 will be divisible by 5.
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

const int N = 55555;
bool is_composite[N+1];
vector<int> primes;
vector<int> three_primes;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  memset(is_composite, 0, sizeof is_composite);
  for (int i = 2; i <= N; i++){
    if (!is_composite[i]) primes.push_back(i);
    for (int j = 0; j < primes.size() && i*primes[j] <= N; j++){
      is_composite[i*primes[j]] = 1;
      if (i%primes[j] == 0) break;
    }
  }

  for (int p : primes){
    if (p%10 == 3) three_primes.push_back(p);
  }
  int n; cin >> n;
  for (int i = 0; i < n; i++){
    cout << three_primes[i];
    cout << (i == n-1 ? "\n" : " "); 
  }
  return 0;
}
