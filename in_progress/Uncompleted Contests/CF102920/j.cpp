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

const int N = 505;
bitset<2*N> mat[N]; 

void printdebug(int n){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 2*n; j++){
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  int tmp[n][n];
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> tmp[i][j];
    }
  }

  for (int j = 0; j < n; j++){
    mat[j].reset();
    for (int i = 0; i < n; i++){
      if (tmp[i][j]) mat[j].set(i);
    }
    mat[j].set(n+j);
  }

  for (int i = 0; i < n; i++){
    // look for pivot point on the i-th column
    int idx = -1;
    for (int j = i; j < n; j++){
      if (mat[j]._Find_first() == i){
        idx = j;
        break;
      }
    }
    if (idx == -1) break;
    if (i != idx) swap(mat[i], mat[idx]);

    // remove all ones in that column
    for (int j = 0; j < n; j++){
      if (j == i) continue;
      if (mat[j][i]) mat[j] = mat[j]^mat[i];
    }
  }

  //check if valid
  bool valid = 1;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (i == j && mat[i][j] == 0) valid = 0;
      if (i != j && mat[i][j] == 1) valid = 0; 
    }
  }
  

  if (valid){
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        if (mat[j][n+i]) cout << j+1 << " ";
      }
      cout << endl;
    }
  }
  else cout << -1 << endl;
  
}
