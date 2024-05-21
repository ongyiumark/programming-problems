/*
  Notice that if there are an even number of negatives, we can make everything positive.
  If there are an odd number of negative, we can leave 1 number negative.
    It's optimal to leave the smallest absolute valued number as negative.
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

const int N = 1e5+5;
ll A[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];
  int negCnt = 0;
  ll lo = 1e18;
  ll total = 0;
  for (int i = 0; i < n; i++) {
    total += abs(A[i]);
    if (A[i] < 0) negCnt++;
    lo = min(lo, abs(A[i]));
  }
  if (negCnt&1) total -= 2*lo;
  
  cout << total << endl;
  return 0;
}
