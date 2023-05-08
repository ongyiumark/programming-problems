#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    vector<string> C(h);
    for (string &s : C) cin >> s;

    int n = min(h, w);
    vector<int> res(n+1);

    vector<int> di = {1, 1, -1, -1};
    vector<int> dj = {-1, 1, -1, 1};

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int d = 0; d <= n; d++) {
                bool all_hash = true;
                for (int k = 0; k < 4; k++) {
                    int x = i+di[k]*d;
                    int y = j+dj[k]*d;

                    char ch;
                    if (x < 0 || x >= h || y < 0 || y >= w) ch = '.';
                    else ch = C[x][y];

                    if (ch == '.') all_hash = false;
                }
                if (!all_hash) {
                    if (d > 0) res[d-1]++;
                    break;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i];
        if (i == n) cout << "\n";
        else cout << " ";
    }
    return 0;
}