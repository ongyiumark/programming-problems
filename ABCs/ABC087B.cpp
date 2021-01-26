/*
  Try all combinations of coins. Any combination of 2 coins will fix the third.
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
  
  int a, b, c, x;
  cin >> a >> b >> c >> x;
  x /= 50;
  int cnt = 0;
  for (int i = 0; i <= a; i++){
    for (int j = 0; j <= b; j++){
      int need = x-10*i-2*j;
      if (need >= 0 && need <= c){
        cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
