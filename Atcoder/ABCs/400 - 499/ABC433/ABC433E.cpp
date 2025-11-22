#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void testcase() {
  int n, m; cin >> n >> m;
  vector<int> x(n), y(m);
  for (int &xx : x) cin >> xx;
  for (int &yy : y) cin >> yy;

  set<tuple<int,int,int,int>> s;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      s.insert({min(x[i],y[j]), max(x[i], y[j]), i, j});
    }
  }
  // a[i][j] <= min(x[i], y[j])

  // if x_i = y_j = v, then a_ij = v
  // if only x_i = v, then choose j st. y_j > v and a_ij = v
  // if only y_j = v, then choose i st. x_i > v and a_ij = v
  // if v not in x and not in y, choose i, j st. x_i > v and y_j > v and a_ij = v
  vector<vector<int>> a(n, vector<int>(m, 0));
  bool possible = true;
  for (int v = n*m; v >= 1; v--) {
    set<tuple<int,int,int,int>>::iterator it = s.lower_bound({v, -1, -1, -1});

    if (it == s.end()) {
      possible = false;
      break;
    }

    int i = get<2>(*it);
    int j = get<3>(*it);
    a[i][j] = v;

    s.erase(it);
  }

  // verify
  for (int i = 0; i < n; i++) {
    int max_row = 0;
    for (int j = 0; j < m; j++) {
      max_row = max(max_row, a[i][j]); 
    }
    if (max_row != x[i]) possible = false;
  }

  for (int j = 0; j < m; j++) {
    int max_col = 0;
    for (int i = 0; i < n; i++) {
      max_col = max(max_col, a[i][j]);
    }
    if (max_col != y[j]) possible = false;
  }

  if (possible) {
    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << a[i][j] << " \n"[j+1>=m];
      }
    }
  }
  else {
    cout << "No\n";
  }
}

int main(){
  cin.tie(0)->sync_with_stdio(false);

  int t; cin >> t;
  while (t--) {
    testcase();
  }
  
  return 0;
}
