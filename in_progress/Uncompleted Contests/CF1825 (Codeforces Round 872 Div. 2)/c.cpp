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
  ll n, m; cin >> n >> m;
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];

  int left = 0;
  int right = 0;
  set<int> s;
  for (int i = 0; i < n; i++) {
    if (x[i] == -1) left++;
    else if (x[i] == -2) right++;
    else s.insert(x[i]); 
  }

  vector<int> idx;
  for (int id : s) idx.push_back(id);
  int sz = idx.size();

  // all left
  int r = sz-1;
  int curr = m;
  int cnt1 = 0;
  int cleft = left;
  while (curr > 0) {
    if (r >= 0 && curr == idx[r]) {
      r--;
      curr--;
      cnt1++;
    }
    else if (cleft > 0) {
      cleft--;
      curr--;
      cnt1++;
    }
    else {
      curr--;
    }
  }

  // all right  
  int l = 0;
  curr = 1;
  int cnt2 = 0;
  int cright = right;
  while (curr <= m) {
    if (l < sz && curr == idx[l]) {
      l++;
      curr++;
      cnt2++;
    }
    else if (cright > 0) {
      cright--;
      curr++;
      cnt2++;
    }
    else {
      curr++;
    }
  }

  // weird mix
  vector<int> diff(m+1), pref(m+1);
  for (int i; i < sz; i++) diff[idx[i]] = 1;
  for (int i = 1; i <= m; i++) pref[i] = pref[i-1]+diff[i];

  int ans = max(cnt1, cnt2);
  for (int i = 1; i <= m; i++) {
    if (s.find(i) == s.end()) continue;
    int lcnt = i-pref[i];
    int rcnt = (m-i)-(pref[m]-pref[i]);

    ans = max(ans, sz+min(lcnt,left)+min(rcnt,right));
  }

  cout << ans << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--) testcase();
  return 0;
}
