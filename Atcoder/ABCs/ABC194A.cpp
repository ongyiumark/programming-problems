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
  
  int a, b; cin >> a >> b;
  a = a+b;
  if (a >= 15 && b >= 8) cout << 1;
  else if (a >= 10 && b >= 3) cout << 2;
  else if (a >= 3) cout << 3;
  else cout << 4;
  cout << endl;
  return 0;
}
