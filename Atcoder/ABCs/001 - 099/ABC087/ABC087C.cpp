/*
  You can only go down once. So, once you go down, you're forced to always go right.
  The path you travel will always be some number of squares at the top followed by some number of squares at the bottom.

  You can count the candies with prefix sums.
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

const int N = 100;
int a[N], b[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }

  for (int i = 1; i < n; i++){
    a[i] += a[i-1];
    b[i] += b[i-1];
  }

  int ans = 0;
  for (int i = 0; i < n; i++){
    int cans = a[i] + b[n-1];
    if (i > 0) cans -= b[i-1];
    ans = max(ans, cans);
  }
  cout << ans << endl;
  return 0;
}
