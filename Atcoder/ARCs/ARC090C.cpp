/*
  Precompute prefix and suffix.
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
  int n; cin >> n;
  int pref[n], suff[n];
  for (int i = 0; i < n; i++) {
    cin >> pref[i];
    if (i > 0) pref[i] += pref[i-1];
  }

  for (int i = 0; i < n; i++) cin >> suff[i];
  for (int i = n-2; i >= 0; i--) suff[i] += suff[i+1];

  int hi = 0;
  for (int i = 0; i < n; i++) {
    hi = max(pref[i]+suff[i], hi);
  }   
  cout << hi << endl;
  return 0;
}
