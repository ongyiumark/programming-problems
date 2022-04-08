/*
  We can compute Q(L,R+1) quickly from Q(L,R).
  So, we can use Mo's Algorithm.

  Since we don't know how to do Q(L+1,R) or Q(L,R-1),
    we can compute Q(L',R) where L' is first index outside the bin of L.
  Then compute Q(L,L').
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 5e4+5;
const int M = 5e3+5;
const int INF = 1e9;
const int LOGA = 25;
int A[N];

int convert(int x) {
  int rem = x%4;
  if (rem == 0) return x;
  if (rem == 1) return 1;
  if (rem == 2) return x+1;
  return 0;
}

struct query {
  int l, r, i;
};

query qs[M];
int ans[M];

struct node {
  int c[2];
  int val, p;

  node() {
    c[0] = c[1] = p = -1;
    // 0 is the trie that holds minimum.
    // 1 is the trie that holds maximum.
    val = INF;
  }
};

node t[2][N*LOGA];
int tidx[2];

void reset_trie() {
  for (int i = 0; i < 2; i++) {
    tidx[i] = 0;
    t[i][tidx[i]] = node();
  }
}

int create_node(int i, int p) {
  tidx[i]++;
  t[i][tidx[i]] = node();
  t[i][tidx[i]].p = p;
  return tidx[i];
}

void add(int i, int xval, int aval) {
  int cidx = 0;
  for (int j = LOGA-1; j >= 0; j--) {
    int bit = (((1<<j)&xval) ? 1 : 0);
    int &v = t[i][cidx].c[bit];
    if (v == -1) v = create_node(i, cidx);
    cidx = v;
  }

  // Actual value node
  t[i][cidx].val = min(t[i][cidx].val, aval);

  // Propagate up
  while(cidx != 0) {
    cidx = t[i][cidx].p;
    if (t[i][cidx].c[0] != -1) t[i][cidx].val = min(t[i][cidx].val, t[i][t[i][cidx].c[0]].val);
    if (t[i][cidx].c[1] != -1) t[i][cidx].val = min(t[i][cidx].val, t[i][t[i][cidx].c[1]].val);
  }
}

int calculate(int i, int xval, int aval){
  int cidx = 0;
  int res = 0;
  if (t[i][cidx].val > aval) return 0;

  for (int j = LOGA-1; j >= 0; j--) {
    int bit = (((1<<j)&xval) ? 1 : 0);

    // Try opposite bit first.
    int v = t[i][cidx].c[1-bit];
    if (v != -1 && t[i][v].val <= aval) {
      cidx = v;
      res |= (1<<j);
    }
    else cidx = t[i][cidx].c[bit];
  }
  return res;
}

void solve(int l, int r, int up) {
  sort(qs+l, qs+r+1, [](const query &a, const query &b) {
    return a.r < b.r;
  });

  reset_trie();
  int cr = up;
  int tmp = 0;
  for (int i = l; i <= r; i++) {
    while(cr <= qs[i].r) {
      // Move right end starting from outside the block.
      int x = A[cr++];
      add(0, convert(x-1), x);
      add(1, convert(x), -x);

      tmp = max(tmp, calculate(0, convert(x), x));
      tmp = max(tmp, calculate(1, convert(x-1), -x));
    }

    int ntmp = tmp;
    for (int j = qs[i].l; j <= min(up,qs[i].r); j++){
      // Calculate left end to end of block.
      int x = A[j];
      ntmp = max(ntmp, calculate(0, convert(x), x));
      ntmp = max(ntmp, calculate(1, convert(x-1), -x));
    }

    ans[qs[i].i] = max(ans[qs[i].i], ntmp); 
  }

  for (int i = l; i <= r; i++) {
    int ntmp = 0;
    reset_trie();
    for (int j = qs[i].l; j <= min(up,qs[i].r); j++){
      // Calculate left end to end of block.
      int x = A[j];
      add(0, convert(x-1), x);
      add(1, convert(x), -x);

      ntmp = max(ntmp, calculate(0, convert(x), x));
      ntmp = max(ntmp, calculate(1, convert(x-1), -x));
    }

    ans[qs[i].i] = max(ans[qs[i].i], ntmp); 
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> A[i];
  for (int i = 0; i < m; i++) {
    int l, r; cin >> l >> r;
    l--; r--;
    qs[i].l = l; qs[i].r = r;
    qs[i].i = i;
  }

  memset(ans, 0, sizeof ans);
  sort(qs, qs+m, [](const query &a, const query &b) {
    return a.l < b.l;
  });

  int del = 300;
  int l = 0, r = 0;
  for (int i = 0; i < n && l < m; i+=del){
    int up = min(i+del,n);
    while (r < m) {
      if (qs[r].l >= up) break;
      r++;
    }
    solve(l, r-1, up);
    l = r;
  }

  for (int i = 0; i < m; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
