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
vector<int> u(N), s(N);

struct segtree {
  vector<int> p;
  int n;
  segtree(vector<int> &arr) {
    n = arr.size();
    p.resize(2*n);
    for (int i = 0; i < 2*n; i++) p[i] = 0;
    //for (int i = 0; i < n; i++) update(i, arr[i]);
  }

  void update(int k, int x){
    k += n;
    p[k] += x;
    for (k /= 2; k >= 1; k /= 2){
      p[k] = p[2*k]+p[2*k+1];
    }
  }

  int range(int a, int b){
    a += n;
    b += n;
    int res = 0;
    while(a <= b){
      if (a%2 == 1) res = res+p[a++];
      if (b%2 == 0) res = res+p[b--];
      a /= 2; b /= 2;
    }
    return res;
  }
};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> u[i];
  for (int i = 0; i < m; i++) cin >> s[i];
  
  segtree sg(u);
  int prev = sg.range(0, n-1);
  for (int i = 0; i < m; i++){
    sg.update(0,s[i]);
    if (i+1 < n) sg.update(i+1,-s[i]);
    int curr = sg.range(0, i);
    cout << curr << endl;
  }

  return 0;
}
