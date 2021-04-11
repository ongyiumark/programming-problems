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

const int N = 100;
int x[N], y[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
  int n, m, X, Y;
  cin >> n >> m >> X >> Y;
  int maxX = X;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    maxX = max(maxX, x[i]);
  }

  int minY = Y;
  for (int i = 0; i < m; i++) {
    cin >> y[i];
    minY = min(minY, y[i]);
  }
  bool agree = minY > maxX;

  cout << (agree ? "No War" : "War") << endl;
  return 0;
}
