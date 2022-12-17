/* 
    Look at the second to the last row.
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const ld EPS = 1e-9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    char grid[5][4*n];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4*n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int j = 0; j < 4*n; j += 4) {
        if (grid[3][j] == '*') cout << 2;
        else if (grid[3][j+1] == '*') cout << 1;
        else if (grid[3][j+2] == '*') cout << 3;
    }
    cout << "\n";
    
    return 0;
}