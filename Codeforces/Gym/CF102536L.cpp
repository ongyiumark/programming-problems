/*
  Let a,b,c,d... be the distinct roots. 
  Simply multiply (x-a)(x-b)(x-c)(x-d)... 
  Don't forget to remove duplicates to minimize the degree.

  To multiply these, just multiply two vectors with foil.
  My initial idea was to do combinations but that's O(2^n). 
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

const int MOD = 999983;
vector<ll> roots, ans;

void solve(){
  int d = roots.size();
  
  vector<ll> tmp(d+1);
  ans[0] = 1;
  for (int i = 0; i < d; i++){
    tmp[0] = 0;
    for (int j = 1; j < d+1; j++){
      tmp[j] = ans[j-1];
    }
    for (int j = 0; j < d+1; j++){
      tmp[j] += ans[j]*roots[i];
      tmp[j] %= MOD;
    }
    for (int j = 0; j < d+1; j++){
      ans[j] = tmp[j];
    }
  }

  reverse(ans.begin(), ans.end());
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--){
    int n, k, l; cin >> n >> k >> l;
    set<int> tmp;
    roots.clear();
    for (int i = 0; i < l; i++){
      int x; cin >> x;
      if (tmp.insert(x).second) roots.push_back(-x);
    }
    if (roots.size() > k) {
      cout << 0 << endl;
      continue;
    }
    int d = roots.size();
    ans.clear();
    ans.resize(d+1);
    solve();
    cout << n << endl;
    for (int i = 1; i <= n; i++){
      cout << k;
      for (int j = 0; j < k+1; j++){
        cout << " " << (j < d+1 ? ans[j] : 0)*i%MOD;
      }
      cout << endl;
    }
  }
  return 0;
}
