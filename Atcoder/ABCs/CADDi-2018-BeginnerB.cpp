/*
  Apparently, we just need to check if h by w fits inside a[i] by b[i].
  We don't need to count how many can fit inside each material.
  Instead, count how many materials can be used.

  The wording is bad.
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
  ll h,w; cin >> h >> w;
  ll a[n], b[n];
  ll total = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    total += int((a[i]/h)*(b[i]/w) > 0);
  }
  cout << total << endl;
  return 0;
}
