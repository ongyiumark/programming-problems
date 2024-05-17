#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;

struct Node {
  int i, j, val, delta, lc, rc;
  Node (int i, int j, int val, int delta, int lc, int rc) 
    : i(i), j(j), val(val), delta(delta), lc(lc), rc(rc) {}
  Node() {}
};

const int MAXN = 2e7;
Node nodes[MAXN];
int counter = 0;
 
int segtree(int i, int j, int val=-INF, int delta=-INF, int lc=-1, int rc=-1) {
  nodes[counter] = Node(i, j, val, delta, lc, rc);
  return counter++;
}
 
int apply_delta(int node_idx, int d) {
  auto [i, j, val, delta, lc, rc] = nodes[node_idx];
  return segtree(i, j, d, d, lc, rc);
}
 
void push(int node_idx) {
  auto [i, j, val, delta, lc, rc] = nodes[node_idx];
  int k = (i+j)/2;
  if (i != j) {
    if (lc == -1) nodes[node_idx].lc = segtree(i, k);
    if (rc == -1) nodes[node_idx].rc = segtree(k+1, j);
  }
  if (delta != -INF) {
    nodes[node_idx].val = delta;
    if (i != j) {
      nodes[node_idx].lc = apply_delta(nodes[node_idx].lc, delta);
      nodes[node_idx].rc = apply_delta(nodes[node_idx].rc, delta);
    }
    nodes[node_idx].delta = -INF;
  }
}
 
int update(int node_idx, int l, int r, int v) {
  push(node_idx);
  auto [i, j, val, delta, lc, rc] = nodes[node_idx];
  if (l <= i and j <= r) {
    int result = apply_delta(node_idx, v);
    push(result);
    return result;
  } else if (r < i or j < l) {
    return node_idx;
  } else {
    int n_lc = update(lc, l, r, v);
    int n_rc = update(rc, l, r, v);
    return segtree(i, j, max(nodes[n_lc].val, nodes[n_rc].val), -INF, n_lc, n_rc);
  }
}
 
int query(int node_idx, int l, int r) {
  push(node_idx);
  auto [i, j, val, delta, lc, rc] = nodes[node_idx];
  if (l <= i and j <= r) {
    return val;
  } else if (r < i or j < l) {
    return -INF;
  } else {
    int result = -INF;
    if (lc != -1) result = max(result, query(lc, l, r));
    if (rc != -1) result = max(result, query(rc, l, r));
    return result;
  }
}


signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int n, e; cin >> n >> e;
  vector<string> names(e);
  set<pair<int,int>, greater<pair<int,int>>> segtrees;
  vector<bool> done(e);
  segtrees.insert({-INF, segtree(0, n+1)});

  for (int i = 0; i < e; ++i) {
      int t; cin >> t;
      if (t == 1) {
        cin >> names[i];
        int l, r; cin >> l >> r;
        int st = update(segtrees.begin()->second, l, r, i);
        segtrees.insert({i, st});
      } else {
        int l, r; cin >> l >> r;
        int idx = 2e9;
        while (true) {
          auto iter = segtrees.lower_bound({idx,-1});
          idx = query(iter->second, l, r);

          if (idx == -INF) {
            cout << ">_<\n";
            break;
          } else if (not done[idx]) {
            done[idx] = true;
            cout << names[idx] << '\n';
            segtrees.erase(segtrees.lower_bound({idx+1,-1}));
            break;
          }
        }
      }
  }

    return 0;
}