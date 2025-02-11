#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct FenwickTree {
    vector<int> ft;
    FenwickTree(int n) : ft(n+1) {}
    int query(int l, int r) { return query(r)-query(l-1); }
    int query(int i) {
        int total = 0;
        for (; i > 0; i -= (i&-i)) total += ft[i];
        return total;
    }
    void update(int i, int v) {
        for (; i < ft.size(); i += (i&-i))
            ft[i] += v;
    }
};

struct FenwickRUPQ {
    FenwickTree ft;
    FenwickRUPQ(int m) : ft(m) {}
    void update(int l, int r, int v) {
        ft.update(l,v); ft.update(r+1, -v);
    }
    int query(int i) { return ft.query(i); }
};

const int MAXN = 5e5+5;
FenwickRUPQ ft(MAXN);

int find_l(int l) {
    int lo = 1, hi = MAXN;
    int ans = hi+1;
    while (lo <= hi) {
        int mid = hi - (hi-lo)/2;
        if (l <= ft.query(mid)) {
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    return ans;
}

int find_r(int r) {
    int lo = 1, hi = MAXN;
    int ans = 0;
    while (lo <= hi) {
        int mid = hi - (hi-lo)/2;
        if (ft.query(mid) <= r) {
            ans = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i <= MAXN; i++) ft.update(i, MAXN, 1);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        
        int lo = 0, hi = MAXN;
        int _l = find_l(l), _r = find_r(r);
        ft.update(_l, _r, 1);
    }
    int q; cin >> q;
    while(q--) {
        int x; cin >> x;
        cout << ft.query(x) << "\n";
    }


    return 0;
}