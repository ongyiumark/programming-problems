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

const int N = 8e5+5;
vector<int> graph[N];
int F[N];
map<int,int> Fcnt;
bool edges[N];
map<pair<int,int>, int> edgeno;

pair<bitset<N>, bitset<N>> dfs(int u, int p){
    pair<bitset<N>, bitset<N>> res;
    res.first.set();
    res.second.reset();
    for (int v : graph[u]){
        if (v == p) continue;
        pair<bitset<N>, bitset<N>> tmp = dfs(v, u);
        res.first = (res.first)&(tmp.first);
        res.second = (res.second)|(tmp.second);
    }

    if (Fcnt[F[u]] == 1) res.first.reset(F[u]);
    res.second.set(F[u]);
    int cnt = ((res.first)&(res.second)).count();
    if (cnt == 0){
        int a = min(u, p);
        int b = max(u, p);
        edges[edgeno[{a,b}]]=1;
    }
    return res;
}

int n;
void testcase(){
    cin >> n;
    for (int i = 0; i < n; i++){
        graph[i].clear();
    }
    Fcnt.clear();
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        if (a > b) swap(a,b);
        graph[a].push_back(b);
        graph[b].push_back(a);
        edgeno[{a,b}] = i;
        edges[i] = 0;
    }

    for (int i = 0; i < n; i++){
        cin >> F[i];
        Fcnt[F[i]]++;
    }

    dfs(1, -1);
    int cnt = 0;
    for (int i = 0; i < n-1; i++){
        cnt += edges[i];
    }
    cout << cnt << endl;
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