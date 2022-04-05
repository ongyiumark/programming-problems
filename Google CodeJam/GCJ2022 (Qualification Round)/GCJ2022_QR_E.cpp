/*
  Importance sampling is insane.
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

pii room(){
  int r, p; cin >> r;
  if (r == -1) return {-1,-1};
  cin >> p;
  return {r,p};
}

int rand(int a, int b) {
  return rand() % (b-a+1) + a;
}

void teleport(int n){
  cout << "T" << " " << rand(1,n) << endl; 
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--){
    int n, k; cin >> n >> k;
    double ans = 0;
    auto [r,p] = room();
    if (r == -1) return 0;
    ans += p; 
    int prevp = p;

    int cnt = 0;
    double total = 0;
    while (true) {
      if (cnt == k) break;

      if (cnt%2 == 1) {
        teleport(n);
        auto [r,p] = room();
        if (r == -1) return 0;
        prevp = p;
        ans += p;
        total += 1;
      }
      else {
        cout << "W" << endl;
        auto [r,p] = room();
        if (r == -1) return 0;
        ans += prevp;
        total += prevp/p;
      }
      cnt++;
    }
    ans = ans/total*n/2;
    ll res = (ll)ans;
    cout << "E" << " " << res << endl; 
  }
  return 0;
}
