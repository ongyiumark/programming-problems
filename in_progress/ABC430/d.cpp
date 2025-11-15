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

struct FenwickTree {
  vector<int> ft;
  FenwickTree(int n) : ft(n+1) {}
  int query(int i) {
    int total = 0;
    for (; i > 0; i -= (i&-i)) total += ft[i];
    return total;
  }
  int query(int l, int r) { return query(r)-query(l-1); }
  void update(int i, int v) {
    for (; i < ft.size(); i += (i&-i)) ft[i] += v;
  }
};

struct IndexedSet {
  FenwickTree f; int n;
  IndexedSet(int max_n) : f(max_n), n(max_n) {}

  int count(int x) { return f.query(x,x); }
  void insert(int x) { f.update(x, 1); }
  void remove(int x) { f.update(x, -1); }
  int size() { return f.query(n); }
  int order_of_key(int x) { return f.query(x)-1; }
  int find_by_order(int k) {
    int i = 1; for (; 2*i <= n; i <<= 1);
    int ret = 0;
    for (; i > 0; i >>= 1) {
      if (i+ret <= n && f.ft[i+ret] <= k) {
        k -= f.ft[i+ret];
        ret += i;
      }
    }
    return ret+1;
  }
};

const int MAXN = 5e5+5;
const ll INF = 1e18;
IndexedSet ind_set(MAXN);

int main(){
  cin.tie(0)->sync_with_stdio(false);


  int n; cin >> n;
  vector<ll> X(n), X_copy(n);
  for (int i = 0; i < n; i++) {
    ll x; cin >> x;
    X_copy[i] = X[i] = x;
  }

  // coordinate compression
  sort(X_copy.begin(), X_copy.end());
  unordered_map<ll,int> compress, decompress;
  compress[0] = 1; decompress[1] = 0;
  for (int i = 0; i < n; i++) {
    compress[X_copy[i]] = i+2;
    decompress[i+2] = X_copy[i];
  }
  vector<int> X_compressed(n);
  for (int i = 0; i < n; i++) {
    X_compressed[i] = compress[X[i]];
  }

  ll total = 0;
  ind_set.insert(compress[0]);

  for (int i = 0; i < n; i++) {
    int left_index = ind_set.order_of_key(X_compressed[i]);
    int right_index = left_index+1;

    int sz = i+1;

    // update left_index
    ll left_of_left = left_index-1 >= 0 ? decompress[ind_set.find_by_order(left_index-1)] : -INF;
    ll right_of_left = left_index+1 < sz ? decompress[ind_set.find_by_order(left_index+1)] : INF;
    ll left = left_index >= 0 ? decompress[ind_set.find_by_order(left_index)] : -INF;
    if (left_index >= 0) {
      if (left_index-1 >= 0 || left_index+1 < sz) total -= min(left-left_of_left, right_of_left-left);
      total += min(left-left_of_left, X[i]-left);
    }

    // update right_index
    ll left_of_right = right_index-1 >= 0 ? decompress[ind_set.find_by_order(right_index-1)] : -INF;
    ll right_of_right = right_index+1 < sz ? decompress[ind_set.find_by_order(right_index+1)] : INF;
    ll right = right_index < sz ? decompress[ind_set.find_by_order(right_index)] : INF;
    if (right_index < sz) {
      if (right_index-1 >= 0 || right_index+1 < sz) total -= min(right_of_right-right, right-left_of_right);
      total += min(right_of_right-right, right-X[i]);
    }

    // update current
    total += min(X[i]-left, right-X[i]);

    // insert current
    ind_set.insert(X_compressed[i]);

    cout << total << "\n";
  }

  
  return 0;
}
