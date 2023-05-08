/*
  Fix c, then prime factorize n-c to count the number of divisors.
  We can also sieve the number of divisors to do this faster.
*/

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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  ll total = 0;
  for (int c = 1; c < n; c++) {
    unordered_map<int,int> fact;
    int p = n-c;
    for (int d = 2; d*d <= p; d++) {
      while (p%d == 0) {
        fact[d]++;
        p /= d;
      }
    }
    if (p > 1) fact[p]++;

    ll div = 1;
    for (auto [prime, mult] : fact) {
      div *= (mult+1);
    }

    total += div;
  }
  cout << total << "\n";

  return 0;
}
