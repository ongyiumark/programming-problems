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
const int N = 1e5;
vector<pii> adj[N];
int f[N], s[N], t[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k, q; cin >> n >> m >> k >> q;
  for (int i = 0; i < m; i++){
    int a, b, l; cin >> a >> b >> l;
    a--; b--;
    adj[a].push_back({b,l});
    adj[b].push_back({a,l});
  }
  for (int i = 0; i < k; i++){
    cin >> f[i];
    f[i]--;
  }

  for (int i = 0; i < q; i++){
    cin >> s[i] >> t[i];
    s[i]--; t[i]--;
  }
  return 0;
}
