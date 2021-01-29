/*
  Create a boolean array of perfect powers.
  Do all perfect powers of 2, 3, 4, ... x-1.
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
  
  int x; cin >> x;
  bool perfect[x+1];
  memset(perfect, 0, sizeof perfect);
  perfect[1] = 1;

  for (int b = 2; b < x; b++){
    int e = b*b;
    while(e <= x){
      perfect[e] = 1;
      e *= b;
    }
  }

  for (int i = x; i >= 1; i--){
    if (perfect[i]){
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
