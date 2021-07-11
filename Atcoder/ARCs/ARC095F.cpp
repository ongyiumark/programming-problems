/*
    Notice that trees created this way are caterpillar trees.
    To check if a given tree is a caterpillar tree, we check if all nodes not in the diameter are leaves.
    
    We can generate an isomorphic tree by moving from head to tail or tail to head 
      (whichever is lexicographically smaller).

    The sequence always starts with 1. When a node has leaves, we put its leaves first, then the node itself.
    For example, if the second node from the head has 3 leaves, it would be 1 3 4 5 2... 
      where 3,4,5 are the leaves of 2.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5+5;
vector<int> graph[N];
bool vis[N];
int par[N];
int child[N];

int bfs(int s){
    memset(vis, 0, sizeof vis);
    memset(par, -1, sizeof par);
    queue<int> q;
    q.push(s);
    vis[s] = 1;

    int moves = 0;
    int currlayers = 1;
    int nextlayers = 0;

    int hi = 0;
    int res = s;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        if (moves >= hi){
            hi = moves;
            res = u;
        }

        for (int v : graph[u]){
            if (vis[v]) continue;
            nextlayers++;
            q.push(v);
            vis[v] = 1;
            par[v] = u;
        }

        currlayers--;
        if (currlayers == 0){
            moves++;
            currlayers = nextlayers;
            nextlayers = 0;
        }
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int s = bfs(1);
    int t = bfs(s);

    memset(child, -1, sizeof child);
    //cout << s << " " << t << endl;

    int v = t;
    set<int> nodes;
    while(v != -1){
        nodes.insert(v);
        for (int u : graph[v]){
            nodes.insert(u);
        }
        if (par[v] != -1) child[par[v]] = v;
        v = par[v];
    }

    if (nodes.size() != n){
        cout << -1 << endl;
        return 0;
    }

    // tail to head
    vector<int> ans1;
    int curr = 1;
    v = t;
    while(v != -1){
        int tmp = curr+1;
        for (int u : graph[v]){
            if (u == par[v]) continue;
            if (u == child[v]) continue;
            ans1.push_back(tmp++);
        }
        ans1.push_back(curr);
        v = par[v];
        curr = tmp;
    }

    // head to tail
    vector<int> ans2;
    curr = 1;
    v = s;
    while(v != -1){
        int tmp = curr+1;
        for (int u : graph[v]){
            if (u == par[v]) continue;
            if (u == child[v]) continue;
            ans2.push_back(tmp++);
        }
        ans2.push_back(curr);
        v = child[v];
        curr = tmp;
    }

    // compare ans1 and ans2
    bool isfirst;

    for (int i = 0; i < n; i++){
        if (ans1[i] == ans2[i]) continue;
        isfirst = ans1[i] < ans2[i];
        break;
    }

    if (isfirst){
        for (int i = 0; i < n; i++){
            cout << ans1[i];
            cout << (i < n-1 ? " " : "\n");
        }
    }
    else {
        for (int i = 0; i < n; i++){
            cout << ans2[i];
            cout << (i < n-1 ? " " : "\n");
        }
    }
    return 0;
}