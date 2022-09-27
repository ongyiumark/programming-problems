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
ll a[N];
ll pref[N];
int n, k;

ll range(int l, int r) {
  return pref[r]-pref[l-1];
}

void testcase() {
  cin >> n >> k;
  a[0] = 0; a[n+1] = 0;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i <= n+1; i++) {
    pref[i] = a[i];
    if (i > 0) pref[i] += pref[i-1];
  }
  bool valid = 0;

  int l = k;
  int r = k;
  while(r < n && range(1,r) < 0 && range(k,r+1) >= 0) r++;
  while (l > 1 && r < n) {
    if (range(l-1,r) >= 0) l--;
    else if (range(l, r+1) >= 0) r++;
    else break;
    //cout << l << " " << r << endl;
  }
  valid |= ((l == 1 || r == n)&&(range(l,r) >= 0));

  //cout << valid << endl;

  l = k;
  r = k;
  while(l > 1 && range(l,n) < 0 && range(l-1,k) >= 0) l--;
  while (l > 1 && r < n) {
    if (range(l,r+1) >= 0) r++;
    else if (range(l-1, r) >= 0) l--;
    else break;
    //cout << l << " " << r << endl;
  }
  valid |= ((l == 1 || r == n)&&(range(l,r) >= 0));

  l = k;
  r = k;
  while (l > 1 && r < n) {
    if (range(l-1,r) >= 0) l--;
    else if (range(l, r+1) >= 0) r++;
    else break;
    //cout << l << " " << r << endl;
  }
  valid |= ((l == 1 || r == n)&&(range(l,r) >= 0));

  //cout << valid << endl;

  l = k;
  r = k;
  while (l > 1 && r < n) {
    if (range(l,r+1) >= 0) r++;
    else if (range(l-1, r) >= 0) l--;
    else break;
    //cout << l << " " << r << endl;
  }
  valid |= ((l == 1 || r == n)&&(range(l,r) >= 0));

  cout << (valid ? "YES" : "NO") << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--) testcase();

  return 0;
}