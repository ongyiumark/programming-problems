#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n; cin >> n;

  vector<int> village_coords(n);
  for (int &x : village_coords) cin >> x;

  vector<ll> village_pop(n);
  for (ll &x : village_pop) cin >> x;

  int q; cin >> q;
  vector<pair<int,int>> queries(q);
  for (int i = 0; i < q; i++) {
    int l, r; cin >> l >> r;
    queries[i] = make_pair(l, r);
  } 

  // coordinate compress
  vector<int> coords;
  for (int &x : village_coords) coords.emplace_back(x);
  for (auto &[l,r] : queries) {
    coords.emplace_back(l);
    coords.emplace_back(r);
  }
  sort(coords.begin(), coords.end());
  coords.erase(unique(coords.begin(), coords.end()), coords.end());

  unordered_map<int,int> compress;
  int sz = coords.size();
  for (int i = 0; i < sz; i++) {
    compress[coords[i]] = i;
  }

  // prefix sums
  vector<ll> pref(sz);
  for (int i = 0; i < n; i++) 
    pref[compress[village_coords[i]]] = village_pop[i];

  for (int i = 1; i < sz; i++) pref[i] += pref[i-1];

  // answer query
  for (auto &[l, r] : queries) {
    int cl = compress[l];
    int cr = compress[r];

    ll res = pref[cr];
    if (cl > 0) res -= pref[cl-1];
    cout << res << "\n";
  }

  return 0;
}