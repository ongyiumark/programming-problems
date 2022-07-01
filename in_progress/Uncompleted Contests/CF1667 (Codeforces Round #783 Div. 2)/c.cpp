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

const int N = 5005;
ll a[N], b[N];
int n;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  memset(b, 0, sizeof b);
  for (int i = 0; i < n; i++) cin >> a[i];

  ll best = 1e18;
  // zero at ith index
  for (int i = 0; i < n; i++) {
    ll res = 0;
    // ascending
    ll curr = 1;
    for (int j = i+1; j < n; j++) {
      ll ncurr = (curr+a[j]-1)/a[j] * a[j];
      res += (curr+a[j]-1)/a[j];
      curr = ncurr+1;
    }

    // decending
    curr = 1;
    for (int j = i-1; j >= 0; j--) {
      ll ncurr = (curr+a[j]-1)/a[j] * a[j];
      res += (curr+a[j]-1)/a[j];
      curr = ncurr+1;
    }

    best = min(res, best);
  }
  cout << best << endl;
  
  return 0;
}
