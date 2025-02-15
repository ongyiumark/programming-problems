#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e18;
struct SegmentTree {
    int n;
    vector<ll> tree;
    SegmentTree(vector<ll> &ar) {
        n = ar.size();
        tree.resize(4*n, -INF);
        build(ar, 1, 0, n-1);
    }

    void pull(int p) {
        tree[p] = max(tree[p<<1], tree[p<<1|1]);
    }
    void build(vector<ll> &ar, int p, int l, int r) {
        if (l == r) {
            tree[p] = ar[l];
            return;
        }
        int k = (l+r)/2;
        build(ar, p<<1, l, k);
        build(ar, p<<1|1, k+1, r);
        pull(p);
    }

    ll query(int l, int r, int p, int _l, int _r) {
        if (l <= _l && _r <= r) {
            return tree[p];
        }
        else if (_r < l || r < _l) return -INF;
        else {
            int k = (_l+_r)/2;
            return max(query(l, r, p<<1, _l, k), query(l, r, p<<1|1, k+1, _r));
        }
    }

    ll query(int l, int r) {
        return query(l, r, 1, 0, n-1);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> A(n), B(n);
    for (ll &x : A) cin >> x;
    for (int i = 0, j = 1; i < n; i++) {
        while (j < n && 2*A[i] > A[j]) j++;
        B[i] = j-i;
    }

    SegmentTree st(B);

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        int k = 0;
        int lo = 1, hi = (r-l+1)/2;

        while (lo <= hi) {
            int mid = hi - (hi-lo)/2;
            if (l+mid-1 <= n-1 && l+mid-1 + max((ll)mid, st.query(l, l+mid-1)) <= r) {
                k = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }

        cout << k << "\n";
    }
    return 0;
}