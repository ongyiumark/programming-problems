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
int R[N], C[N];
int prefixR[N], prefixC[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q; cin >> n >> q;
  for (int i = 0; i < n; i++){
    cin >> R[i];
  }
  for (int i = 0; i < n; i++){
    cin >> C[i];
  }

  for (int i = 1; i < n; i++){
    prefixR[i] = (R[i]+R[i-1])%2;
    prefixC[i] = (C[i]+C[i-1])%2;
    if (i != 1){
      prefixR[i] += prefixR[i-1];
      prefixC[i] += prefixC[i-1];
    }
  }

  while(q--){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    a--; b--; c--; d--;
    if (a > c) swap(a, c);
    if (b > d) swap(b, d);

    int cnt = prefixR[c]+prefixC[d];
    if (a > 0) cnt -= prefixR[a];
    if (b > 0) cnt -= prefixC[b];
    //cout << cnt << endl;
    cout << (cnt == 0 ? "YES" : "NO") << endl;
  }


  
  return 0;
}
