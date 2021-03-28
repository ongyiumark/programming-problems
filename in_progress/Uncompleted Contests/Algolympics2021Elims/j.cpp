/*
  Since all the values are distinct, we can simply keep track of how far the last element moved.
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

const int N = 1e5;
int stars[N], nstars[N];

void solve(){
  int k; cin >> k;
  for (int i = 0; i < k; i++) cin >> stars[i];
  for (int i = 0; i < k; i++) cin >> nstars[i];

  int idx = k;
  for (int i = 0; i < k; i++){
    if (stars[k-1] == nstars[i]){
      idx = i;
      break;
    }
  }

  cout << k-1-idx << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
