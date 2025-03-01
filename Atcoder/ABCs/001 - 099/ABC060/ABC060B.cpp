/*
  ax = by + c
  ax - by = c
  This is a linear diophantine equation. Simply check if c is a multiple of gcd(a,b).
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int gcd(int a, int b){
  if (b == 0) return a;
  return gcd(b,a%b);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, c;
  cin >> a >> b >> c;
  cout << (c%gcd(a,b) == 0 ? "YES" : "NO") << endl;
  return 0;
}
