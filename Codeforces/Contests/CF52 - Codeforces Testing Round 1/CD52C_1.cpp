#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegmentTreeMin {
  const static inline ll Identity = 1e18;
  int i, j; ll val, lazy = 0;

  SegmentTreeMin *left, *right;
  ~SegmentTreeMin() { delete left, delete right; }
  SegmentTreeMin(int i, int j) : i(i), j(j) {
    if (i == j) {
      left = right = nullptr;
      val = Identity;
      return;
    }
    int k = (i+j)/2;
    left = new SegmentTreeMin(i, k);
    right = new SegmentTreeMin(k+1, j);
    pull();
  }
  SegmentTreeMin(vector<ll> &ar, int i, int j) : i(i), j(j) {
    if (i == j) {
      val = ar[i];
      left = right = nullptr;
      return;
    }
    int k = (i+j)/2;
    left = new SegmentTreeMin(ar, i, k);
    right = new SegmentTreeMin(ar, k+1, j);
    pull();
  }
  void pull() { val = min(left->val, right->val); }
  void push() {
    if (lazy) {
      val += lazy;
      if (i != j) {
        left->lazy += lazy;
        right->lazy += lazy;
      }
      lazy = 0;
    }
  }
  void update(int l, int r, ll v) {
    push();
    if (l <= i && j <= r) lazy += v, push();
    else if (j < l || r < i) {}
    else {
      int k = (i+j)/2;
      left->update(l, r, v);
      right->update(l, r, v);
      pull();
    }
  }
  ll query(int l, int r) {
    push();
    //cout << i << " " << j << endl;
    if (l <= i && j <= r) return val;
    else if (j < l || r < i) return Identity;
    else return min(left->query(l,r),right->query(l,r));
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
  SegmentTree st(ar, 0, n-1);
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