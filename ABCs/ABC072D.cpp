/*
  Let's denote the elements that don't need swapping as 1 and the elements that need swapping as 0.
  00 can be turned into 11 with a single operation. Prioritize these operations.
  After converting all adjacent pairs of 0's to 1's, Simply count how many 0's are left.
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

const int N = 1e5+5;
int p[N];
bool ok[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for (int i = 1; i <= n; i++){
    cin >> p[i];
    ok[i] = p[i] != i;
  }
  int cnt = 0;
  for (int i = 2; i <= n; i++){
    if (!ok[i-1] && !ok[i]){
      ok[i-1] = ok[i] = 1;
      cnt++;
    } 
  }
  for (int i = 1; i <= n; i++){
    cnt += !ok[i];
  }
  cout << cnt << endl;
  return 0;
}
