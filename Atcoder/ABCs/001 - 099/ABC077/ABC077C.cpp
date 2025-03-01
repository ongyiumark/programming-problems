/*
  For each part in the middle, count how many parts in the upper are less that 
  and how many parts in the lower are greater than that.

  This can be done with Binary Search.
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

const int N = 1e5;
int a[N], b[N], c[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) cin >> c[i];
  sort(a, a+n);
  sort(b, b+n);
  sort(c, c+n);

  ll ans = 0;
  for (int i = 0; i < n; i++){
    int lo = 0;
    int hi = n-1;
    int A = 0;
    while(lo <= hi) {
      int mid = hi-(hi-lo)/2;
      if (a[mid] < b[i]){
        A = mid+1;
        lo = mid + 1;
      }
      else hi = mid-1;
    }

    lo = 0;
    hi = n-1;
    int B = n;
    while(lo <= hi){
      int mid = hi-(hi-lo)/2;
      if (c[mid] > b[i]){
        B = mid;
        hi = mid-1;
      }
      else lo = mid+1;
    }
    B = n-B;
    ans += (ll)A*B;
  }
  cout << ans << endl;
  return 0;
}
