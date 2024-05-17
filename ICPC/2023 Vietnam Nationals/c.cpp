#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<array<int,9>> grid(9);
    for (auto& r : grid) {
        for (int& i : r) {
            char c; cin >> c;
            i = c-'0';
        }
    }

    auto check_vert = [&](int r, int c) {
        int cur = grid[r][c];
        for (int i = 0; i < 9; ++i) {
            if (i == r) continue;
            if (grid[i][c] == cur)  return false;
        }
        return true;
    };
    auto check_hori = [&](int r, int c) {
        int cur = grid[r][c];
        for (int j = 0; j < 9; ++j) {
            if (j == c) continue;
            if (grid[r][j] == cur) return false;
        }
        return true;
    };
    auto check_square = [&](int r, int c) {
        int cur = grid[r][c];
        int sr = (r/3) * 3, sc = (c/3) * 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int nr = sr+i, nc = sc+j;
                if (nr == r and nc == c) continue;
                if (grid[nr][nc] == cur) return false;
            }
        }
        return true;
    };
    const pair<int,int> knight_moves[] = {
        {-2, 1}, {-1, 2}, {1, 2}, {2, 1},
        {2, -1}, {1, -2}, {-1, -2}, {-2, -1}
    };
    const pair<int,int> king_moves[] = {
        {-1, 0}, {-1, 1}, {0, 1}, {1, 1},
        {1, 0}, {1, -1}, {0, -1}, {-1, -1}
    };
    auto check_knight = [&](int r, int c) {
        int cur = grid[r][c];
        for (auto [dr, dc] : knight_moves) {
            int nr = r+dr, nc = c+dc;
            if (nr < 0 or nr >= 9 or nc < 0 or nc >= 9) continue;
            if (grid[nr][nc] == cur) return false;
        }
        return true;
    };
    auto check_king = [&](int r, int c) {
        int cur = grid[r][c];
        for (auto [dr, dc] : king_moves) {
            int nr = r+dr, nc = c+dc;
            if (nr < 0 or nr >= 9 or nc < 0 or nc >= 9) continue;
            if (grid[nr][nc] == cur) return false;
        }
        return true;
    };
    auto check = [&](int r, int c) {
        return check_vert(r, c)
            and check_hori(r, c)
            and check_square(r, c)
            and check_knight(r, c)
            and check_king(r, c);
    };

    auto get_nxt = [](int r, int c) {
        ++c;
        if (c >= 9) ++r, c = 0;
        return pair<int,int>{r, c};
    };

    function<bool(int,int)> solve = [&](int r, int c) {
        if (r >= 9) {
            return true;
        }
        auto [nxtr, nxtc] = get_nxt(r, c);
        if (grid[r][c] != 0) {
            return check(r, c) and solve(nxtr, nxtc);
        }
        for (int i = 1; i <= 9; ++i) {
            grid[r][c] = i;
            if (check(r, c) and solve(nxtr, nxtc)) return true;
        }
        grid[r][c] = 0;
        return false;
    };

    // for (auto& row : grid) {
    //     for (int i : row) cout << i << ' ';
    //     cout << endl;
    // }

    bool good = true;
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            if (grid[r][c] == 0) continue;
            if (not check(r, c)) {
                good = false;
                goto hell;
            }
        }
    }
    hell:

    

    if (good and solve(0, 0)) {
        for (auto& row : grid) {
            for (int i : row) cout << i;
            cout << endl;
        }
    } else {
        cout << "NO SOLUTION\n";
    }

    return 0;
}
