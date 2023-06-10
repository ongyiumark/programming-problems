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

  int k, n; cin >> k >> n;
  vector<int> A(2*n);
  for (int i = 0; i < n; i++) cin >> A[i];
  for (int i = n; i < 2*n; i++) A[i] = A[i-n]+k;

  int ans = 1e9;
  for (int i = n-1; i < 2*n; i++) {
    ans = min(ans, A[i]-A[i-n+1]);
  }
  
  cout << ans << "\n";
  return 0;
}
