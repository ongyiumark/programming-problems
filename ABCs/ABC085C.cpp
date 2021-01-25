/*
  Try all combinations of a,b,c such that a+b+c=2000.
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
  
  int n, y; cin >> n >> y;
  y /= 1000;

  for (int a = 0; a <= n; a++){
    for (int b = 0; b <= n; b++){
      int c = (n-a-b);
      if (c > 2000 || c < 0) continue;
      if (10*a+5*b+c == y){
        cout << a << " " << b << " " << c << endl;
        return 0;
      }
    }
  }
  cout << -1 << " " << -1 << " " << -1 << endl;
  return 0;
}
