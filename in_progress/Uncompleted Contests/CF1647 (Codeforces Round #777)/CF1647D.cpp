/*
  There's a lot of case bashing.
  
  Let d^k * y = x such that d does not divide y.

  1. Suppose that d^k | x where k >= 4. 
    Then, it's YES if either y or d is composite.
    If both d and y are prime, then it's NO.
  2. Suppose that d^3 | x
    If y is composite, then it's YES.
    If both y and d are prime, then it's NO.
    
    Suppose that y is prime and d is composite.
      If y*y = d, then it's NO.
      Otherwise, it's YES.
  3. Suppose that d^2 | x
    If y is prime, then it's NO.
    Otherwise, it's YES.
  4. It's NO.
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

bool isprime(ll x) {
  ll d = 2;
  while (d*d <= x) {
    if (x % d == 0) return false;
    d++;
  }
  return true;
}
void testcase(){
  ll x, d; cin >> x >> d;
  if (x%(d*d) != 0) {
    cout << "NO" << endl;
    return;
  } 
  x = x/d/d;

  bool dprime = isprime(d);

  if (x%d == 0 && !dprime){
    x /= d;
    if (x%d == 0) {
      cout << "YES" << endl;
      return;
    }  

    // d , d, d*x
    bool xprime = isprime(x);
    if (!xprime) {
      cout << "YES" << endl;
      return;
    }

    if (d%x != 0) {
      cout << "YES" << endl;
      return;
    }

    // d, d, d*x and d%x == 0 and x is prime
    if (d/x == x) {
      cout << "NO" << endl;
    }
    else {
      cout << "YES" << endl;
    }

    return;
  }
  
  if (x%d == 0) {
    while (x%d == 0) {
      x /= d;
    }
    cout << (isprime(x) ? "NO" : "YES") << endl;
    return;
  }

  cout << (isprime(x) ? "NO" : "YES") << endl;
  return;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--){
    testcase();
  }
  return 0;
}
