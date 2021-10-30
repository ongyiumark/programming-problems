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
pii moves[N];
set<pii> movesset;
set<pii> amoves, bmoves;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  int ax, ay; cin >> ax >> ay;
  int bx, by; cin >> bx >> by;

  for (int i = 0; i < n; i++){
    int x,y; cin >> x >> y;
    moves[i] = {x,y};
    movesset.insert({x,y});
  }

  for (int i = 0; i < n; i++){
    int cax = ax + moves[i].first;
    int cay = ay + moves[i].second;
    if (cax <= 0 || cax > n || cay <= 0 || cay > n) continue;
    amoves.insert({cax, cay});
  }

  for (pii p : amoves){
    int x = bx-p.first; 
    int y = by-p.second;
    if (movesset.find({x,y}) != movesset.end()){
      cout << "Alice wins" << endl;
      return 0;
    }
  }

  for (int i = 0; i < n; i++){
    int cbx = bx + moves[i].first;
    int cby = by + moves[i].second;
    if (cbx <= 0 || cbx > n || cby <= 0 || cby > n) continue;
    bmoves.insert({cbx, cby});
  }

  for (pii p : bmoves){
    
  }

  cout << "Bob wins" << endl;
  return 0;
}
