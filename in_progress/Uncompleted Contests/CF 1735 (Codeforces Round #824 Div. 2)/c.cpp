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

struct dsu {
  vector<int> p;
  dsu(int n) : p(n, -1) {}
  int find(int x) {
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
  }

  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a==b) return 0;
    if (p[a] > p[b]) swap(a,b);
    p[a] += p[b];
    p[b] = a;
    return 1;
  }

  bool check(int a, int b) {
    a = find(a);
    b = find(b);
    return a == b;
  }
};

int par[26];
bool vis[27];

void testcase() {
  int n; cin >> n;
  string t; cin >> t;
  memset(par, -1, sizeof par);
  memset(vis, 0, sizeof vis);
  string s = t;

  //cout << s << endl;
  int lo = 0;
  dsu uf(27);
  for (int i = 0; i < n; i++) {
    if (par[t[i]-'a'] != -1) {
      s[i] = par[t[i]-'a']+'a';
      continue;
    }

    int nlo = lo;
    while(uf.check(t[i]-'a', nlo)) {
      nlo++;
    }

    if (nlo == 26) {
      int tmp = 0;
      while(vis[tmp]) tmp++;
      nlo = tmp;
    }

    par[t[i]-'a'] = nlo;
      
    s[i] = par[t[i]-'a']+'a';
    vis[nlo] = 1;
    uf.unite(t[i]-'a', nlo);
    while(vis[lo]) lo++;
  }
  cout << s << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--) testcase();
  return 0;
}
