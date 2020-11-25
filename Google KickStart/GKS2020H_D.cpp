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

ll graph[26][26];

void testcase(){
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < 26; j++){
            graph[i][j] = 1e9;
        }
    }

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++){
        cin >> S[i];
    }

    for (int i = 1; i <= n; i++){
        string s = S[i];
        for (int j = 0; j < (int)s.size(); j++){
            for (int k = 0; k < (int)s.size(); k++){
                graph[s[j]-'A'][s[k]-'A'] = graph[s[k]-'A'][s[j]-'A'] = 1;
            }
        }
    }

    for (int i = 0; i < 26; i++){
        graph[i][i] = 0;
    }

    // Order of the for-loop in floyd-warshall matters.
    for (int k = 0; k < 26; k++){
        for (int i = 0; i < 26; i++){
            for (int j = 0; j < 26; j++){
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }

    while(q--){
        int x, y;
        cin >> x >> y;

        string s = S[x];
        string t = S[y];

        ll ans = 1e9;
        for (char c1 : s){
            for (char c2 : t){
                ans = min(ans, graph[c1-'A'][c2-'A']);
            }
        }

        cout << (ans == 1e9 ? -1 : ans+2);

        if (q == 0) cout << endl;
        else cout << " ";
    }  
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
