/*
  First, we can simplify senpai's score by adding all the linear functions.
  We can think if the quality score as the dot product of the P and W vectors.
  The dot product is maximixed when P and W parallel.

  Moreover, notice that g is actually the magnitide of P.
  So, the answer is |W|g t >= Ft + C
  Edge case when C <= 0: the answer is t = 0.

  This will have precision errors in C++.
  To handle this, we multiply be the conjugate to get rid of any x-y when x and y are close to each other.
  If F < 0, then the original equation is stable.
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int c; cin >> c;
  while(c--){
    ll q, g; cin >> q >> g;
    ll W = 0;
    for (int i = 0; i < q; i++){
      ll w; cin >> w;
      W += w*w;
    }
    ll F, C;
    F = C = 0;
    for (int i = 0; i < q; i++){
      ll a, b; cin >> a >> b;
      F += a;
      C += b;
    }
    cout << setprecision(15) << fixed; 
    if (C <= 0) cout << 0 << endl;
    else cout << (F > 0 ? (ld)C*(sqrtl(W)*g+F)/(W*g*g-F*F) : (ld)C/(sqrtl(W)*g-F)) << endl;
  }
  return 0;
}
