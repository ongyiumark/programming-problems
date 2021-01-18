/*
  Start from the end going back by 2. Then, start from the beginning going forward by 2.
  You can also just brute force this with a deque (my first solution).
*/
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
  int n; cin >> n; 
  vector<int> ans;
  int a[n];
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  for (int i = n-1; i >= 0; i-=2){
    ans.push_back(a[i]);
  }
  for (int i = (n&1); i < n; i+=2){
    ans.push_back(a[i]);
  }

  for (int i = 0; i < ans.size(); i++){
    cout << ans[i];
    cout << (i == n-1 ? "\n" : " ");
  }
  return 0;
}
