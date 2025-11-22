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

int main(){
  cin.tie(0)->sync_with_stdio(false);

  string s; cin >> s;
  // for each i: number of same digit to the left and right
  int n = s.size();
  vector<int> count_left(n), count_right(n);
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i-1]) count_left[i] = count_left[i-1]+1;
  }
  for (int i = n-2; i >= 0; i--) {
    if (s[i] == s[i+1]) count_right[i] = count_right[i+1]+1;
  }
  ll total = 0;
  for (int i = 0; i < n; i++) {
    if (s[i]+1 == s[i+1]) {
      total += min(count_left[i]+1, count_right[i+1]+1);
    }
  }
  cout << total << "\n";
  return 0;
}
