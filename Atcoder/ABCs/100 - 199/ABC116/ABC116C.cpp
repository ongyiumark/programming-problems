/*
  For each flower, we try to grow it to the desired height will maximizing the number of flowers we grow.
  So, fix L and find the farthest R. Repeat until flower L is at the desired height.  
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
int h[N];
int n;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> h[i];

  int ans = 0;
  for (int i = 0; i < n; i++) {

    while(h[i] > 0){
      int j = i;
      int lo = 100;
      while(j < n && h[j] > 0) {
        lo = min(lo, h[j]);
        j++;
      }
      for (int k = i; k < j; k++) h[k] -= lo;
      ans += lo;
    }
  }

  cout << ans << endl;
  return 0;
}
