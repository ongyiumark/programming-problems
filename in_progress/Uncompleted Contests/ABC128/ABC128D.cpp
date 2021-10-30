/* 
  Notice that it's always optimal to return jewels at the very end so we can return the largest negatives first.
  So, we fix how may we get from the right. Then, fix how many from the left.
    Then subtract the largest negatives with remaining moves (may not use all of them).
  
  This run in O(N^2) to try all combinations of right an left jewels. 
    Then, another O(N lgN) to sort to find the smallest negatives.
  
  Total time complexity is O(N^3 lgN). N is 50 so this is doable. 
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


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k; cin >> n >> k;
  int v[n];
  for (int i = 0; i < n; i++) cin >> v[i];

  int best = 0;
  for (int l = 0; l <= n; l++){
    for (int r = 0; r <= n; r++){
      if (l+r > min(k,n)) continue;
      int rem = k-l-r;
      vector<int> tmp;
      for (int i = 0; i < l; i++) tmp.push_back(v[i]);
      for (int i = 0; i < r; i++) tmp.push_back(v[n-1-i]);
      sort(tmp.begin(), tmp.end());

      int total = 0;
      int j = 0;
      while(j < l+r && tmp[j] < 0) j++;
      for (int i = min(rem,j); i < l+r; i++) total += tmp[i];
      best = max(best,total);
    }
  }
  cout << best << endl;
  return 0;
}
