/*
  Check if I is in P with two pointers.
  Then, the answer is len(P)-len(I).
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

void testcase(){
  string I, P; cin >> I >> P;
  int n, m;
  n = I.size();
  m = P.size();
  int iidx = 0; int pidx = 0;
  while (pidx < m){
    if (I[iidx] == P[pidx]) {
      iidx++; pidx++;
    }
    else pidx++;
    if (iidx == n){
      cout << abs(n-m) << endl;
      return;
    }
  }
  cout << "IMPOSSIBLE" << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  for (int x = 1; x <= T; x++) {
    cout << "Case #" << x << ": ";
    testcase();
  }
  
  return 0;
}
