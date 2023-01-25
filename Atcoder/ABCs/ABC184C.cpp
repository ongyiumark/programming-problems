#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
  ll a = (r1+c1), b = (r1-c1), c = (r2+c2), d = (r2-c2);

  if ((r1 == r2) && (c1 == c2)) {
    cout << 0 << "\n";
  }
  else if ((abs(r1-r2) + abs(c1-c2) <= 3) || (a == c) || (b == d)) {
    cout << 1 << "\n";
  }
  else if (((a+c)%2 == 0) || ((b+d)%2 == 0) || (min(abs(a-c), abs(b-d)) <= 3) || (abs(r1-r2) + abs(c1-c2) <= 6))  {
    cout << 2 << "\n";
  }
  else {
    cout << 3 << "\n";
  }
  
  return 0;
}
