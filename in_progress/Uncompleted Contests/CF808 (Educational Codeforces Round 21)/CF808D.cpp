/*
  Try every prefix/suffix. Get the difference of the their sums.
  Check if they include the number you are looking for to balance the sum. 
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
ll a[N], pref[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  pref[0] = 0;
  for (int i = 0; i < n; i++) {
    pref[i+1] = pref[i] + a[i];
  }

  map<ll, int> sufcnt, prefcnt;
  for (int i = n-1; i >= 0; i--) {
    sufcnt[a[i]]++;
  }

  bool valid = 0;
  for (int i = 0; i < n; i++) {
    ll L = pref[i+1];
    ll R = pref[n]-pref[i+1];
    sufcnt[a[i]]--;
    prefcnt[a[i]]++;

    ll need = abs(L-R);
    if (need%2 != 0) continue;

    if (L > R && prefcnt[need/2]) valid = 1;
    if (L < R && sufcnt[need/2]) valid = 1;
    if (L == R) valid = 1;
  }

  cout << (valid ? "YES" : "NO") << endl;

  return 0;
}
