#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1e9;
int main() {
  cin.tie(0)->sync_with_stdio(0);

  int r, c; cin >> r >> c;
  vector grid(r, vector(c, '.'));
  vector<int> cnt(26);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == '.') continue;
      cnt[grid[i][j]-'a']++;
    }
  }
  
  vector memo(27, vector(r*c+5, -1));
  vector best_move(27, vector(r*c+5, false));
  function<int(int,int)> check = [&](int i, int b) {
    int &ans = memo[i][b];
    if (ans != -1) return ans;
    if (i == 26) return ans = 0;
    if (b < cnt[i]) {
      best_move[i][b] = 0;
      return ans = check(i+1, b)+cnt[i];
    }
    else {
      int p1 = check(i+1, b)+cnt[i];
      int p2 = check(i+1, b-cnt[i]);

      if (p1 < p2) best_move[i][b] = 0;
      else best_move[i][b] = 1;

      return ans = min(p1, p2); 
    }
  };

  int best = INF;
  int bestr = 0, bestc = 0;
  for (int i = 0; i <= r; i++) {
    for (int j = 0; j <= c && (i+r)*(j+c) <= 2*r*c; j++) {
      // count black and white 
      int nr = r+i;
      int nc = c+j;

      int black_cnt = 0;
      if (nr % 2 == 0 || nc % 2 == 0) black_cnt = nr*nc/2;
      else black_cnt = (nr*nc+1)/2;

      int white_cnt = nr*nc - black_cnt;
      int min_white = check(0, black_cnt);

      if (min_white > white_cnt) continue;
      if (best > nr*nc) {
        best = nr*nc;
        bestr = nr;
        bestc = nc;
      }
    }
  }

  vector<bool> isblack(26);
  int black_cnt = (bestc*bestr+1)/2;
  pair<int,int> state = {0, black_cnt};
  vector<int> whites, blacks;
  while (state.first < 26) {
    auto &[i, b] = state;

    if(best_move[i][b]) {
      blacks.push_back(i);
      state = {i+1, b-cnt[i]};
    }
    else {
      whites.push_back(i);
      state = {i+1, b};
    }
  }

  vector gridans(bestr, vector(bestc, '.'));
  queue<char> qblack, qwhite;
  for (int &i : blacks) {
    for (int j = 0; j < cnt[i]; j++) qblack.push(i+'a');
  }
  for (int &i : whites) {
    for (int j = 0; j < cnt[i]; j++) qwhite.push(i+'a');
  }

  for (int i = 0; i < bestr; i++) {
    for (int j = 0; j < bestc; j++) {
      if ((i+j)%2 == 0 && !qblack.empty()) {
        gridans[i][j] = qblack.front();
        qblack.pop();
      }
      if ((i+j)%2 == 1 && !qwhite.empty()) {
        gridans[i][j] = qwhite.front();
        qwhite.pop();
      }
    }
  }

  cout << bestr << " " << bestc << "\n";
  for (int i = 0; i < bestr; i++) {
    for (int j = 0; j < bestc; j++) {
      cout << gridans[i][j];
    }
    cout << "\n";
  }


  return 0;
}