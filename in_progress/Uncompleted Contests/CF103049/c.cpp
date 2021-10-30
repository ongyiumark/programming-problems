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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ld n, k, d, s; cin >> n >> k >> d >> s;

  if (d*n - s*k > 100*(n-k) || d*n-s*k < 0) {
    cout << "impossible" << endl;
    return 0;
  }

  cout << fixed << setprecision(10) << (d*n - s*k)/(n-k) << endl;
  return 0;
}
