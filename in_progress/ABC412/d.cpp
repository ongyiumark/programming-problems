#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<bool>> adjmat(n, vector<bool>(n));

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adjmat[a][b] = adjmat[b][a] = true;
    }

    int best_score = 1e9;
    vector<int> verts(n);
    iota(verts.begin(), verts.end(), 0);

    do {
        int cnt_exists = 0;
        int score = 1e9;
        for (int i = 0; i < n; i++) {
            if (adjmat[verts[i]][verts[(i+1)%n]]) cnt_exists++;
        }
        score = min(score, (n-cnt_exists) + (m-cnt_exists));

        // split into components [0, d), [d, n)
        for (int d = 3; d <= n-3; d++) {
            cnt_exists = 0;
            for (int i = 0; i < d; i++) {
                if (adjmat[verts[i]][verts[(i+1)%d]]) cnt_exists++;
            }
            for (int i = d; i < n; i++) {
                if (adjmat[verts[i]][verts[i+1 < n ? i+1 : d]]) cnt_exists++;
            }
            score = min(score, (n-cnt_exists) + (m-cnt_exists));
        }

        
        best_score = min(best_score, score);
    } while (next_permutation(verts.begin(), verts.end()));

    cout << best_score << "\n";
    return 0;
}