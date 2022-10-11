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

const int N = 5e5+5;
ll s[2*N];
ii t[2*N];

struct node {
  int par;
  ll total;
  int l, r;

  node() : par(-1), total(0), l(0), r(0) {};
};

struct dsu {
  vector<node> p;
  dsu(int n) : p(2*n) {
    for (int i = 0; i < 2*n; i++) {
      p[i].total = s[i];
      //cout << p[i].total << " ";
      p[i].l = p[i].r = i;
    }
    //cout << endl;
  };
  int find(int x) {
    if (p[x].par < 0) return x;
    return p[x].par = find(p[x].par);
  }
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a==b) return false;
    if (p[a].par > p[b].par) swap(a,b);
    p[a].par += p[b].par;
    p[b].par = a;
    p[a].total += p[b].total;
    p[a].l = min(p[a].l, p[b].l);
    p[a].r = max(p[a].r, p[b].r);

    return true;
  }
};

bool opt(ll x, int n) {
  dsu uf(n);
  for (int i = 0; i < 2*n; i++) {
    int idx = t[i].second;
    if (s[idx] > x) break;
    if (uf.p[idx].par == -1) uf.p[idx].total += x;
    else continue;

    while(true) {
      idx = uf.find(idx);
      int l = uf.p[idx].l;
      int r = uf.p[idx].r;

      bool val = 0;
      if (l > 0 && s[l-1] <= uf.p[idx].total) {
        int b = uf.find(l-1);
        if (uf.p[b].par < -1) uf.p[idx].total -= x;
        val |= uf.unite(idx,b);
      }
      if (r < 2*n-1 && s[r+1] <= uf.p[idx].total) {
        int b = uf.find(r+1);
        if (uf.p[b].par < -1) uf.p[idx].total -= x;
        val |= uf.unite(idx,b);
      }
      if (!val) break;
    }
    idx = uf.find(idx);
    //cout << idx << " " << uf.p[idx].total << " " << -uf.p[idx].par << endl;
  }
  
  int hi = 0;
  for (int i = 0; i < 2*n; i++) {
    hi = max(-uf.p[i].par, hi);
  }
  return hi >= n;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> s[i]; 
  for (int i = n; i < 2*n; i++) s[i] = s[i-n];
  for (int i = 0; i < 2*n; i++) {
    t[i] = {s[i], i};
  }
  sort(t, t+2*n);

  //cout << opt(11 , n) << endl;
  //cout << opt(4, n) << endl;
  
  
  ll lo = 0;
  ll hi = 1e14;
  ll ans = 0;
  while(lo <= hi) {
    ll mid = hi - (hi-lo)/2;
    if (opt(mid, n)) {
      hi = mid-1;
      ans = mid;
    }
    else lo = mid+1;
  }
  cout << ans << endl;
  
  

  
  return 0;
}
