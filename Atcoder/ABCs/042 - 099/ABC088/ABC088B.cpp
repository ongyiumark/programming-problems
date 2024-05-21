/*
  Sort in descending order.
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
  int a[n];
  int total = 0;
  for (int i = 0; i < n; i++){
    cin >> a[i];
    total += a[i];
  }

  sort(a, a+n, greater<int>());
  int alice = 0;
  for (int i = 0; i < n; i+=2){
    alice += a[i];
  }

  cout << 2*alice - total << endl;
  return 0;
}
