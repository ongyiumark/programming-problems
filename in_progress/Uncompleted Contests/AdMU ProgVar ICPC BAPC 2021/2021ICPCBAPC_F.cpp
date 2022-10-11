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
pii bp[N], pb[N];

pii operator+(const pii &left, const pii &right) {
  return {left.first + right.first, left.second + right.second};
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int b, p; cin >> b >> p;
    bp[i] = {b,p};
    pb[i] = {p,b};
  }

  if (n&1) {
    cout << "impossible" << endl;
    return 0;
  }

  sort(bp, bp+n);
  sort(pb, pb+n);

  bool val1 = 1;
  pii tmp1 = bp[0]+bp[n-1];
  for (int i = 1; i < n/2; i++) {
    if (tmp1 != bp[i]+bp[n-1-i]) val1 = 0;
  }

  bool val2 = 1;
  pii tmp2 = pb[0]+pb[n-1];
  for (int i = 1; i < n/2; i++) {
    if (tmp2 != pb[i]+pb[n-1-i]) val2 = 0;
  }

  cout << ((val1 || val2) ? "possible" : "impossible") << "\n";

  return 0;
}
