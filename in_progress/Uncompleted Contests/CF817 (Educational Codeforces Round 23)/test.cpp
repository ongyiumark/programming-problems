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

int f(int n) {
  ll ans = 0;
  while (n > 0) {
    ans += n%10;
    n /= 10;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N = 3000;
  for (int i = 1; i < N; i++) {
    cout << i << " " << f(i) << " " << i-f(i) << endl;
  }
  return 0;
}
