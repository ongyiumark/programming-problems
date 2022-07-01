/*
  Do union find on roads and rails separately.
  Identify each node by their parents in both roads and rails.
  Two nodes are connected if they have the same paired parents.
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

const int N = 2e5+5;
struct dsu {
  vector<int> p;
  dsu(int n) : p(n, -1) {}
  int find (int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
  }

  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;

    if (p[a] > p[b]) swap(a, b);
    p[a] += p[b];
    p[b] = a;

    return true;
  }

  bool is_connected(int a, int b) {
    a = find(a); b = find(b);
    return a==b;
  }
} road_dsu(N), rail_dsu(N);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, k, l;
  cin >> n >> k >> l;
  for (int i = 0; i < k; i++) {
    int p, q; cin >> p >> q;
    p--; q--;
    road_dsu.unite(p, q);
  }

  for (int i = 0; i < l; i++) {
    int r, s; cin >> r >> s;
    r--; s--;
    rail_dsu.unite(r,s);
  }

  map<pii, int> cnt;
  for (int i = 0; i < n; i++) {
    int x = road_dsu.find(i);
    int y = rail_dsu.find(i);
    cnt[{x,y}]++;
  }

  for (int i = 0; i < n; i++) {
    int x = road_dsu.find(i);
    int y = rail_dsu.find(i);
    cout << cnt[{x,y}];
    if (i == n-1) cout << endl;
    else cout << " ";
  }

  
  return 0;
}
