/*
  The trick is to inductively build a (1,2^k) continuous city.
  It turns out, you can build (1,2^k) continuous city with k+2 blocks.

  To build this, create an edge (i,j, 2^(i-2)) for every 2 <= i < j <= k+2.
    Additionally, create an edge (1,j 1) for every 2 <= j <= k+2.

  Notice that we can convert any (L, R) segment to a (1, R') segment by adding an edge of weight L-1 to the last block.
  From now on, assume that we want to build (1, R).

  If we write (R-1) in binary, we can attach the block that corresponds to that bit to the last block.
  By carfully adding the weights, we can create a (2, R) continuous city.
  Finally add (1,n,1).
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

struct edge{
  int a, b, c;
};
vector<edge> ans;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // build 2^19 
  for (int i = 1; i <= 21; i++){
    for (int j = i+1; j <= 21; j++){
      if (i == 1) ans.push_back({i,j, 1});
      else ans.push_back({i, j, (1<<(i-2))});
    }
  }
  int L, R; cin >> L >> R;
  bool one = L == 1;
  if (!one) ans.push_back({22,23, L-1});
  R -= L;
  
  for (int d = 19; d >= 0; d--){
    if ((1<<d)&R){
      ans.push_back({d+2,22+one, R+1-(1<<d)});
      R -= (1<<d);
    }
  }
  ans.push_back({1, 22+one,1});

  cout << "YES" << endl;  
  cout << 23 << " " << ans.size() << endl;
  for (edge &e : ans){
    cout << e.a << " " << e.b << " " << e.c << endl;
  }
  return 0;
}
