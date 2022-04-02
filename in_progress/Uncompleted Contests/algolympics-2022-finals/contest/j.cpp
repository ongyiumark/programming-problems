#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update>;
 
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int n;
bool grid[4][4];
int gridid;
int c[5];
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
// n, grid num, c
int grids[5][1<<16][5];

bool valid(int x, int y) {
    return 0 <= x && x < n
        && 0 <= y && y < n;
}

void helper(int i, int j){
    if (j >= n) {
        i += 1;
        j = 0;
    }
    if (i >= n){
        /*
        for (int x = 0; x < n; x++){
            for (int y = 0; y < n; y++){
                cout << grid[x][y];
            }
            cout << endl;
        }
        cout << endl;
        */
        
        int tmp[5];
        for (int k = 0; k < 5; k++) tmp[k] = 0;
        for (int x = 0; x < n; x++){
            for (int y = 0; y < n; y++){
                if (!grid[x][y]) {
                    continue;
                }
                int tcnt = 0;
                for (int k = 0; k < 4; ++k) {
                    int nxtx = x+dr[k], nxty = y+dc[k];
                    if (!valid(nxtx, nxty)) continue;
                    tcnt += grid[nxtx][nxty];
                }
                tmp[tcnt]++;
            }
        }
        //cout << n << " " << gridid << ": ";
        for (int k = 0; k < 5; k++){
            grids[n][gridid][k] = tmp[k];
            //cout << grids[n][gridid][k] << " ";
        }
        //cout << endl;
        gridid++;
        return;
    }
    
    helper(i, j+1);
    grid[i][j] = 1;
    helper(i, j+1);
    grid[i][j] = 0;
}

void preprocess(int i){
    n = i;
    gridid = 0;
    memset(grid, 0, sizeof grid);
    helper(0,0);
}

void testcase(){
    cin >> n;
    
    memset(grid, 0, sizeof grid);
    for (int i = 0; i < 5; i++) cin >> c[i];
    int cnt = 0;
    //cout << endl;
    for (int i = 0; i < (1<<(n*n)); i++) {
        bool valid = 1;
        //cout << n << " " << i << ": "; 
        for (int k = 0; k < 5; k++){

            valid &= (grids[n][i][k] == c[k]);
            //cout << grids[n][i][k] << " ";
        }
        //cout << endl;
        cnt += valid;
    }
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    memset(grids,0,sizeof grids);
    for (int i = 1; i <= 4; i++) preprocess(i);
    int T; cin >> T;
    while(T--){
        testcase();
    }
    return 0;
}
