/*
  Count the number of elements that are divisible by 4.
  To satify the condition, you need floor(n/2) of such elements.
  
  You also need to count the number of elements that are congruent to 2 (mod 4).
  Every pair of these can be 'removed' from the sequence.
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int cnt = 0;
  int cnt2 = 0;
  int n; cin >> n;
  for (int i = 0; i < n; i++){
    int a; cin >> a;
    cnt += a%4 == 0;
    cnt2 += a%4 == 2;
  }
  cout << (cnt >= (n-cnt2/2*2)/2 ? "Yes" : "No") << endl;
  return 0;
}
