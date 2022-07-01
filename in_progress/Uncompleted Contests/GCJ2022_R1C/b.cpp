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
  int n, k; cin >> n >> k;
  vector<ll> E(n);
  for (int i = 0; i < n; i++) cin >> E[i];

  ll T = 0;
  ll square_of_sum = 0, sum_of_square = 0;
  for (int i = 0; i < n; i++) {
    sum_of_square += E[i]*E[i];
    square_of_sum += E[i];
    T += E[i];
  }
  square_of_sum *= square_of_sum;



  ll S = (sum_of_square-square_of_sum)/2;

  ll rem = S%T;
  if (rem == 0) {
    cout << S/T << endl;
    return;
  }
  cout << "REM " << rem << endl;
  
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  for (int x = 1; x <= t; x++) {
    cout << "Case #" << x << ": ";
    testcase();
  }
  
  return 0;
}
