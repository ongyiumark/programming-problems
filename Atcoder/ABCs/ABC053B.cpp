#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s; cin >> s;
  int n = s.size();
  int a, z;
  a = z = -1;
  for (int i = 0; i < n; i++){
    if (s[i] == 'A' && a == -1) a = i;
    if (s[i] == 'Z') z = i;
  }

  cout << z-a+1 << endl;
  return 0;
}
