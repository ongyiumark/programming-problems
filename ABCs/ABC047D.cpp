/*
  It's always optimal to buy at the cheapest and sell at the most expensive.
  If you were to sell at the i-th town, you can calculate the expected profit by getting the minimum of the previous towns.
  Count the number of towns that have the same maximum profit if you were to sell in them.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5+1;
ll a[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, t;
  cin >> n >> t;
  for (int i = 0; i < n; i++) cin >> a[i];

  map<ll, int> cnt;
  ll lo = a[0];
  for (int i = 1; i < n; i++){
    lo = min(lo, a[i]);
    cnt[a[i]-lo]++;
  }

  cout << (--cnt.end())->second << endl;
  
  return 0;
}
