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
    ll a, b; // intersection, union
    int max, cnt;
    bool fail;
};

struct F {
    ll a, b; // f(x) = (x \cap a) \cup b
};

S e() { return {-1,0,0,1,false}; } // -1 sets all bits
F id() { return {-1,0}; }
S op(S x, S y) {
    S ret;
    ret.a = x.a&y.a;
    ret.b = x.b|y.b;
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
    ret.fail = false;
    return ret;
}
S mapping(F f, S x) {
    if ((~f.a|f.b)&(x.b^~x.a)) {
        // ~f.a|f.b are all elements that will be removed or added
        // x.b^x.a is union minus intersection
        return {0,0,0,0,true};
    }
    S ret = x;
    ret.max -= __builtin_popcountll(ret.a&~f.a);
    ret.a &= f.a;
    ret.b &= f.a;
    
    ret.max += __builtin_popcountll(~ret.b&f.b);
    ret.a |= f.b;
    ret.b |= f.b;
    return ret;
}
F composition(F g, F f) {
    F ret;
    ret.a = f.a&g.a;
    ret.b = (f.b&g.a)|g.b;
    return ret;
}

struct SegmentTree {
    int n; vector<S> st; vector<F> lazy;
    SegmentTree(int n) : n(n), st(4*n, e()), lazy(4*n, id()) {}
    void pull(int p) {
        st[p] = op(st[p<<1], st[p<<1|1]);
    }
    void push(int p, int i, int j) {
        st[p] = mapping(lazy[p], st[p]);
        if (i != j) {
            lazy[p<<1] = composition(lazy[p], lazy[p<<1]);
            lazy[p<<1|1] = composition(lazy[p], lazy[p<<1|1]);
        }
        lazy[p] = id();
    }
    void update(int l, int r, F f) {
        update(l, r, f, 1, 0, n-1);
    }
    void update(int l, int r, F f, int p, int i, int j) {
        push(p, i, j);
        if (l <= i && j <= r) {
            lazy[p] = composition(f, lazy[p]);
            // cout << lazy[p].a << " " << lazy[p].b << endl;
            // cout << st[p].a << " " << st[p].b << " " << st[p].max << " " << st[p].cnt << " " << st[p].fail << endl;

            push(p, i, j);
            if (i != j) {
                cout << lazy[p<<1].a << " " << lazy[p<<1].b << endl;
                cout << lazy[p<<1|1].a << " " << lazy[p<<1|1].b << endl;
                cout << st[p<<1].a << " " << st[p<<1].b << " " << st[p<<1].max << " " << st[p<<1].cnt << " " << st[p<<1].fail << endl;
                cout << st[p<<1|1].a << " " << st[p<<1|1].b << " " << st[p<<1|1].max << " " << st[p<<1|1].cnt << " " << st[p<<1|1].fail << endl;
            }

            // cout << p << " " << i << " " << j << " " << st[p].fail << endl;
            // cout << st[p].a << " " << st[p].b << " " << st[p].max << " " << st[p].cnt << " " << st[p].fail << endl;
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
        if (l <= i && j <= r) { 
            if (st[p].fail) {
                int k = (i+j)/2;
                return op(query(l, r, p<<1, i, k), query(l, r, p<<1|1, k+1, j));
            }
            return st[p];
        }
        else if (j < l || r < i) { return e(); }
        else {
            int k = (i+j)/2;
            return op(query(l, r, p<<1, i, k), query(l, r, p<<1|1, k+1, j));
        }
    }
};

SegmentTree segtree(MAXN);

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
        
    if (t == 1) segtree.update(l, r, {-1, (1LL<<x)});
    else if (t == 2) segtree.update(l, r, {~(1LL<<x), 0});
    else {
        S res = segtree.query(l, r);
        cout << res.max << " " << res.cnt << "\n";
    }

    cout << "Array: " << endl;
    // vector<int> ind = {524'288, 524'289, 262'145, 262'146};
    for (int i = 0; i < 4; i++) {
        S ret = segtree.query(i, i);
        cout << ((ret.b>>9)&1) << " " << ((ret.b>>19)&1) << endl;
    }
    cout << endl;

    if (q == 3) break;
  }
  
  return 0;
}
