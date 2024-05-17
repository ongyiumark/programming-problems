#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
 
const int INF = 1e9;
struct segtree {
    int i, j, val, delta;
    segtree* child_l;
    segtree* child_r;
    ~segtree() { delete child_l, delete child_r; }
    segtree(int l, int r) : segtree(l, r, -INF, -INF, nullptr, nullptr) {}
    segtree(int l, int r, int val, int delta, segtree* child_l, segtree* child_r)
        : i(l), j(r), val(val), delta(delta), child_l(child_l), child_r(child_r) {}
 
    segtree* apply_delta(int d) {
        return new segtree(i, j, d, d, child_l, child_r);
    };
 
    void push() {
        int k = (i+j) / 2;
        if (i != j) {
          if (not child_l) child_l = new segtree(i, k);
          if (not child_r) child_r = new segtree(k+1, j);
        }

        if (delta != -INF) {
            val = delta;
            if (i != j) {
                //segtree *old_l = child_l, *old_r = child_r;
                child_l = child_l->apply_delta(delta);
                child_r = child_r->apply_delta(delta);
                //delete old_l, delete old_r;
            }
            delta = -INF;
        }
    }
 
    segtree* update(int l, int r, int v) {
        push();
        if (l <= i and j <= r) {
            segtree* result = apply_delta(v);
            result->push();
            return result;
        } else if (r < i or j < l) {
            return this;
        } else {
            segtree* new_child_l = child_l->update(l, r, v);
            segtree* new_child_r = child_r->update(l, r, v);
            return new segtree(
                i, j,
                max(new_child_l->val, new_child_r->val),
                -INF,
                new_child_l, new_child_r
            );
        }
    }
 
    int query(int l, int r) {
        push();
        if (l <= i and j <= r) {
            return val;
        } else if (r < i or j < l) {
            return -INF;
        } else {
            int result = -INF;
            if (child_l) result = max(result, child_l->query(l, r));
            if (child_r) result = max(result, child_r->query(l, r));
            return result;
        }
    }
};
 
const int MAXE = 2e5+5;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, e; cin >> n >> e;

  vector<int> coords(2*e+1);
  vector<tuple<short, string, int,int>> qs(e+1);
  vector<int> compress(n+1);
  vector<segtree*> segtrees;

  vector<bool> done(e+1);
  vector<int> p(e+1);

  int cidx = 0;
  for (int i = 0; i < e; i++) {
    auto &[op, name, a, b] = qs[i];
    cin >> op;
    // /cout << op << endl;
    if (op == 1) cin >> name >> a >> b;
    else cin >> a >> b;
    coords[cidx++] = a;
    coords[cidx++] = b;
  }
  sort(coords.begin(), coords.end());
  coords.erase(unique(coords.begin(), coords.end()), coords.end());

  int sz = coords.size();
  for (int i = 0; i < sz; i++) compress[coords[i]] = i; 
  coords.clear();

  segtrees.push_back(new segtree(0, sz-1));
  function<int(int)> find = [&](int x){
    if (p[x] <= 0) return p[x];
    else return p[x] = find(p[x]);
  };
 
  for (int i = 1; i <= e; i++) {
    //cout << i << endl;
    auto &[op, name, a, b] = qs[i-1];
    if (op == 1) {
      p[i] = -segtrees.size();
      int acmp = compress[a];
      int bcmp = compress[b];
      segtrees.push_back(segtrees.back()->update(acmp, bcmp, i));
    }
    else {
      int ccmp = compress[a], dcmp = compress[b];
      p[i] = i-1;
      int ans = -INF;
      int idx = -find(i);
      //cout << i <<  " - start " << idx << " " << find(i-1) <<endl;
      while (true) {
        ans = segtrees[idx]->query(ccmp,dcmp);
        //cout << idx << " " << ans << endl;
        if (ans == -INF || !done[ans]) break;
        idx = -find(ans-1);
      }
      
      if (ans == -INF) cout << ">_<\n";
      else {
        cout << get<1>(qs[ans-1]) << "\n";
        done[ans] = 1;
        p[ans] = find(ans)+1;
      }
    }
  }
 
  return 0;
}