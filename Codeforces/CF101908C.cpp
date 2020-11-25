#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll x, y; cin >> x >> y;
  ll h, v; cin >> h >> v;

  vector<pair<int,int>> horiz(h), vert(v);

  for (int i = 0; i < h; i++){
    int y1, y2; cin >> y1 >> y2;
    horiz[i] = {y1,y2};
  }

  for (int i = 0; i < v; i++){
    int x1, x2; cin >> x1 >> x2;
    vert[i] = {x1,x2};
  }

  sort(horiz.begin(), horiz.end());
  sort(vert.begin(), vert.end());

  ll ans = 0;
  ordered_set<int> hendings;
  hendings.insert(horiz[0].second);
  for (int i = 1; i < h; i++){
    ans += hendings.order_of_key(horiz[i].second);
    hendings.insert(horiz[i].second);
  }

  ordered_set<int> vendings;
  vendings.insert(vert[0].second);
  for (int i = 1; i < v; i++){
    ans += vendings.order_of_key(vert[i].second);
    vendings.insert(vert[i].second);
  }
  
  cout << ans + (h+1)*(v+1) << endl;

  return 0;
}
