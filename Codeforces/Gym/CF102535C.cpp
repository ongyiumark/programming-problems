/*
  We can't keep a boolean array anymore, so let's use a hashmap.
  We can also use sort our keys and use binary search. 
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

unordered_map<int,bool> door;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k; cin >> k;
  for (int i = 0; i < k; i++){
    int x; cin >> x;
    if (x > 0) door[x-1] = 1;
    door[x+1] = 1;
  }
  int l; cin >> l;
  int cnt = 0;
  for (int i = 0; i < l; i++){
    int x; cin >> x;
    cnt += door[x];
  } 
  cout << cnt << endl;
  return 0;
}
