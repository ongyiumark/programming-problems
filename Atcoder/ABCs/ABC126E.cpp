/*
  Count the number of disjoint sets.
  The Z values don't matter.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5+1;

struct DSU{
  int par[N];

  void init(){
    memset(par, -1, sizeof par);
  }

  int find(int i){
    if (par[i] < 0) return i;
    return par[i] = find(par[i]);
  }

  void unite(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (par[a] < par[b]){
      par[a] += par[b];
      par[b] = a;
    }
    else {
      par[b] += par[a];
      par[a] = b;
    }
  }

  int count(int n){
    int ans = 0;
    for (int i = 1; i <= n; i++){
      ans += par[i] < 0;
    }
    return ans;
  }
} dsu;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;
  dsu.init();

  for (int i = 0; i < m; i++){
    int x, y, z;
    cin >> x >> y >> z;
    dsu.unite(x,y);
  }

  cout << dsu.count(n) << endl;

  return 0;
}
