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
  
  ll x, y; cin >> x >> y;
  ll r; cin >> r;

  ll left = x-r, right = x+r, up = y-r, down = y+r;
  cout << left << " " << up << endl;
  cout << right << " " << up << endl;
  cout << right << " " << down << endl;
  cout << left << " " << down << endl;
  return 0;
}
