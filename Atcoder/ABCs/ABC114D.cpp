/*
  The idea is to prime factorize n!. Then, write all possible product partitions of 75.
  For each product partition, try to fit them into the multiplicities of the factorization of n!.

  My implementation is very ungeneralizable.
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

unordered_map<int,int> fact;
vector<int> mults;
bool vis[100];


int solve(vector<int> &v, int i){
  if (i == v.size()) return 1;
  int ans = 0;
  for (int j = 0; j < mults.size(); j++){
    if (vis[j]) continue;
    if (v[i]-1 <= mults[j]){
      vis[j] = 1;
      ans += solve(v, i+1);
      vis[j] = 0;
    }
  }
  return ans;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for (int i = 2; i <= n; i++){
    int x = i;
    for (int d = 2; d*d <= x; d++){
      while(x%d == 0){
        x/=d;
        fact[d]++;
      }
    }
    if (x > 1) fact[x]++;
  }

  for (auto it : fact){
    mults.push_back(it.second);
  }

  int ans = 0;
  vector<vector<int>> pos = {{75}, {3,25}, {5,15}, {3,5,5}};
  for (vector<int> v : pos){
    memset(vis, 0, sizeof vis);
    int tmp = solve(v, 0);
    if (v.size() == 3) tmp /= 2;
    ans += tmp;
  }
  cout << ans << endl;
  return 0;
}
