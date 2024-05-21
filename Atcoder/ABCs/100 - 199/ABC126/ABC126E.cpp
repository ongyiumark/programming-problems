/*
  For every i, form an edge between X[i] and Y[i]. 
  The answer is the number of disjoint sets.
    This is because if we know one of X[i] or Y[i], then we can conclude the other one.
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

const int N = 1e5+5;
int X[N], Y[N], Z[N];

struct union_find{
  vector<int> ar;
  union_find(int n) {
    ar = vector<int>(n,-1);
  }

  int find(int x){
    if (ar[x] < 0) return x;
    return ar[x] = find(ar[x]);
  }

  bool unite(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (ar[a] < ar[b]) swap(a,b);
    ar[b] += ar[a];
    ar[a] = b;
    return true;
  }
} dsu(N);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> X[i] >> Y[i] >> Z[i];
    dsu.unite(X[i], Y[i]);
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++){
    cnt += dsu.ar[i] < 0;
  }
  cout << cnt << endl;
  return 0;
}
