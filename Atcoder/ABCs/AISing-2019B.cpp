/*
  Get the minimum of how many first, second, and third problems there are.
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, a, b;
  cin >> n >> a >> b;
  int p[n];
  for (int i = 0; i < n; i++) cin >> p[i];
  int lo, mid, hi;
  lo = mid = hi = 0;
  for (int i = 0; i < n; i++) {
    lo += (p[i] <= a);
    mid += (p[i] >= a+1 && p[i] <= b);
    hi += (p[i] >= b+1);
  }

  cout << min({lo,mid,hi}) << endl;
  return 0;
}
