#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp> // for rope ds:
#include <ext/pb_ds/tree_policy.hpp>     // <ext/rope>
using namespace __gnu_pbds;              // __gnu_cxx;
template <typename T>
using indexed_multiset = tree<T, null_type, less_equal<T>,
  rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  
  int n, q; cin >> n >> q;
  indexed_multiset<ll> ms;

  vector<ll> p(n);
  for (ll &x : p) {
    cin >> x;
    ms.insert(x);
  }
  vector<tuple<char,ll,ll>> qs(q);
  for (auto &[op, a, b] : qs) {
    cin >> op >> a >> b;
    if (op == '!') {
      a--;
      ms.erase(ms.find_by_order(ms.order_of_key(p[a])));
      p[a] = b;
      ms.insert(b);
    }
    else {
      auto right = ms.lower_bound(b);
      auto left = ms.upper_bound(a);

      int r = (right == ms.end() ? ms.size() : ms.order_of_key(*right));
      int l = (left == ms.end() ? ms.size() : ms.order_of_key(*left));
      cout << r-l << "\n";
    }
  }



  return 0;
}