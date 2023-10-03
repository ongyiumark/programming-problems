#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector<int> c, p;
vector<vector<int>> adj;
vector<tuple<int,int,int>> qs;

struct segtree {
    vector<ll> vals, deltas;
    segtree (vector<ll> &ar) {
        int n = ar.size();
        vals.resize(4*n, 0);
        deltas.resize(4*n, 0);
        build(ar, 1, 0, n-1);
    }

    void build(vector<ll> &ar, int p, int i, int j) {
        if (i == j) {
            vals[p] = ar[i];
            return;
        }
        int k = (i+j)>>1;
        build(ar, p<<1, i, k);
        build(ar, p<<1|1, k+1, j);
        pull(p);
    }

    void pull(int p) {
        vals[p] = vals[p<<1] + vals[p<<1|1];
    }

    void push(int p, int i, int j) {
        if (deltas[p]) {
            vals[p] += (j-i+1)*deltas[p];
            if (i != j) {
                deltas[p<<1] += deltas[p];
                deltas[p<<1|1] += deltas[p];
            }

            deltas[p] = 0;
        }
    }

    void update(int l, int r, int v, int p, int i, int j) {
        push(p, i, j);
        if (l <= i && j <= r) {
            deltas[p] += v;
            push(p, i, j);
        }
        else if (j < l || r < i) { }
        else {
            int k = (i+j)>>1;
            update(l, r, v, p<<1, i, k);
            update(l, r, v, p<<1|1, k+1, j);
            pull(p);
        }
    }

    ll query(int l, int r, int p, int i, int j) {
        if (l <= i && j <= r) return vals[p];
        else if (j < l || r < i) return 0;
        else {
            int k = (i+j)>>1;
            return query(l, r, p<<1, i, k) + query(l, r, p<<1|1, k+1, j);
        }
    }
};

ll solve(int u, vector<ll> &dp) {
    dp[u] = c[u];
    for (int v : adj[u]) {
        dp[u] += solve(v, dp);
    }    
    return dp[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    c.resize(n); p.resize(n);
    adj.resize(n, vector<int>());
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        p[i]--;
        adj[p[i]].push_back(i);
    }
    qs.resize(q);
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        qs[i] = {a,b,i};
    }
    sort(qs.begin(), qs.end());
    
    vector<ll> ans(q);
    vector<bool> active(n, 0);
    vector<ll> dp(n, -1);
    solve(0, dp);

    vector<ll> ar(n, 0);
    ar[0] = dp[0];
    active[0] = 1;

    segtree st(ar);
    int ci = 0;
    for (int i = 0; i < q; i++) {
        auto [a, b, id] = qs[i];
        while (ci < a) {
            for (int v : adj[ci]) {
                if (!active[v]) {
                    active[v] = true;
                    st.update(v, v, dp[v], 1, 0, n-1);
                }
            }
            ci++;
        }

        ans[id] = st.query(a, b, 1, 0, n-1);
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}