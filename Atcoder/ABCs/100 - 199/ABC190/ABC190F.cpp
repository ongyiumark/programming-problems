/*
  Suppose we have know the number of inversions for k = x, say I.
  We want to know the number of inversions for k = x+1.

  Suppose our b[n-1] = y for k = x+1.
  First, we remove how much y contributed to I.
  Second, we add the new contribution of y to make our new inversion number.

  The second step is easy since we simply need to count how many elements before y are greater than y.
  Since y is our last element, the answer is n-1-y.

  For the first step, recall that y is the first element for k = x.
  Thus, we need to count how many elements after y are less than y.
  Since y is our first element, the answer is y.

  So, I' = I+n-1-2*y.
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
using ordered_set_greater = __gnu_pbds::tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_set_less = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 3e5;
ll a[N];
ordered_set_greater<int> os;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  ll curr_inv = 0;
  for (int i = 0; i < n; i++){
    curr_inv += os.order_of_key(a[i]);
    os.insert(a[i]);
  }

  cout << curr_inv << endl;
  for (int i = 0; i < n-1; i++){
    curr_inv += n-1-2*a[i];
    cout << curr_inv << endl;
  }
  return 0;
}
