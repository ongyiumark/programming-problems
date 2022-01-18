#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T,null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;

const int N = 50;
int C[N];
vector<int> graph[N];

int solve(int u, int p){
    int ans = 0;
    for (int v : graph[u]){
        if (v == p) continue;
        ans = max(solve(v,u), ans);
    }
    return ans+C[u];
}
void testcase(){
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        graph[i].clear();
    }    
    for (int i = 0; i < n; i++) cin >> C[i];
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    vector<int> ans;
    for (int v : graph[0]){
        ans.push_back(solve(v,0));
    }

    sort(ans.begin(), ans.end(), greater<int>());

    if (ans.size() == 0) cout << C[0] << endl;
    else if (ans.size() == 1) cout << ans[0]+C[0] << endl;
    else cout << ans[0]+ans[1]+C[0] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int x = 1; x <= t; x++){
        cout << "Case #" << x << ": ";
        testcase();
    }
    return 0;
}