/*
  Check every center. Choose one valid height and check if everything is consistent with that height.
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

const int N = 105;
int x[N], y[N], h[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> h[i];

  for (int cx = 0; cx <= 100; cx++){
    for (int cy = 0; cy <= 100; cy++){
      int tmp = 0;
      for (int i = 0; i < n; i++){
        if (h[i]) tmp = h[i]+abs(cx-x[i])+abs(cy-y[i]); 
      }

      bool valid = 1;
      for (int i = 0; i < n && valid; i++){
        if (h[i] != max(tmp-abs(cx-x[i])-abs(cy-y[i]),0))
          valid = 0;
      }
      if (valid) {
        cout << cx << " " << cy << " " << tmp << endl;
        return 0;
      }
    }
  }
  return 0;
}
