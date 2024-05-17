#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct SegmentTree {
  vector<ll> st, lazy;
  int n;

  SegmentTree(int n) : n(n) {
    st.assign(4*n, 0);
    lazy.assign(4*n, 0);
  }

  void pull(int p) {
    st[p] = st[p<<1] + st[p<<1|1];
  }

  void push(int p, int i, int j) {
    if (lazy[p]) {
      st[p] += (j-i+1)*lazy[p];
      if (i != j) {
        lazy[p<<1] += lazy[p];
        lazy[p<<1|1] += lazy[p];
      }
      lazy[p] = 0;
    }
  }

  ll query(int l, int r) { return query(l, r, 1, 0, n-1); }
  ll query(int l, int r, int p, int i, int j) {
    push(p, i, j);
    if (l <= i && j <= r) return st[p];
    else if (j < l || r < i) return 0;
    else {
      int k = (i+j)/2;
      return query(l, r, p<<1, i, k) + query(l, r, p<<1|1, k+1, j);
    }
  }

  void update(int l, int r, ll v) { return update(l, r, v, 1, 0, n-1); }
  void update(int l, int r, ll v, int p, int i, int j) {
    push(p, i, j);
    if (l <= i && j <= r) {
      lazy[p] += v;
      push(p, i, j);
    }
    else if (j < l || r < i);
    else {
      int k = (i+j)/2;
      update(l, r, v, p<<1, i, k);
      update(l, r, v, p<<1|1, k+1, j);
      pull(p);
    }
  }
};

const int LG = 20;

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n, q; cin >> n >> q;
  vector<vector<int>> child(n);
  vector<int> parent(n, -1);

  for (int i = 1; i < n; i++) {
    cin >> parent[i];
    parent[i]--;
    child[parent[i]].push_back(i);
  }

  vector<int> depth(n);
  vector<int> L(n), R(n);
  vector<vector<int>> decendant_count(n, vector<int>(LG, 0));
  int counter = 0;
  function<void(int)> dfs = [&](int u) {
    L[u] = counter;

    counter++;
    decendant_count[u][0] = 1;
    for (int &v : child[u]) {
      depth[v] = depth[u]+1;
      dfs(v);

      auto &tmp = decendant_count[v];
      for (int i = 1; i < LG; i++) decendant_count[u][i] += tmp[i-1];
    }
    R[u] = counter-1;
  };
  dfs(0);


  SegmentTree one_st(n), k_st(n);
  vector<vector<ll>> k_update_tracker(n, vector<ll>(LG, 0));
  auto update_one = [&](int x, int y) {
    one_st.update(L[x], R[x], y);
  };

  auto update_k = [&](int x, int y, int k) {
    ll total = 0;
    total += y;
    for (int i = 1; i < LG; i++) {
      y /= k;
      k_update_tracker[x][i] += y;
      total += y*decendant_count[x][i];
    }
    k_st.update(L[x], L[x], total);
  };

  auto solve = [&](int x) {
    ll result = 0;
    result += one_st.query(L[x], R[x]);
    
    result += k_st.query(L[x], R[x]);
    for (int j = 1, u = parent[x]; j < LG && u != -1; j++, u = parent[u]) {
      for (int i = 0; i+j < LG; i++) {
        result += k_update_tracker[u][i+j] * decendant_count[x][i];
      }
    }
    return result;
  };
  for (int i = 0; i < q; i++) {
    int op; cin >> op;
    if (op == 1) {
      int x, y, k; cin >> x >> y >> k;
      x--;
      if (k == 1) update_one(x, y);
      else update_k(x, y, k);
    }
    else {
      int x; cin >> x;
      x--;
      cout << solve(x) << "\n";
    }
  }

  

  return 0;
}