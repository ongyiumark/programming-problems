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

const int NMAX = 1e9;
void testcase(){
  int n; cin >> n;
  ll a[n];

  a[0] = 1;
  for (int i = 1; i < 30; i++) {
    // powers of 2
    a[i] = a[i-1]*2;
  }

  map<ll, bool> taken;
  for (int i = 0; i < 30; i++) taken[a[i]] = 1;

  ll tot = 0;
  int j = 1;
  for (int i = 30; i < n-1; i++) {
    while (taken[j]) j++;
    // 1e9 to 1e9 - 70
    a[i] = j;
    tot += j;
    taken[j] = 1;
  }
  a[n-1] = tot;

  for (int i = 0; i < n; i++) {
    cout << a[i];
    if (i == n-1) cout << endl;
    else cout << " ";
  }

  ll b[n];
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  sort(b, b+n);

  vector<ll> ans;
  ll diff = 0;
  ll sumL, sumR;
  sumL = sumR = 0;
  for (int i = 0; i < n; i++) {
    if (diff > 0) {
      diff -= b[i];
      sumR += b[i];
    }
    else {
      diff += b[i];
      ans.push_back(b[i]);
      sumL += b[i];
    }
  }
  for (int i = 29; i >= 0; i--) {
    if (diff > 0) {
      diff -= a[i];
      sumR += a[i];
    }
    else {
      diff += a[i];
      ans.push_back(a[i]);
      sumL += a[i];
    }
  }

  for (int i = 30; i < n-1; i++) {
    ans.push_back(a[i]);
  }

  int sz = ans.size();
  for (int i = 0; i < sz; i++) {
    cout << ans[i];
    if (i == sz-1) cout << endl;
    else cout << " ";
  }

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  for (int x = 1; x <= t; x++) {
    testcase();
  }
  
  return 0;
}
