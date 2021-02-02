/*
  The digital sum of a number k in base b is k%(b-1). 
  With the exeption when k%(b-1) = 0. In this case, the digital sum is b-1.

  So, the question reduces to checking if k%x, 2k%x, 3k%x, ..., xk%x where x = b-1 is a permutation.
  k%x, 2k%x, 3k%x, ..., xk%x is a permutation if and only if gcd(x,k) = 1.
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

ll gcd(ll a, ll b){
  if (b == 0) return a;
  return gcd(b,a%b);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--){
    ll k, b; cin >> k >> b;
    b--;
    cout << (gcd(b, k)==1 ? "COOL" : "NOT COOL") << endl;
  }
  return 0;
}
