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

const int INF = 1e9;
void testcase(){
    string s; cin >> s;
    int k; cin >> k;
    int grid[26][26];
    
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < 26; j++){
            if (i == j) grid[i][j] = 0;
            else grid[i][j] = INF;
        }
    }

    for (int i = 0; i < k; i++){
        char a, b; cin >> a >> b;
        grid[a-'A'][b-'A'] = 1;
    }

    // floyd warshall
    for (int k = 0; k < 26; k++){
        for (int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                if (grid[i][j] > grid[i][k]+grid[k][j] && grid[i][k] != INF && grid[k][j] != INF){
                    grid[i][j] = grid[i][k]+grid[k][j];
                }
            }
        }
    }
    /*
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < 26; j++){
            cout << (grid[i][j] == INF ? 0 : grid[i][j]) << " ";
        }
        cout << endl;
    }
    cout << endl;
    */

    int n = s.size();
    int best = INF;
    for (int i = 0; i < 26; i++){
        int curr = 0;
        for (int j = 0; j < n; j++){
            int idx = s[j]-'A';
            if (grid[idx][i] == INF){
                curr = INF;
                break;
            } 
            curr += grid[idx][i];
        }
        best = min(best, curr);
    }

    cout << (best == INF ? -1 : best) << endl;
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