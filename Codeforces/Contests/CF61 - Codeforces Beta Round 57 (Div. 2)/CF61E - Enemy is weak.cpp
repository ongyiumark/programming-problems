#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct MergeTree {
  int n; vector<vector<ll>> st;
  MergeTree(vector<ll> &ar) {
    n = ar.size();
    st.assign(2*n, vector<ll>());
    for (int i = 0; i < n; i++) st[i+n].push_back(ar[i]);
    for (int i = n-1; i > 0; i--) {
      st[i].resize(st[i<<1].size() + st[i<<1|1].size());
      merge(st[i<<1].begin(), st[i<<1].end(), st[i<<1|1].begin(), st[i<<1|1].end(), st[i].begin());
    }
  }
  ll count_less(int l, int r, ll x) {
    ll res = 0;
    for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
      if (l&1) {
        auto &v = st[l++];
        auto it = lower_bound(v.begin(), v.end(), x);
        res += (it-v.begin());
      }
      if (r&1) {
        auto &v = st[--r];
        auto it = lower_bound(v.begin(), v.end(), x);
        res += (it-v.begin());
      }
    }
    return res;
  }

  ll count_greater(int l, int r, ll x) {
    ll res = 0;
    for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
      if (l&1) {
        auto &v = st[l++];
        auto it = upper_bound(v.begin(), v.end(), x);
        res += v.size()-(it-v.begin()); 
      }
      if (r&1) {
        auto &v = st[--r];
        auto it = upper_bound(v.begin(), v.end(), x);
        res += v.size()-(it-v.begin());
      }
    }
    return res;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n; cin >> n;
  vector<ll> ar(n);
  for (ll &x : ar) cin >> x;
  MergeTree st(ar);

  ll ans = 0;
  for (int i = 1; i < n-1; i++) {
    ans += st.count_greater(0, i-1, ar[i])*st.count_less(i+1, n-1, ar[i]);
  }
  cout << ans << "\n";

  return 0;
}