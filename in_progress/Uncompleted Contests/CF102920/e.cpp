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
  int n; cin >> n;
  int d[n];
  bool valid = 1;
  for (int i = 0; i < n; i++){
    cin >> d[i];
    if (i == 0 || i == n-1){
      if (d[i] > 1) valid = 0;
    }
    else {
      if (d[i] > 2) valid = 0;
    }
  }
  int curr = 0;
  for (int i = 0; i < n; i++){
    curr = abs(d[i]-curr);
  }
  if (d[0] == 0 && d[1] == 2) valid = 0;
  if (d[n-2] == 2 && d[n-1] == 0) valid = 0;
  cout << ((curr == 0 && valid)? "YES" : "NO") << endl;
  return 0;
}
