#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ll,ll> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5+5;
struct dsu {
  vector<ii> p;
  dsu (int n) { 
    p.resize(2*n);
    for (int i = 0; i < n; i++) p[i] = {-1, 0};
    for (int i = n; i < 2*n; i++) p[i] = {0, -1};
  }

  ii find(int x) {
    if (p[x].first < 0 || p[x].second < 0) return {x, x};
    return p[x] = find(p[x].first);
  }
  
  int size(int x) {
    x = find(x).first;
    return -(p[x].first+p[x].second);
  }

  bool unite(int a, int b) {
    a = find(a).first;
    b = find(b).first;

    if (a == b) return false;
    if (size(a) < size(b)) swap(a, b);

    p[a] = {p[a].first+p[b].first, p[a].second+p[b].second};
    p[b] = {a, a};

    return false;
  }

  ll compute(int x) {
    if (p[x].first > 0) return 0;
    return p[x].first*p[x].second;
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  dsu uf(N);
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    x--; y--;
    uf.unite(x, y+N);
  }

  ll ans = 0;
  for (int i = 0; i < N; i++) {
    ans += uf.compute(i);
  }

  cout << ans - n << "\n";
  return 0;
}
