/*
  Keep two pointers while looping through the start times.
  Left point keeps track of start, and right pointer keeps track of end. 
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

const int N = 2e5+5;
int T[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, t; cin >> n >> t;
  for (int i = 0; i < n; i++) {
    cin >> T[i];
  }

  ll ans = 0;
  int prev = 0;
  int curr = 0;
  for (int i = 0; i < n; i++){
    prev = max(prev, T[i]);
    curr = max(curr, T[i]+t);
    ans += (curr-prev);
    prev = curr;
  }
  cout << ans << endl;
  return 0;
}
