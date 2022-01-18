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
const int N = 50;
char grid[N][N];
void testcase(){
    int n; cin >> n;
    int rows[n], cols[n];
    for (int i = 0; i < n; i++){
        rows[i] = cols[i] = n;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            char c; cin >> c;
            grid[i][j] = c;
            if (c == 'O') rows[i] = cols[j] = INF;
            else if (c == 'X') {
                if (rows[i] != INF) rows[i]--;
                if (cols[j] != INF) cols[j]--;
            }
        }
    }

    int best = INF;
    for (int i = 0; i < n; i++){
        best = min({best, rows[i], cols[i]});
    }

    int cnt = 0;
    for (int i = 0; i < n; i++){
        cnt += (rows[i] == best) + (cols[i] == best);
    }

    if (best == 1){
        for (int i = 0; i < n; i++){
            if (rows[i] != 1) continue;
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '.'){
                    if (cols[j] == 1) cnt--;
                    break;
                }
            }
        }
    }

    if (best == INF) cout << "Impossible" << endl;
    else cout << best << " " << cnt << endl;
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