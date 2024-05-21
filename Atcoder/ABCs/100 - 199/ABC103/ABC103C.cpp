/*
  You can obtain x%a = 0 for all a by getting the LCM.
  Thus x%a-1 = -1 = a-1 for all a.
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

const int N = 3000;
int a[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n; 
  ll total = 0;
  for (int i = 0; i < n; i++){
    cin >> a[i];
    total += a[i]-1;
  }
  cout << total << endl;
  return 0;
}
