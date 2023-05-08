#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

string query(ll x, ll y) {
  cout << "? " << x << " " << y << endl;
  string res; cin >> res;
  return res;
}

int main(){
  ll w, h; cin >> w >> h;

  vector<int> p(w);
  iota(p.begin(), p.end(), 1);
  random_shuffle(p.begin(), p.end());

  ll max_h = 0;
  ll max_w = 0;
  bool found = 0;
  for (int &x : p) {
    string res = query(x, max_h+1);
    if (res == "sky") continue;
    
    found = 1;
    ll lo = max_h+1;
    ll hi = h;
    ll ans = max_h+1;
    while(lo <= hi) {
      ll mid = hi - (hi-lo)/2;
      string tmp = query(x, mid);
      if (tmp == "building") {
        ans = mid;
        lo = mid+1;
      }
      else hi = mid-1;
    }
    if (max_h < ans) {
      max_h = ans;
      max_w = x;
    }

    if (max_h == h) break;
  }
  
  if (!found) cout << "! " << 1 << " " << 0 << endl;
  else cout << "! " << max_w << " " << max_h << endl;
  
  return 0;
}
