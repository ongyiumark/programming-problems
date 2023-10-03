#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, q; cin >> n >> m >> q;
    vector<pair<int,int>> ar(n, {0,0});
    vector<int> c(2*n);
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        x--;
        c[x] = c[x+n] = 1;
    }

    vector<int> p(2*n);
    p[0] = c[0];
    for (int i = 1; i < 2*n; i++) p[i] = p[i-1] + c[i];

    vector<pair<int,char>> qs(q);
    for (int i = 0; i < q; i++) {
        int id; char c;
        cin >> id >> c;
        id--;
        qs[i] = {id, c};
    }

    vector<bool> pos(n);
    for (int i = q-1; i >= 0; i--) {
        auto [id, c] = qs[i];
        if (c == 'L') ar[id].first = ar[(id+1)%n].first+1;
        else ar[id].second = ar[(id-1+n)%n].second+1;

        int r = id+ar[id].first;
        int l = id-ar[id].second;
        ll total = 0;
        if (r-l+1 > n) total = p[n-1];
        else {
            if (l < 0) {
                l += n;
                r += n;
            }
            if (r >= 2*n) {
                l -= n;
                r -= n;
            }

            total = p[r];
            if (l > 0) total -= p[l-1];
        }

        if (total == m) pos[id] = 1;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
        if (pos[i]) ans.push_back(i+1);

    int sz = ans.size();
    for (int i = 0; i < sz; i++) {
        cout << ans[i];
        cout << (i+1 < sz ? " " : "\n");
    }

    return 0;
}