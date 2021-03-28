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

const int MOD = 1e9+7;
const int N = 2e5+1;

string n;
int k;
ll dp[N][16][2];
map<char, int> conv;
ll solve(int i, int d, int s){
  ll &ret = dp[i][d][s];
  if (ret != -1) return ret;
  ret = 0;

  if (s == 0) {
    ret = (ret + solve(i-1, d, 0)*d)%MOD;
    ret = (ret + solve(i-1, d-1, 0)*(16-d+1))%MOD;
  }
  else {
  }

}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  memset(dp, -1, sizeof dp);
  string t = "0123456789ABCDEF";
  for (int i = 0; i < 16; i++){
    conv[t[i]] = i;
  }

  int sz = n.size();
  cout << solve(sz,k,0) + solve(sz,k,1) << endl;
  return 0;
}
