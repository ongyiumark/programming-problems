#include <bits/stdc++.h>
using namespace std;
 
using ii = pair<int, int>;
using iiii = tuple<int, int, int, int>;
using vi = vector<int>;
 
const int INF = 2e9;
const int MAXN = 1e3+2;
 
int n, q;
string g[MAXN];
 
// dist[letter][i][j]
// dist to nearest store with letter
int dist[5][MAXN][MAXN];
 
const string letters = "MBTSP";
unordered_map<char, int> toidx = {
    {'M', 0}, {'B', 1}, {'T', 2}, {'S', 3}, {'P', 4},
};
 
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
bool valid(int r, int c) {
    return 0 <= r && r < n
        && 0 <= c && c < n;
}
 
void preprocess() {
    memset(dist, -1, sizeof(dist));
    queue<iiii> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            const int& idx = toidx[g[i][j]];
            if (g[i][j] != '.') {
                q.push({i, j, idx, 0});
            }
        }
    }
 
    while (!q.empty()) {
        auto [row, col, c, d] = q.front();
        q.pop();
        for (int x = 0; x < 4; ++x) {
            int nxtr = row+dr[x], nxtc = col+dc[x];
            if (!valid(nxtr, nxtc) || dist[c][nxtr][nxtc] != -1) {
                continue;
            }
            dist[c][nxtr][nxtc] = d+1;
            q.push({nxtr, nxtc, c, d+1});
        }
    }
 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j] != '.') {
                for (char c: letters) {
                    dist[toidx[c]][i][j] = INF;
                }
            }
        }
    }
}
 
// get all possible queries
vector<string> possibles;
void preprocess2(int idx, string& cur) {
    if (idx >= 5) {
        possibles.push_back(cur);
        sort(possibles.back().begin(), possibles.back().end());
        return;
    }
    //exclude
    preprocess2(idx+1, cur);
    //include
    cur.push_back(letters[idx]);
    preprocess2(idx+1, cur);
    cur.pop_back();
}
 
unordered_map<string, int> ans;
 
void preprocess3() {
    for (string& s: possibles) {
        ans[s] = INF;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j] != '.') {
                    continue;
                }
                int cur = 0;
                for (char c: s) {
                    cur += dist[toidx[c]][i][j];
                }
                ans[s] = min(ans[s], cur);
            }
        }
    }
}
 
void print_grid(char c) {
    int idx = toidx[c];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[idx][i][j] == INF) {
                cout << ". ";
            } else {
                cout << dist[idx][i][j] << ' ';
            }
        }
        cout << '\n';
    }
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
 
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
    }
 
    preprocess();
    string pp;
    preprocess2(0, pp);
    preprocess3();
    // for (char c: letters) {
    //     cout << c << '\n';
    //     print_grid(c);
    //     cout << '\n';
    // }
    string s;
    for (int i = 0; i < q; ++i) {
        cin >> s;
        sort(s.begin(), s.end());
        cout << ans[s] << '\n';
    }
 
    return 0;
}
