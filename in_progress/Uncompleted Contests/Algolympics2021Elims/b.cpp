/*
  Compute the cost for making 1 pork gising-gising.
  The answer is floor(budget/cost).
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

const int N = 4000;
int g[N], p[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  ll b; cin >> b;
  for (int i = 0; i < n; i++) cin >> g[i];
  ll total = 0;
  for (int i = 0; i < n; i++) cin >> p[i];
  
  for (int i = 0; i < n; i++) total += g[i]*p[i];

  cout << b/total << endl;  
  return 0;
}
