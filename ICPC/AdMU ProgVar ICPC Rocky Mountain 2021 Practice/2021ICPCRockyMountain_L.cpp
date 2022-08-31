#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

template<typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct dsu {
    vector<int> p;
    dsu(int n) : p(n,-1) {}

    int find(int x) {
        if (p[x] < 0) return x;
        return p[x] = find(p[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;

        if (p[a] > p[b]) swap(a,b);
        p[a] += p[b];
        p[b] = a;

        return true;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    dsu uf(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        uf.unite(u,v);
    }

    ll num = 0;
    for (int i = 0; i < n; i++) {
        if (uf.p[i] >= 0) continue;
        int sz = -uf.p[i];
        num += (ll)sz*(sz-1)/2;
    }
    ll den = (ll)n*(n-1)/2;

    cout << fixed << setprecision(10) << (ld)num/den << endl;

    return 0;
}