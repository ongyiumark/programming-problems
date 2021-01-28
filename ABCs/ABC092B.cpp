/*
  Solve for largest k such that kA+1 <= D. The number of chocolates eaten is k+1. 
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
  int d, x; cin >> d >> x;
  for (int i = 0; i < n; i++){
    int a; cin >> a;
    x += (d-1)/a+1;
  }
  cout << x << endl;
  return 0;
}
