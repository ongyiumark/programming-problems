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

const int N = 101;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, k; cin >> n >> k;
  vector<ii> edges;
  
  vector<vector<bool>> adjmat(n, vector<bool>(n, false));
  // star graph
  for (int i = 1; i < n; i++) adjmat[0][i] = true;

  int cnt = (n-1)*(n-2)/2;
  for (int i = 1; i < n && cnt > k; i++) {
    for (int j = i+1; j < n && cnt > k; j++) {
      adjmat[i][j] = true;
      cnt--;
    }
  }

  if (cnt != k) {
    cout << -1 << "\n";
    return 0;
  }

  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (adjmat[i][j]) edges.emplace_back(i, j);
    }
  } 
  
  cout << edges.size() << "\n";
  for (auto &[a, b] : edges) {
    cout << a+1 << " " << b+1 << "\n";
  }
  return 0;
}
