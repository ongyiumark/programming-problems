/*
  This is a bfs-like problem but we need to be efficient.
  Notice that water becomes still row by row. A row is a group of empty cells sandwiched by solid cells.
  A row is still if (1) is full of water, (2) everything below it is either solid or still.

  We simply need to keep track of this these two numbers for each row.
  Be careful of repeating already visited cells. 
  We can do this by keeping a timer on every cell and only updating if the timer is greater than the time to be updated.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1500000;
vector<vector<char>> grid;
vector<vector<int>> row_id;
vector<vector<int>> timer;
struct row{
  int i, lj, rj, water, below, st; 
};
row rw[N+1];

struct cell{
  int i, j, t;
};
queue<cell> q;
int ans;
void print_grid(int r, int c){
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      cout << grid[i][j];
    }
    cout << "\n";
  }
}

void update_row(int id, int time){
  int row_sz = rw[id].rj - rw[id].lj + 1;
  if (rw[id].water == row_sz && rw[id].below == row_sz){
    // this turns the row still
    rw[id].st = 1;
    for (int j = rw[id].lj; j <= rw[id].rj; j++) {
      int row_above = row_id[rw[id].i-1][j];
      if (row_above != -1) {
        rw[row_above].below++;
        int above_sz = rw[row_above].rj - rw[row_above].lj + 1;
        if (rw[row_above].below == above_sz && rw[row_above].water == above_sz) update_row(row_above, time);
      }
      
      char char_above = grid[rw[id].i-1][j];
      if (char_above == '.' && timer[rw[id].i-1][j] > time+1) {
        q.push({rw[id].i-1, j, time+1});
        timer[rw[id].i-1][j] = time+1;
      }
      else if ('0' <= char_above && char_above <= '9') {
        char above_left = grid[rw[id].i-1][j-1];
        char above_right = grid[rw[id].i-1][j+1];
        if (above_left == '.' && timer[rw[id].i-1][j-1] > time+1) {
          q.push({rw[id].i-1, j-1, time+1});
          timer[rw[id].i-1][j-1] = time+1;
        }
        if (above_right == '.' && timer[rw[id].i-1][j+1] > time+1) {
          q.push({rw[id].i-1, j+1, time+1});
          timer[rw[id].i-1][j+1] = time+1;
        }
      }
    }
  }
}

void propagate_helper(int time, int r, int c){
  while(!q.empty() && q.front().t == time){
    cell cc = q.front();
    q.pop();
    
    char cchar = grid[cc.i][cc.j];
    int id = row_id[cc.i][cc.j];
    if (cchar == '.') {
      grid[cc.i][cc.j] = time%10+'0';
      if (id != -1) rw[id].water++;
      //ans = time;
    }
    if (id != -1){
      if (rw[id].st == 1) continue;
      update_row(id, time);
    }

    if (cc.i + 1 < r){
      char char_below = grid[cc.i+1][cc.j];
      // if cell below is empty
      if (char_below == '.' && timer[cc.i+1][cc.j] > time+1) {
        q.push({cc.i+1, cc.j, time+1});
        timer[cc.i+1][cc.j] = time+1;
      }
      else {
        int row_below = row_id[cc.i+1][cc.j];
        // above solid or still water cell
        if (char_below == '#' || (row_below != -1 && rw[row_below].st)){
          if (cc.j-1 >= 0 && grid[cc.i][cc.j-1] == '.' && timer[cc.i][cc.j-1] > time+1) {
            q.push({cc.i, cc.j-1, time+1});
            timer[cc.i][cc.j-1] = time+1;
          }
          if (cc.j+1 < c && grid[cc.i][cc.j+1] == '.' && timer[cc.i][cc.j+1] > time+1) {
            q.push({cc.i, cc.j+1, time+1});
            timer[cc.i][cc.j+1] = time+1;
          }
        }
      }
    }

  }
}

void propagate(int r, int c){
  int time = -1;
  while(!q.empty()){
    time++;
    propagate_helper(time, r, c);
  }
  cout << time << endl;
  print_grid(r,c);
}

void solve(){
  int r, c;
  cin >> r >> c;

  grid.resize(r);
  row_id.resize(r);
  timer.resize(r);
  for (int i = 0; i < r; i++){
    grid[i].resize(c);
    row_id[i].resize(c);
    timer[i].resize(c);
    for (int j = 0; j < c; j++){
      cin >> grid[i][j];
      row_id[i][j] = -1;
      timer[i][j] = 1e9;
    }
  }

  // make sure the queue is empty
  while(!q.empty()){
    q.pop();
  }

  // push initial waters
  for (int j = 0; j < c; j++){
    if (grid[0][j] == 'W') {
      grid[0][j] = '.';
      q.push({0,j,0});
      timer[0][j] = 0;
    }
  }

  // generate rows
  int id = 0;
  for (int i = 1; i < r-1; i++){
    for (int j = 1; j < c-1; j++){
      if (grid[i][j-1] == '#' && grid[i][j] == '.'){
        int k = j;
        rw[id] = {i,k,0,0,0,0};
        while(k < c-1 && grid[i][k] != '#'){
          rw[id].below += (grid[i+1][k] == '#');
          k++;
        }
        if (grid[i][k] == '#') {
          rw[id].rj = k-1;
          for (int x = rw[id].lj; x <= rw[id].rj; x++) row_id[i][x] = id;
          id++;
        }
        j = k;
      }
    }
  }

  propagate(r, c);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
