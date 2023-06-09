#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int INF = 1e9;
const ll INFLL = 4e18;

vector<string> pat = {
    "A...B...C",
    ".A.B....C",
    "..A.....C",
    ".B.A....C",
    "B...A...C",
    "B....A.C.",
    "B.....C..",
    "B....C.A."
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    string t; cin >> t;
    string s; cin >> s;

    int sz = pat.size();

    bool flip = (t == "right-over-middle");
    if (flip) swap(s[0], s[2]);

    char grid[4*n+1][9];
    for (int i = 0; i < 4*n+1; i++) {
        for (int j = 0; j < 9; j++) {
            if (i%sz == 0 && j == 0 && i > 0) swap(s[0], s[1]), swap(s[1], s[2]);
    
            if (pat[i%sz][j] == '.') grid[i][j] = '.';
            else grid[i][j] = s[pat[i%sz][j]-'A'];
        }
    }

    for (int i = 0; i < 4*n+1; i++) {
        for (int j = 0; j < 9; j++) {
            cout << (flip ? grid[i][8-j] : grid[i][j]);
        }
        cout << "\n";
    }

    return 0;
}