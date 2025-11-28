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

int main(){
  cin.tie(0)->sync_with_stdio(false);

  int n, m; cin >> n >> m;
  vector<string> S(n);
  for (string &s: S) cin >> s;


  set<string> patterns;
  for (int i = 0; i < n-m+1; i++) { //i+m-1 < n-m+1
    for (int j = 0; j < n-m+1; j++) {
      string current_pattern = "";
      for (int di = 0; di < m; di++) {
        for (int dj = 0; dj < m; dj++) {
          int x = i+di;
          int y = j+dj;
          current_pattern.append(1, S[x][y]);
        }
      }
      patterns.insert(current_pattern);
    }
  }

  cout << patterns.size() << endl;  
  return 0;
}
