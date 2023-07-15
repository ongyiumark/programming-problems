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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  string s; cin >> s;
  bool valid = true;

  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0 and s[i] == 'L') valid = false;
    if (i % 2 == 1 and s[i] == 'R') valid = false;
  }
  cout << (valid ? "Yes" : "No") << "\n";
  return 0;
}
