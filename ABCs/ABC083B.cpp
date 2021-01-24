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

int digit_sum(int x){
  int ans = 0;
  while(x > 0){
    ans += x%10;
    x /= 10;
  }
  return ans;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, a, b;
  cin >> n >> a >> b;
  int ans = 0;
  for (int i = 1; i <= n; i++){
    int dsum = digit_sum(i);
    if (a <= dsum && dsum <= b) ans += i;
  }  
  cout << ans << endl;
  return 0;
}
