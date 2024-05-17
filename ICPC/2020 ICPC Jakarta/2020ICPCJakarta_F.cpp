#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1e18;
struct FenwickTree {
  vector<ll> ft;
  unordered_map<ll,int> compress;

  FenwickTree(vector<ll>& coords) {
    int n = coords.size();
    ft.assign(n+1, 0);

    for (int i = 1; i <= n; i++) {
      compress[coords[i-1]] = i;
    }
  }

  void update(int i, int v) {
    for (; i < ft.size(); i += (i&-i)) ft[i] += v;
  }
  void cupdate(ll x, int v) { update(compress[x], v); }
  
  ll query(int i) {
    ll total = 0;
    for (; i > 0; i -= (i&-i)) total += ft[i];
    return total;
  }
  ll query(int l, int r) { return query(r) - query(l-1); }
  ll cquery(ll l, ll r) { return query(compress[l], compress[r]); }
};

int main() {
  cin.tie(0)->sync_with_stdio(false);
  
  int n, m; cin >> n >> m;
  vector<ll> C(n);
  for (ll &x : C) cin >> x;
  vector<vector<ll>> W(m);
  for (int i = 0; i < m; i++) {
    int sz; cin >> sz;
    W[i].assign(sz, 0);
    for (int j = 0; j < sz; j++) cin >> W[i][j];
  }

  vector<ll> coords_tmp;
  for (int i = 0; i < n; i++) {
    coords_tmp.push_back(C[i]);
    coords_tmp.push_back(C[i]+1);
    coords_tmp.push_back(C[i]-1);
  }
  for (int i = 0; i < m; i++) {
    for (ll &x : W[i]) {
      coords_tmp.push_back(x);
      coords_tmp.push_back(x+1);
      coords_tmp.push_back(x-1);
    }
  } 
  coords_tmp.push_back(-INF);
  coords_tmp.push_back(INF);
  sort(coords_tmp.begin(), coords_tmp.end());

  vector<ll> coords;
  coords.push_back(coords_tmp[0]);
  int sz = coords_tmp.size();
  for (int i = 1; i < sz; i++) {
    if (coords_tmp[i] == coords_tmp[i-1]) continue;
    coords.push_back(coords_tmp[i]);
  }

  FenwickTree ft(coords);

  ll start_inversion = 0;
  for (int i = 0; i < n; i++) {
    start_inversion += ft.cquery(C[i]+1, INF);
    ft.cupdate(C[i], 1);
  }
  for (int i = 0; i < m; i++) {
    ll ans = INF;

    ll inversions = start_inversion;
    int sz = W[i].size();
    for (int j = 0; j < sz; j++) {
      inversions += ft.cquery(W[i][j]+1, INF);
      ft.cupdate(W[i][j], 1);
    }

    ans = min(ans, inversions);
    for (int j = 0; j < sz; j++) ft.cupdate(W[i][j], -1);

    for (int j = 0; j < sz; j++) {
      inversions -= ft.cquery(W[i][j]+1, INF);
      inversions += ft.cquery(-INF, W[i][j]-1);
      ans = min(ans, inversions);
    }
    cout << ans << "\n";
  }

  return 0;
}