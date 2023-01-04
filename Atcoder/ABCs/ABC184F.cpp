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

const int N = 45;
ll n, t;
ll A[N];

const int N2 = 20;
ll L[1<<N2], R[1<<N2];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> t;
  for (int i = 0; i < n; i++) cin >> A[i];  
  memset(L, 0, sizeof L);
  memset(R, 0, sizeof R);

  if (n == 1) {
    cout << (A[0] <= t ? A[0] : 0) << "\n";
    return 0;
  }

  int a = 0, b = n/2-1, c = n/2, d = n-1;
  int lsz = b-a+1;
  int rsz = d-c+1;
  
  for (int i = 0; i < (1 << lsz); i++) {
    for (int j = 0; j < lsz; j++) {
      if ((1<<j)&i) L[i] += A[a+j];
    }
  }
  
  for (int i = 0; i < (1 << rsz); i++) {
    for (int j = 0; j < rsz; j++) {
      if ((1<<j)&i) R[i] += A[c+j];
    }
  }

  sort(L, L+(1<<lsz));
  sort(R, R+(1<<rsz));

  ll ans = 0;
  for (int i = 0; i < (1<<lsz); i++) {
    if (L[i] > t) break;
    ans = max(ans, L[i] + *prev(upper_bound(R, R+(1<<rsz), t-L[i])));
  }
  cout << ans << "\n";
  return 0;
}
