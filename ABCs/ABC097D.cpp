/*
  Let (x,y) be edges in a graph.
  P[i] can be turned into i if and only if i and j are connected where P[j] = i.
  Alternatively, we can put P[i] into its right place if i and P[i] are connected. 
  
  We can check for connected components with union find.
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
int P[N];
int actual[N];
struct union_find{
  vector<int> p;
  union_find(int n) : p(n+1,-1) {}
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
};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m; cin >> n >> m;
  union_find dsu(n);
  for (int i = 1; i <= n; i++){
    cin >> P[i];
    actual[P[i]] = i;
  }
  for (int i = 0; i < m; i++){
    int x, y; cin >> x >> y;
    dsu.unite(x,y);
  }

  int cnt = 0;
  for (int i = 1; i <= n; i++){
    cnt += dsu.find(actual[i]) == dsu.find(i);
  }
  cout << cnt << endl;
  return 0;
}
