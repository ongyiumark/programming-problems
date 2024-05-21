/*
  Use 2 DSUs; one for roads and one for rails.
  The group representative is a tuple (parent_of_roads, parent_of_rails).
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

const int N = 2e5+1;

struct DSU{
  vector<int> p;
  DSU(int n) : p(n, -1) {}

  int find(int x){
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
  }

  bool unite(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (p[a] > p[b]) swap(a,b);
    p[a] += p[b];
    p[b] = a;
    return true;
  }

  int size(int x) {
    return -p[find(x)];
  }
};

DSU roads_dsu = DSU(N);
DSU rails_dsu = DSU(N);
map<pair<int,int>, int> ans;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, k, l;
  cin >> n >> k >> l;
  for (int i = 0; i < k; i++){
    int p, q; cin >> p >> q;
    roads_dsu.unite(p, q);
  }

  for (int i = 0; i < l; i++){
    int r, s; cin >> r >> s;
    rails_dsu.unite(r,s);
  }

  for (int i = 1; i <= n; i++){
    int a = roads_dsu.find(i);
    int b = rails_dsu.find(i);
    ans[{a,b}]++;
  }

  for (int i = 1; i <= n; i++){
    int a = roads_dsu.find(i);
    int b = rails_dsu.find(i);
    cout << ans[{a,b}];
    if (i == n) cout << endl;
    else cout << " ";
  }
  return 0;
}
