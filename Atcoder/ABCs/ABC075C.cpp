/*
  The constraints are small, so you can try to exclude one of the edges for each edge.
  You can tell if it's a bridge with union find.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 50;
int a[N], b[N];

struct union_find{
  vector<int> p;
  union_find(int n) : p(n, -1) {}
  int find(int x){
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
  }
  bool unite(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (a > b) swap(a,b);
    p[a] += p[b];
    p[b] = a;
    return true;
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++){
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }

  int ans = 0;
  for (int i = 0; i < m; i++){
    union_find arr = union_find(n);
    for (int j = 0; j < m; j++){
      if (i == j) continue;
      arr.unite(a[j], b[j]);
    }
    ans += arr.unite(a[i], b[i]);
  }
  cout << ans << endl;
  return 0;
}
