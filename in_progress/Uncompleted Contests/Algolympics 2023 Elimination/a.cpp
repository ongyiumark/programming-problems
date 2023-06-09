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

const int D = 1e4+5;
int A[D], B[D];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int d, n; cin >> d >> n;  
  for (int i = 0; i < d; i++) cin >> A[i];
  for (int i = 0; i < d; i++) cin >> B[i];

  for (int i = 0; i < n; i++) {
    bool val = 1;
    for (int j = 0; j < d; j++) {
      int x; cin >> x;
      val &= (A[j]-B[j] <= x && x <= A[j]);
    }
    if (val) cout << "SUS\n";
    else cout << "INNOCENT\n";
  }

  return 0;
}
