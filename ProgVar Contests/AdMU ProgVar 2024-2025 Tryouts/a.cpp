#include <bits/stdc++.h>
using namespace std;

const int M = 3000+5;
void read_bingo(vector<vector<int>> &v) {
    v.resize(5);
    for (int i = 0; i < 5; i++) {
        v[i].resize(5);
        for (int j = 0; j < 5; j++) {
            cin >> v[i][j];
        }
    }
}


int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    vector<vector<vector<int>>> cards(n);
    for (int i = 0; i < n; i++) read_bingo(cards[i]);
    vector<vector<int>> rows(n, vector<int>(M, -1));
    for (int c = 0; c < n; c++) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                rows[c][cards[c][i][j]] = i;
            }
        }
    }

    auto check_ties = [&](int i, int j) {
        vector<vector<int>> &a = cards[i];
        vector<vector<int>> &b = cards[j];
        
        for (int ai = 0; ai < 5; ai++) {
            for (int aj = 0; aj < 5; aj++) {
                int m = a[ai][aj];
                if (rows[j][m] == -1) continue;

                int bi = rows[j][m];

                unordered_set<int> vals;
                for (int jj = 0; jj < 5; jj++) {
                    if (a[ai][jj] != m) vals.insert(a[ai][jj]);
                    if (b[bi][jj] != m) vals.insert(b[bi][jj]);
                }

                if (n == 2) return true;

                bool has_filled = 0;
                for (int c = 0; c < n; c++) {
                    if (c == i || c == j) continue;
                    for (int x = 0; x < 5; x++) {
                        bool filled = 1;
                        for (int y = 0; y < 5; y++) {
                            filled &= (vals.find(cards[c][x][y]) != vals.end());
                        }
                        has_filled |= filled;
                    }
                }
                if (!has_filled) return true;
            }
        }
        return false;
    };

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (check_ties(i, j)) {
                cout << i+1 << " " << j+1 << "\n";
                return 0;
            }
        }
    }
    cout << "no ties\n";
    return 0;
}