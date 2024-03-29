/*
  Try making each digit the tens digit by multiplying it by 10. 
  Get the maximum of those three.
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
  int a, b, c; cin >> a >> b >> c;
  cout << max({a + 10*b + c, 10*a + b + c, 10*c + a + b}) << endl;
  return 0;
}
