/*
  Start from the top and check if its a perfect power.
  
  To check if its a perfect power, we prime factorize.
  Let m be the minimum exponent in the prime factorization.
  m must be at least 2, and all the other exponents must be a multiple of m.
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

bool valid(int x){
  if (x == 1) return true;
  map<int,int> factors;
  for (int i = 2; i*i <= x; i++){
    while(x % i == 0){
      factors[i]++;
      x /= i;
    }
  }
  if (x > 1) factors[x]++;

  int p = 1e9;
  for (auto it : factors){
    p = min(p, it.second);
  }
  if (p == 1) return false;

  bool valid = 1;
  for (auto it : factors){
    valid &= (it.second%p == 0);
  }
  return valid;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int x; cin >> x;
  for (int i = x; i >= 1; i--){
    if (valid(i)) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
