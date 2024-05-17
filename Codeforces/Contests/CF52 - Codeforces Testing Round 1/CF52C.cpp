#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegmentTree {
  const static inline ll Identity = 1e18; 

  int n; vector<ll> st, lazy;
  SegmentTree(int n) : n(n), st(4*n, Identity), lazy(4*n, 0) {}
  SegmentTree(const vector<ll> &ar) {
    n = ar.size();
    st.assign(4*n, Identity); lazy.assign(4*n, 0);
    build(ar, 1, 0, n-1);
  }
  void build(const vector<ll>& ar, int p, int i, int j) {
    if (i == j) {
      st[p] = ar[i];
      return;
    }
    int k = (i+j)/2;
    build(ar, p<<1, i, k);
    build(ar, p<<1|1, k+1, j);
    pull(p);
  }
  void pull(int p) { st[p] = min(st[p<<1], st[p<<1|1]); }
  void push(int p, int i, int j) {
    if (lazy[p] != 0) {
      st[p] += lazy[p];
      if (i != j) {
        lazy[p<<1] += lazy[p];
        lazy[p<<1|1] += lazy[p];
      }
      lazy[p] = 0;
    }
  }
  void update(int l, int r, ll v) { 
    update(l, r, v, 1, 0, n-1); 
  }
  void update(int l, int r, ll v, int p, int i, int j) {
    push(p, i, j);
    if (l <= i && j <= r) {
      lazy[p] += v;
      push(p, i, j);
    }
    else if (j < l || r < i) {}
    else {
      int k = (i+j)/2;
      update(l, r, v, p<<1, i, k);
      update(l, r, v, p<<1|1, k+1, j);
      pull(p);
    }
  }
  ll query(int l, int r) { return query(l, r, 1, 0, n-1); }
  ll query(int l, int r, int p, int i, int j) {
    push(p, i, j);
    if (l <= i && j <= r) { return st[p]; }
    else if (j < l || r < i) { return Identity; }
    else {
      int k = (i+j)/2;
      return min(query(l, r, p<<1, i, k), query(l, r, p<<1|1, k+1, j));
    }
  }
};

vector<string> split(string &s) {
  stringstream sstream(s);
  vector<string> res; string token;
  while (getline(sstream, token, ' ')) {
    res.push_back(token);
  }
  return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> ar(n);
  for (ll &x : ar) cin >> x;
  SegmentTree st(ar);
  int m; cin >> m;
  cin.ignore();
  for (int i = 0; i < m; i++) {
    string s; getline(cin, s);
    vector<string> tokens = split(s);
    if (tokens.size() == 3) {
      int l = stoi(tokens[0]), r = stoi(tokens[1]);
      ll v = stoll(tokens[2]);
      if (l > r) st.update(l, n-1, v), st.update(0, r, v);
      else st.update(l, r, v);
    }
    else {
      int l = stoi(tokens[0]), r = stoi(tokens[1]);
      if (l > r) cout << min(st.query(l, n-1), st.query(0, r));
      else cout << st.query(l, r);
      cout << "\n";
    }

  }

  return 0;
}