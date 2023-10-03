/*
  Brute force.
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

int X[10][10];
int d;

int d2(int i, int j){
  int res = 0;
  for (int k = 0; k < d; k++) {
    res += (X[i][k]-X[j][k])*(X[i][k]-X[j][k]);
  }
  return res;
}

bool isSq(int x){
  for (int k = 1; k*k <= x; k++){
    if (k*k == x) return true;
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n >> d;
  for (int i = 0; i < n; i++){
    for (int k = 0; k < d; k++){
      cin >> X[i][k];
    }
  }

  int cnt = 0;
  for (int i = 0; i < n; i++){
    for (int j = i+1; j < n; j++){
      if (isSq(d2(i, j))) cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
