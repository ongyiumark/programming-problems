/*
  Just simulate both paths.
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

const int N = 101;
int square[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, x; cin >> n >> m >> x;
  memset(square, 0, sizeof square);
  for (int i = 0; i < m; i++){
    int a; cin >> a;
    square[a]++;
  }

  for (int i = x-1; i >= 0; i--){
    square[i] += square[i+1];
  }
  for (int i = x+1; i <= n; i++){
    square[i] += square[i-1];
  }

  cout << min(square[0], square[n]) << endl;
  return 0;
}
