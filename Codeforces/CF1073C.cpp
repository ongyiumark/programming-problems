/*
  Binary search the answer. 
  The manhattan distance and the length must have the same parity.
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

string s;
int x, y;
int n;

unordered_map<char, int> dx = {{'U', 0}, {'D', 0}, {'L', -1}, {'R', 1}};
unordered_map<char, int> dy = {{'U', 1}, {'D', -1}, {'L', 0}, {'R', 0}};

bool check(int len){
  int cx = 0;
  int cy = 0;
  for (int i = len; i < n; i++){
    cx += dx[s[i]];
    cy += dy[s[i]];
  }

  int d = abs(cx-x)+abs(cy-y);
  if(d%2 == len%2 && d <= len) return true;
  for (int i = 0; i+len < n; i++){
    cx += dx[s[i]];
    cy += dy[s[i]];

    cx -= dx[s[i+len]];
    cy -= dy[s[i+len]];

    d = abs(cx-x)+abs(cy-y);
    if(d%2 == len%2 && d <= len) return true;
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  cin >> s;
  cin >> x >> y;

  if (abs(x)+abs(y) > n) {
    cout << -1 << endl;
    return 0;
  }

  int lo = 0;
  int hi = n;
  int ans = -1;
  while(lo <= hi){
    int mid = hi - (hi-lo)/2;
    if (check(mid)){
      ans = mid;
      hi = mid-1;
    }
    else lo = mid+1;
  }

  cout << ans << endl;
  
  return 0;
}
