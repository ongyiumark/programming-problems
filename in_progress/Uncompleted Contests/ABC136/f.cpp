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

struct segtree {
  vector<ll> vals, deltas;
  int n;

  segtree(vector<ll> &arr) : n(arr.size()) {
    vector<ll>(4*n).swap(vals);
    vector<ll>(4*n).swap(deltas);

    build(arr, 1, 0, n-1);
  }

  void build(vector<ll> &arr, int p, int i, int j) {
    if (i == j) { vals[p] = arr[i]; return; }

    int k = (i+j)>>1;
    build(arr, p<<1, i, k);
    build(arr, p<<1|1, k+1, j);
    pull(p);
  }

  void pull(int p) { vals[p] = vals[p<<1] + vals[p<<1|1]; }
  void push(int p, int i, int j) {
    if (deltas[p]) {
      vals[p] += (j-i+1)*deltas[p];
      if (i != j) {
        deltas[p<<1] += deltas[p];
        deltas[p<<1|1] += deltas[p];
      }
      deltas[p] = 0;
    }
  }

  void update(int l, int r, ll v, int p, int i, int j) {
    push(p, i, j);
    if (l <= i and j <= r) {
      deltas[p] += v;
      push(p, i, j);
    }
    else if (j < l or r < i) {}
    else {
      int k = (i+j)>>1;
      update(l, r, v, p<<1, i, k);
      update(l, r, v, p<<1|1, k+1, j);
      pull(p);
    }
  }

  ll query(int l, int r, int p, int i, int j) {
    push(p, i, j);
    if (l <= i and j <= r) return vals[p];
    else if (j < l or r < i) return 0;
    else {
      int k = (i+j)>>1;
      return query(l, r, p<<1, i, k) + query(l, r, p<<1|1, k+1, j);
    }
  }
};

const int N = 2e5+5;
const ll MOD = 998244353;

ll modpow(ll b, ll e) {
  ll ans = 1;
  while(e > 0) {
    if (e&1) ans = ans*b%MOD;
    b = b*b%MOD;
    e>>= 1;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  vector<pair<ll, ll>> p(n);
  for (auto &[x, y] : p) cin >> x >> y;

  // coordinate compression
  sort(p.begin(), p.end());
  for (int i = 0; i < n; i++) p[i].first = i;
  sort(p.begin(), p.end(), [](const pair<ll,ll> &left, const pair<ll,ll> &right) {
    return left.second < right.second;
  });
  for (int i = 0; i < n; i++) p[i].second = i;

  sort(p.begin(), p.end());
  vector<ll> left_arr(N), right_arr(N);
  for (int i = 0; i < n; i++) right_arr[p[i].second] = 1;

  segtree left(left_arr), right(right_arr);
  // cout << "initial segtrees: \n";
  // for (int i = 0; i < 3; i++) cout << left.query(i, i, 1, 0, N-1) << " ";
  // cout << endl;
  // for (int i = 0; i < 3; i++) cout << right.query(i, i, 1, 0, N-1) << " ";
  // cout << endl; 


  ll ans = 0;
  for (int i = 0; i < n; i++) {
    auto [cx, cy] = p[i];

    right.update(cy, cy, -1, 1, 0, N-1);

    vector<ll> quads(4);
    quads[0] = right.query(cy+1, N-1, 1, 0, N-1);
    quads[1] = left.query(cy+1, N-1, 1, 0, N-1);
    quads[2] = left.query(0, cy-1, 1, 0, N-1);
    quads[3] = right.query(0, cy-1, 1, 0, N-1);

    // cout << "current: " << cx << " " << cy << endl;
    // for (int i = 0; i < 4; i++) cout << quads[i] << " ";
    // cout << endl;
    // for (int i = 0; i < 3; i++) cout << left.query(i, i, 1, 0, N-1) << " ";
    // cout << endl;
    // for (int i = 0; i < 3; i++) cout << right.query(i, i, 1, 0, N-1) << " ";
    // cout << endl;

    for (int mask = 0; mask < (1<<4); mask++) {
      //if ((((mask>>1)&1)^((mask>>3)&1)) and ((mask>>0)&1)^((mask>>2)&1)) continue;
      ll tmp = 1;
      for (int i = 0; i < 4; i++) {
        if (((mask>>i)&1) == 0) continue;
        tmp *= modpow(2, quads[i])-1;

        // cout << i << endl;
        tmp %= MOD;
      }
      // cout << "contrib: "  << mask << " " << tmp << endl;
      ans += tmp;
      ans %= MOD;
    }
    

    ll tmp1 = (quads[0] > 0 and quads[2] > 0 ? (modpow(2, quads[0])-1)*(modpow(2, quads[2])-1)%MOD : 0);
    ll tmp2 = (quads[1] > 0 and quads[3] > 0 ? (modpow(2, quads[1])-1)*(modpow(2, quads[3])-1)%MOD : 0);
    ans += tmp1 + tmp2;
    ans %= MOD;


    // cout << ans << endl;
    left.update(cy, cy, 1, 1, 0, N-1);
  } 
  cout << ans << "\n";

  return 0;
}
