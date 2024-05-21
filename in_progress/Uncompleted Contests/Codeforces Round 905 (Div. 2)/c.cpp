#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void testcase() {
  int n; cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  vector<bool> is_first(n), is_last(n);
  set<int> seen;
  for (int i = 0; i < n; i++) {
    if (seen.find(a[i]) != seen.end()) continue;
    is_first[i] = true;
    seen.insert(a[i]);
  } 

  seen.clear();
  for (int i = n-1; i >= 0; i--) {
    if (seen.find(a[i]) != seen.end()) continue;
    is_last[i] = true;
    seen.insert(a[i]);
  }

  vector<int> pref_first(n), suff_last(n);
  for (int i = 0; i < n; i++) {
    pref_first[i] = is_first[i];
    if (i > 0) pref_first[i] += pref_first[i-1];
  }
  for (int i = n-1; i >= 0; i--) {
    suff_last[i] = is_last[i];
    if (i < n-1) suff_last[i] += suff_last[i+1];
  }

  ll cnt = 0;
  for (int i = 0; i < n; i++) {
    if (!is_first[i]) continue;
    cnt += suff_last[i];
  }
  cout << cnt << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while (t--) testcase();
  
  return 0;
}
