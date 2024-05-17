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

  int x[2], y[2];
  for (int i = 0; i < 2; i++) cin >> x[i] >> y[i];
  
  cout << abs(x[0]-x[1])+abs(y[0]-y[1])-min(abs(x[0]-x[1]),abs(y[0]-y[1])) << endl;
  
  return 0;
}
