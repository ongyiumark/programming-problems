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
using ordered_set = __gnu_pbds::tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5;
ll a[N];
ordered_set<ll> os;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  ll lo = 1e18;
  int loidx = n;
  for (int i = n-1; i >= 0; i--){
    if (loidx < n) {

    }
    if (lo > a[i]){
      lo = a[i];
      loidx = i;
    }
  }
  ll cnt = 0;
  ll hi = 0;
  for (int i = 0; i < n; i++) {
    cnt += os.order_of_key(a[i]);
    //hi = max(hi, (ll)os.order_of_key(a[i]));
    os.insert(a[i]);
  }
  if (cnt == 0) cout << 1 << endl;
  else cout << cnt-hi << endl;
  return 0;
}
