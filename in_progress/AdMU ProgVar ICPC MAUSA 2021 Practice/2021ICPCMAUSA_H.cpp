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

const int M = 2e6;
vector<int> p;
vector<bool> is_composite(M);

bool check(string a, string b) {
  int n = a.size(), m = b.size();
  if (n > m) return false;
  for (int i = 0; i+n-1 < m; i++) {
    bool found = 1;
    for (int j = 0; j < n; j++) {
      found &= (a[j] == b[i+j]);
    }
    if (found) return true;
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 2; i < M; i++) {
    if (!is_composite[i]) p.push_back(i);
    for (int j = 0; j < (int)p.size() && i*p[j] < M; j++) {
      is_composite[i*p[j]] = 1;
      if (i%p[j]==0) break;
    }
  }

  int l, h; cin >> l >> h;
  string t; cin >> t;
  int ans = 0;
  for (int i = l-1; i <= h-1; i++) {
    ans += check(t, to_string(p[i]));
  }
  cout << ans << endl;
  
  return 0;
}
