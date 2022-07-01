/*
  Sort by the following criteria:
    left+right < right+left
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

const int N = 5e4+5;
string a[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n, [](const string &left, const string &right) {
    int lsz = left.size();
    int rsz = right.size();
    for (int i = 0; i < lsz+rsz; i++) {
      char x = (i < lsz ? left[i] : right[i-lsz]);
      char y = (i < rsz ? right[i] : left[i-rsz]);
      if (x == y) continue;
      return x < y;
    }
    return false;
  });

  string ans = "";
  for (int i = 0; i < n; i++) ans += a[i];
  cout << ans << endl;

  return 0;
}
