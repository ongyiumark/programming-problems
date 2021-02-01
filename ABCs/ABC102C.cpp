/*
  Subtract i from A[i]. The question becomes find an integer b that minimizes the absolute distance from all elements.
  This is the median.
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

const int N = 2e5;
ll a[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  for (int i = 0; i < n; i++){
    cin >> a[i];
    a[i] -= i+1;
  }
  sort(a, a+n);
  ll b = a[(n-1)/2];
  ll ans = 0;
  for (int i = 0; i < n; i++){
    ans += abs(a[i]-b);
  }
  cout << ans << endl;
  return 0;
}
