#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  bool A[n][n];
  bool B[m][m];

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      char c; cin >> c;
      A[i][j] = (c == '#');
    }
  }

  for (int i = 0; i < m; i++){
    for (int j = 0; j < m; j++){
      char c; cin >> c;
      B[i][j] = (c == '#');
    }
  }

  for (int i = 0; i < n-m+1; i++){
    for (int j = 0; j < n-m+1; j++){
      bool valid = true;
      for (int k = 0; k < m; k++){
        for (int l = 0; l < m; l++){
          valid &= (A[i+k][j+l] == B[k][l]);
        }
      }
      if (valid){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
