/* 
  Make n sets and check for the presence of each food in all sets.
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
  
  int n, m; cin >> n >> m;
  unordered_set<int> A[n];
  for (int i = 0; i < n; i++){
    int k; cin >> k;
    for (int j = 0; j < k; j++){
      int x; cin >> x;
      A[i].insert(x);
    }
  }

  int cnt = 0;
  for (int x = 1; x <= m; x++){
    bool likes = true;
    for (int i = 0; i < n; i++){
      if (A[i].find(x) == A[i].end()){
        likes = false;
        break;
      }
    }
    cnt += likes;
  }
  cout << cnt << endl;
  return 0;
}
