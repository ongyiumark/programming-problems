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
  int l, r; cin >> l >> r;
  string s; cin >> s;
  int n = s.size();
  for (int i = 0; i < l-1; i++){
    cout << s[i];
  }
  for (int i = r-1; i >= l-1; i--){
    cout << s[i];
  }
  for (int i = r; i < n; i++) {
    cout << s[i];
  }
  return 0;
}
