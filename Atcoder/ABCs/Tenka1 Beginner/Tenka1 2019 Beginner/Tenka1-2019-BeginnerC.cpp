/*
  The idea is that the final result must be a string of whites follows by a string of blacks.
  For example, ........#######

  We can fix the point where white turns to black and we can comput the cost in O(1) with prefix sums.
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
int wPref[N], bPref[N];
string s;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  cin >> s;

  for (int i = 0; i < n; i++){
    wPref[i] = (s[i] == '.');
    bPref[i] = (s[i] == '#');

    if (i > 0) {
      wPref[i] += wPref[i-1];
      bPref[i] += bPref[i-1];
    }
  }  

  int lo = 1e6;
  for (int i = 0; i <= n; i++){
    // i whites, n-i blacks
    int tmp = 0;
    if (i > 0) tmp += bPref[i-1];

    tmp += wPref[n-1];
    if (i > 0) tmp -= wPref[i-1];

    lo = min(tmp, lo);
  }
  cout << lo << endl;
  
  return 0;
}
