#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define all(x) (x).begin(), (x).end()

// #define int long long
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using viii = vector<iii>;

const int INF = is_same<int, long long>() ? 1e18 : 1e9;
const int MOD = 1e9+7;
const int MAXN = 102;

int rows, cols;
string g[MAXN];
int sum[MAXN][MAXN];

void make_sum() {
    for (int i = 0; i < rows; ++i)
        fill(sum[i], sum[i]+cols+1, 0);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j]; 
            if (g[i][j] == '#') ++sum[i+1][j+1];
        }
    }
}

int check(int r, int c, int s) {
    int outer = sum[r+s][c+s] - sum[r+s][c] - sum[r][c+s] + sum[r][c];
    int inner = sum[r+s-1][c+s-1] - sum[r+s-1][c+1] - sum[r+1][c+s-1] + sum[r+1][c+1];
    return outer == inner ? outer : -1;
}

void make_output(int r, int c, int s) {
    for (int i = 0; i < s; ++i) {
        g[r+i][c] = 'B';
        g[r][c+i] = 'B';
        g[r+s-1][c+i] = 'B';
        g[r+i][c+s-1] = 'B';
    }
}

void solve() {
    make_sum();
    int ans = 0, r = -1, c = -1, s = -1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (int k = 2; k <= 100; ++k) {
                if (i+k > rows) continue;
                if (j+k > cols) continue;
                int cur = check(i, j, k);
                if (ans < cur) {
                    ans = cur;
                    r = i;
                    c = j;
                    s = k;
                }
            }
        }
    }

    if (ans == 0) {
        cout << "NO\n";
    } else {
        cout << ans << '\n';
        make_output(r, c, s);
    }
    for (int i = 0; i < rows; ++i) {
        cout << g[i] << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;
    while (T--) {
        cin >> rows >> cols;
        for (int i = 0; i < rows; ++i)
            cin >> g[i];
        solve();
    }

    return 0;
}