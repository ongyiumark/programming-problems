/*
  The optimal way is to divide only one element by 2 at a time.
  So we simply count how many times we can divide by 2.
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
  
  int n; cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++){
    int a; cin >> a;
    while(a % 2 == 0){
      a /= 2;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
