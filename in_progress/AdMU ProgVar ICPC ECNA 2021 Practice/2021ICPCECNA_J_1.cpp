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
const ll INF = 1e18;
int l[N], r[N], ar[N];

struct dsu {
  vector<int> p, l, r;
  vector<ll> minar;
  dsu(int n) : p(n,-1), minar(n, INF), l(n), r(n) {
    for (int i = 0; i < n; i++) {
      minar[i] = ar[i];
      l[i] = i;
      r[i] = i;
    }
  }
  int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
  }

  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (p[a] > p[b]) swap(a,b);
    p[a] += p[b];
    minar[a] = min(minar[a], minar[b]);
    l[a] = min(l[a], l[b]);
    r[a] = max(r[a], r[b]);
    p[b] = a;
    return true;
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  vector<pii> sorted;
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
    l[i] = i;
    r[i] = i;
    sorted.push_back({ar[i], i});
  }

  sort(sorted.begin(), sorted.end(), greater<pii>());
  dsu uf(n);

  ll best = 0;
  int lans = 0;
  int rans = 0;
  for (int i = 0; i < n; i++) {
    int val = sorted[i].first;
    int idx = sorted[i].second;

    int par = uf.find(idx);
    if (uf.l[par]-1 >= 0 && val <= ar[uf.l[par]-1]) uf.unite(uf.l[par]-1, par);
    if (uf.r[par]+1 < n && val <= ar[uf.r[par]+1]) uf.unite(uf.r[par]+1, par);

    par = uf.find(idx);

    if (best < -uf.p[par]*uf.minar[par]) {
      best = -uf.p[par]*uf.minar[par];
      lans = uf.l[par];
      rans = uf.r[par];
    }
    else if (best == -uf.p[par]*uf.minar[par]){
      if (lans > uf.l[par]) {
        best = -uf.p[par]*uf.minar[par];
        lans = uf.l[par];
        rans = uf.r[par];
      }
    }

  }
  cout << lans+1 << " " << rans+1 << " " << best << endl;
  
  return 0;
}
