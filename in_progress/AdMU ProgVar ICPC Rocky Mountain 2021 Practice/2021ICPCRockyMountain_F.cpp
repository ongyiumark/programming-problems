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

const int N = 305;
int dp[N][N][N][2];
int s[N], p[N];
vector<int> graph[N];
vector<int> children[N];

void dfs(int u, int p) {
    for (int v : graph[u]) {
        if (v == p) continue;
        children[u].push_back(v);
        dfs(v, u);
    }
}

int solve(int u, int child, int cap, bool parent_picked) {
    int &ans = dp[u][child][cap][parent_picked];
    if (ans != -1) return ans;
    if (children[u].size() == 0) {
        if (cap >= s[u] && !parent_picked) ans = p[u];
        else ans = 0;
        return ans;
    }

    if (children[u].size() <= child) return 0;

    ans = 0;
    if (child > 0) {
        for (int i = 0; i <= cap; i++) {
            ans = max(ans, solve(children[u][child], 0, i, parent_picked) + solve(u, child+1, cap-i, parent_picked));
        }
    }  
    else if (parent_picked) {
        for (int i = 0; i <= cap; i++) {
            ans = max(ans, solve(children[u][child], 0, i, false) + solve(u, child+1, cap-i, false));
        }
    } 
    else {
        for (int i = 0; i <= cap; i++) {
            if (cap-s[u] >= i) ans = max(ans, p[u]+solve(children[u][child], 0, i, true)+solve(u, child+1, cap-s[u]-i, true));
            ans = max(ans, solve(children[u][child], 0, i, false) + solve(u, child+1, cap-i, false));
        }
    }
    return ans;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int S; cin >> S;

    for (int i = 0; i < n; i++) cin >> s[i] >> p[i];
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(dp, -1, sizeof dp);
    dfs(0, -1);
    cout << solve(0, 0, S, false) << endl;

    return 0;
}