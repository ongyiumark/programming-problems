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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--) {
    int v; cin >> v;
    pii votes[1001];
    memset(votes, 0, sizeof votes);
    for (int i = 0; i < 1001; i++) {
      votes[i] = {0,-i};
    }
    for (int i = 0; i < v; i++) {
      int x; cin >> x;
      votes[x].first++;
    }
    sort(votes+1, votes+1001, greater<pii>());
    cout << -votes[1].second << endl;
  }
  return 0;
}
