/* 
  Brute force each number from 1 to n.
  You don't even need to be efficient with the divisor counting.
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

int div_count(int x){
  int cnt = 0;
  for (int i = 1; i <= x; i++){
    cnt += x%i == 0;
  }
  return cnt;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int ans = 0;
  int n; cin >> n;
  for (int i = 1; i <= n; i+=2){
    ans += div_count(i) == 8;
  }
  cout << ans << endl;
  return 0;
}
