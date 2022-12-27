#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5+5;
vector<int> graph[N];
bool dead[N];
pair<int,int> Q[N];

queue<int> monarch;

void dfs(int u) {
    monarch.push(u);
    for (int v : graph[u]) {
        dfs(v);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q; cin >> q;
    int idx = 2;
    memset(dead, 0, sizeof dead);
    for (int i = 0; i < q; i++) {
        int t,x; cin >> t >> x;
        Q[i] = {t, x};
        if (t == 1) graph[x].push_back(idx++);
    }
    
    dfs(1);

    for (int i = 0; i < q; i++) {
        int t = Q[i].first;
        int x = Q[i].second;
        if (t == 2) {
            dead[x] = 1;
            while(dead[monarch.front()]) {
                monarch.pop();
            }
            cout << monarch.front() << endl;
        }
    }
  
    return 0;
}