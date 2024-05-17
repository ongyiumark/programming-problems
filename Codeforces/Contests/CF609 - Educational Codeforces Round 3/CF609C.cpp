/*
  Compute the optimal distribution by totalling everything and dividing by n.
  Then, you just need to count how much is overloaded.
    You can move all overload to underloads, which balances everything.
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

const int N = 1e5+5;
int m[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  int total = 0;
  for (int i = 0; i < n; i++) {
    cin >> m[i];
    total += m[i];
  }
  sort(m, m+n);
  
  int best = total/n;
  int extra = total%n;

  int ans = 0;
  for (int i = n-1; i >= 0; i--){
    int need = best + (n-extra <= i ? 1 : 0);
    if (m[i] > need) ans += m[i]-need;
  }
  cout << ans << endl;

  return 0;
}
