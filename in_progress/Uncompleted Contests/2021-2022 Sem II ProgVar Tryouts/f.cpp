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

int n, m;
int grid[30][30];

bool valid(int a, int b, int c, int d) {
  return false;
}

bool validup(int a, int b, int c, int d) {
  bool valid = 1;
  for (int i = 0; i <= a-c; i++) {
    if (!grid[a+i][b+i]) return false;
  }
  
}

bool validhor(int a, int b, int c, int d) {
  assert(a == c);
  bool valid = 1;
  for (int i = 0; i <= a; i++) {
    if (a+a-i+1 >= n) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 0) valid = 0;
        if (!valid) return false;
      }
      continue;
    }
    for (int j = 0; j < m; j++){ 
      if (grid[i][j] == grid[a+a-i+1][j]) valid = 0;
      if (!valid) return false;
    }
  }
  return true;
}

bool validvert(int a, int b, int c, int d) {
  assert(b == d);
  bool valid = 1;
  for (int j = 0; j <= b; j++) {
    if (b+b-j+1 >= m) {
      for (int i = 0; i < n; i++) {
        if (grid[i][j] == 0) valid = 0;
        if (!valid) return false;
      }
      continue;
    }
    for (int i = 0; i < n; i++){ 
      if (grid[i][j] == grid[i][b+b-j+1]) valid = 0;
      if (!valid) return false;
    }
  }
  return true;
}

void testcase() {
  cin >> n >> m;
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char ch; cin >> ch;
      grid[i][j] = (ch == '#');
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // horizontal
      if (j == 0 && validhor(i,j,i,m-1)) {
        cout << i+1 << " " << j+1 << " " << i+1 << " " << m << endl;
        return;
      }

      // vertical
      if (i == 0 && validvert(i,j,n-1,j)) {
        cout << i+1 << " " << j+1 << " " << n << " " << j+1 << endl;
        return;
      }

      // diag up
      int r = i; int c = j;
      while(r > 0 && c > 0) r--,c--;
      if (valid(i,j,r,c)) {
        cout << i+1 << " " << j+1 << " " << r+1 << " " << c+1 << endl;
        return;
      }

      // diag down
      r = i; c = j;
      while(r < n-1 && c < m-1) r++,c++;
      if (valid(i,j,r,c)) {
        cout << i+1 << " " << j+1 << " " << r+1 << " " << c+1 << endl;
        return;
      }

    }
  }
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while (t--) {
    testcase();
  }

  return 0;
}
