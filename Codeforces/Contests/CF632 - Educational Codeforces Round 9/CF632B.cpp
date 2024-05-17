/*
  You can compute the change in strength in O(1) with a 
    prefix array of A's and B's
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

const int N = 5e5+5;
ll p[N];
ll pref[2][N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> p[i];
  string s; cin >> s;
  pref[0][0] = pref[0][1] = 0;
  for (int i = 0; i < n; i++) {
    pref[s[i]-'A'][i+1] = p[i];
    pref[0][i+1] += pref[0][i];
    pref[1][i+1] += pref[1][i];
  }

  ll best = pref[1][n];
  for (int i = 1; i <= n; i++) {
    // prefix to i
    best = max(best, pref[1][n]-pref[1][i]+pref[0][i]);

    // suffix from i
    best = max(best, pref[1][n]-(pref[1][n]-pref[1][i-1])+(pref[0][n]-pref[0][i-1]));
  }
  cout << best << endl;
  return 0;
}
