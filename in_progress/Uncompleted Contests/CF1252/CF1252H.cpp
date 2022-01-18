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
pair<ll,ll> rect[N];
ll prefix[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    ll l, w; cin >> l >> w;
    if (l < w) swap(l,w);
    rect[i] = {l,w};
  }
  sort(rect, rect+n, greater<pair<ll,ll>>());
  for (int i = 0; i < n; i++){
    prefix[i] = rect[i].second;
    if (i != 0) prefix[i] = max(prefix[i], prefix[i-1]);
  }

  ll best_area = 0;
  ll best = 0;

  for (int i = 0; i < n; i++){
    best_area = max(best_area, rect[i].first*rect[i].second);
    if (i != 0){
      best = max(best, rect[i].first*min(prefix[i-1],rect[i].second));
      //cout << rect[i].first << " " << rect[i].second << " " << prefix[i-1] << endl;
    }
  }

  if (best*2 >= best_area){
    cout << best << ".0" << endl;
  }
  else {
    cout << best_area/2;
    if (best_area%2 == 1) cout << ".5";
    else cout << ".0";
    cout << endl;
  }
  
  return 0;
}
