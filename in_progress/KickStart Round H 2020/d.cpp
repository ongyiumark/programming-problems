#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 5e4+1;
string S[N];

ll graph[101][101];

set<int> friends[26];
void testcase(){
    for (int i = 0; i < 101; i++){
        for (int j = 0; j < 101; j++){
            graph[i][j] = 1e9;
        }
    }
    for (int i = 0; i < 26; i++){
        friends[i].clear();
    }

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++){
        cin >> S[i];
    }

    if (n > 100){
        while(q--){
            cout << -1;
            if (q == 0) cout << endl;
            else cout << " ";
        }
        return;
    }

    for (int i = 1; i <= n; i++){
        string curr = S[i];
        for (int j = 0; j <(int)curr.size(); j++){
            for (auto s : friends[curr[j]-'A']){
                //cout << s << endl;
                graph[i][s] = 2;
                graph[s][i] = 2;
            }
            friends[curr[j]-'A'].insert(i);
        }
    }

    for (int i = 0; i < 101; i++){
        graph[i][i] = 1;
    }

    for (int i = 1; i < 101; i++){
        for (int j = 1; j < 101; j++){
            for (int k = 1; k < 101; k++){
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]-1);
            }
        }
    }

    while(q--){
        int x, y;
        cin >> x >> y;

        if (graph[x][y] == 1e9) cout << -1;
        else cout << graph[x][y];

        if (q == 0) cout << endl;
        else cout << " ";
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << (graph[i][j] == 1e9 ? 0 : graph[i][j]) << " ";
        }
        cout << endl;
    }
    cout << endl;
    
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
