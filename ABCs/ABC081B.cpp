/*
  Try consecutive powers of 2 until it doesn't work.
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

int a[200];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int div = 1;
  int i;
  for (i = 1; i <= 30; i++){
    div *= 2;
    bool valid = 1;
    for (int j = 0; j < n; j++){
      valid &= (a[j]%div == 0);
    }
    if (!valid) break;
  }
  cout << i-1 << endl;
  return 0;
}
