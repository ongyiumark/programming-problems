#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<ll,int> ii;

template<typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 3e5+5;
vector<int> child[N];
int p[N], b[N];
ll v[N];
priority_queue<ii, vector<ii>, greater<ii>> cities[N];

int dfs(int u) {
    int hi = 0;
    int idx = -1;
    for (int vv : child[u]) {
        int cnt = dfs(vv);
        if (min(cnt,b[vv]) > hi) {
            hi = min(cnt, b[vv]);
            idx = vv;
        }
    }
    if (idx != -1){
        swap(cities[u], cities[idx]);
        for (int vv : child[u]) {
            if (vv == idx) continue;
            while (!cities[vv].empty()) {
                cities[u].push(cities[vv].top());
                cities[vv].pop();
            }
         }
    }
    cities[u].push({v[u], u});
    while(cities[u].size() > b[u]) cities[u].pop();
    return cities[u].size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    p[1] = 1;
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        child[p[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> v[i];

    dfs(1);
    vector<ll> ans;
    ll total = 0;
    for (int i = 0; i < b[1]; i++) {
        if (!cities[1].empty()) {
            ans.push_back(cities[1].top().second);
            total += cities[1].top().first;
            cities[1].pop();
        }
        else break;
    }

    cout << total << endl;
    sort(ans.begin(), ans.end());
    int m = ans.size();
    cout << m;
    if (m > 0) cout << " ";
    for (int i = 0; i < m; i++) {
        cout << ans[i];
        if (i < m-1) cout << " ";
        else cout << endl;
    }
    return 0;
}