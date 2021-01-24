/*
  Notice that if all the numbers are positive, we can satisfy the constraints by adding a[i] to a[i+1] from 1 to n-1.
  Similarly, if all the numbers are negative, we can satisfy the constraints by adding a[i+1] to a[i] from n-1 to 1.
  These take n-1 operations.

  So, how do we turn everything to the same sign?
  We get the element with the maximum absolute value and add that to everything.
  This will make everything follow its sign.
  This takes another n-1 operations.
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

int a[51];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }

  int pivot = -1;
  int hi = 0;
  for (int i = 1; i <= n; i++){
    if (hi <= abs(a[i])){
      hi = abs(a[i]);
      pivot = i;
    }
  }
  cout << 2*n-2 << endl;
  for (int i = 1; i <= n; i++){
    if (i == pivot) continue;
    cout << pivot << " " << i << endl;
  }
  if (a[pivot] < 0){
    for (int i = n-1; i >= 1; i--){
      cout << i+1 << " " << i << endl;
    }
  }
  else {
    for (int i = 2; i <= n; i++){
      cout << i-1 << " " << i << endl;
    }
  }
  return 0;
}
