/*
  Create an 2 edges from i to i+1 with weight 0 and 2^(i-1).
  This way, we can construct any number 19 bit number by creating edges to node 20.
  However, 19 bits isn't enough, so we can actually make use of node 19 multiple times.
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

struct edges{
  ll u, v, w;
};

vector<edges> graph;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll l; cin >> l;

  for (int i = 1; i <= 18; i++){
    graph.push_back({i,i+1, 0});
    graph.push_back({i,i+1, 1LL<<(i-1)});
  }

  for (int i = 18; i >= 0; i--){
    while (l >= (1<<i)){
      graph.push_back({i+1, 20, l-(1LL<<i)});
      l -= (1LL<<i);
    }
  }

  cout << 20 << " " << graph.size() << endl;
  for (auto e : graph){
    cout << e.u << " " << e.v << " " << e.w << endl;
  }

  return 0;
}
