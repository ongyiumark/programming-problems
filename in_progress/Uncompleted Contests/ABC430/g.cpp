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

const int MAXN = 3e5+5;

struct S {
    int max, cnt;
};

struct F {
    int x;
};

S e() { return {0,1}; }
F id() { return {0}; }
S op(S x, S y) {
    S ret;
    if (x.max > y.max) {
        ret.max = x.max;
        ret.cnt = x.cnt;
    }
    else if (x.max < y.max) {
        ret.max = y.max;
        ret.cnt = y.cnt;
    }
    else {
        ret.max = x.max;
        ret.cnt = x.cnt+y.cnt;
    }
    return ret;
}
S mapping(F f, S x) {
    S ret = x;
    ret.max += f.x;
    return ret;
}
F composition(F g, F f) {
    F ret;
    ret.x = g.x+f.x;
    return ret;
}

struct SegmentTree {
    int n; vector<S> st; vector<F> lz;
    SegmentTree(int n) : n(n), st(4*n, e()), lz(4*n, id()) {
        build(1, 0, n-1);
    }
    void build(int p, int i, int j) {
        if (i != j) {
            int k = (i+j)/2;
            build(p<<1, i, k);
            build(p<<1|1, k+1, j);
            pull(p);
        }
        else st[p] = e();
    }
    void pull(int p) {
        st[p] = op(st[p<<1], st[p<<1|1]);
    }
    void push(int p, int i, int j) {
        st[p] = mapping(lz[p], st[p]);
        if (i != j) {
            lz[p<<1] = composition(lz[p], lz[p<<1]);
            lz[p<<1|1] = composition(lz[p], lz[p<<1|1]);
        }
        lz[p] = id();
    }
    void update(int l, int r, F f) {
        update(l, r, f, 1, 0, n-1);
    }
    void update(int l, int r, F f, int p, int i, int j) {
        push(p, i, j);
        if (l <= i && j <= r) {
            lz[p] = composition(f, lz[p]);
            push(p, i, j);
        }
        else if (j < l || r < i) {}
        else {
            int k = (i+j)/2;
            update(l, r, f, p<<1, i, k);
            update(l, r, f, p<<1|1, k+1, j);
            pull(p);
        }
    }
    S query(int l, int r) {
        return query(l, r, 1, 0, n-1);
    }
    S query(int l, int r, int p, int i, int j) {
        push(p, i, j);
        if (l <= i && j <= r) { return st[p]; }
        else if (j < l || r < i) { return e(); }
        else {
            int k = (i+j)/2;
            return op(query(l, r, p<<1, i, k), query(l, r, p<<1|1, k+1, j));
        }
    }
};

SegmentTree segtree(MAXN);
vector<set<ii>> intervals(60);

set<ii>::iterator add_interval(set<ii> &s, int l, int r) {
    auto it = s.lower_bound({l,r});
    set<ii>::iterator loc = it;
    while (it != s.end() && it->first <= r) {
        r = max(r, it->second);
        segtree.update(it->first, it->second, {-1});
        loc = it = s.erase(it);
    }
    if (it != s.begin() && (--it)->second >= l) {
        l = min(l, it->first);
        r = max(r, it->second);
        segtree.update(it->first, it->second, {-1});
        s.erase(it);
    }
    segtree.update(l, r, {1});
    return s.insert(loc, {l, r});
}

void remove_interval(set<ii> &s, int l, int r) {
    auto it = add_interval(s, l, r);
    ii new_interval = *it;
    s.erase(it);

    if (r < new_interval.second) {  s.insert({r+1, new_interval.second}); }
    if (new_interval.first < l) { s.insert({new_interval.first, l-1}); }
    segtree.update(l, r, {-1});
}

int main(){
  cin.tie(0)->sync_with_stdio(false);
  

  int n, q; cin >> n >> q;
  while(q--) {
    int t; cin >> t;
    int l, r; cin >> l >> r;
    l--; r--;
    int x = -1;
    if (t != 3) {
        cin >> x;
        x--;
    }
    
    if (t == 1) { add_interval(intervals[x], l, r); }
    else if (t == 2) { remove_interval(intervals[x], l, r); }
    else {
        S res = segtree.query(l, r);
        cout << res.max << " " << res.cnt << "\n";
    }
  }
  
  return 0;
}
