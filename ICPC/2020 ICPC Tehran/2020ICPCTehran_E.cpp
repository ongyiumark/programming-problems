#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int di[] = {1,-1,0,0,1,1,-1,-1};
int dj[] = {0,0,1,-1,1,-1,1,-1};
const int INF = 1e9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<string> grid(n);
    queue<pair<int,int>> q;
    vector<vector<int>> d(n, vector<int>(m, INF));

    int cnt = 0;
    int si, sj, ti, tj;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '*') {
                q.push({i, j});
                d[i][j] = 0;
                cnt++;
            }
            else if (grid[i][j] == 'S') {
                si = i; sj = j;
            }
            else if (grid[i][j] == 'E') {
                ti = i; tj = j;
            }
        }
    }

    while(!q.empty()) {
        auto [ci, cj] = q.front();
        q.pop();

        for (int k = 0; k < 8; k++) {
            int x = ci+di[k];
            int y = cj+dj[k];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (d[x][y] < INF) continue;

            d[x][y] = d[ci][cj]+1;
            q.push({x,y});
        }
    }    


    int ans = INF;
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    vis[si][sj] = 1;
    priority_queue<tuple<int,int,int>> pq;
    pq.push({d[si][sj], si, sj});
    bool found = false;
    while(!pq.empty()) {
        auto [w, ci, cj] = pq.top();
        pq.pop();
        ans = min(ans, d[ci][cj]);
        if (ci == ti && cj == tj) {
            found = true;
            break;
        }

        for (int k = 0; k < 4; k++) {
            int x = ci+di[k];
            int y = cj+dj[k];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (vis[x][y]) continue;
            if (grid[x][y] == '#' || grid[x][y] == '*') continue;

            vis[x][y] = true;
            pq.push({d[x][y], x,y});
        }
    }

    if (!found) cout << -1 << endl;
    else if (cnt == 0) cout << "safe\n";
    else cout << ans << "\n";

    return 0;
}