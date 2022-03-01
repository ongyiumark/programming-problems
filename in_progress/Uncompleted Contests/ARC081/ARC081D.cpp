/*
  Go from left to right, the answer is multiplied depending on the direction of the tiles.
  If the current tile is vertical, 
    1. If the previous tile is vertical, multiply by 2
    2. If the previous tile is horizontal, multiply by 1
  If the current tile is horizontal,
    1. If the previous tile is vertical, multiply by 2
    2. If the previous tile is horizontal, multiply by 3
  
  Exception: First tiles, 3 if vertical, 6 if horizontal.
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

const int M = 1e9+7;
string s1, s2;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  cin >> s1 >> s2;

  ll ans = 1;

  // 0 - vertical
  // 1 - horizontal
  bool states[n+1];
  memset(states, 0, sizeof states);
  for (int i = 0; i < n; i++) {
    if (s1[i] == s2[i]) {
      if(i == 0) ans = ans*3;
      else if (!states[i-1]) ans = ans*2;
      
      ans %= M;
    }
    else {
      if (i == 0) ans = ans*6;
      else if (!states[i-1]) ans = ans*2;
      else ans = ans*3;

      ans %= M;
      states[i] = states[i+1] = 1;
      i++;
    }
  }

  cout << ans << endl;
  return 0;
}
