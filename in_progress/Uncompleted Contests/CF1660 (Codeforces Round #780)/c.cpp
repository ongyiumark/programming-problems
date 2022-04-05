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

string s;
int n;
const int N = 2e5+5;
int dp[N];
int nxt[N];

int solve(int i){
  if (i >= n) return 0;
  int &ans = dp[i];
  if (ans != -1) return ans;
  ans = 1e9;
  if (nxt[i] == n) ans = min(ans, n-i+1);
  else ans = min(ans, solve(nxt[i]+1)+nxt[i]-i-1);

  ans = min(ans, solve(i+1)+1);
  //cout << i << " " << ans << endl;
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--){
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) dp[i] = -1;
    int pos[26];
    for (int i = 0; i < 26; i++) pos[i] = n;
    for (int i = n-1; i >= 0; i--){
      nxt[i] = pos[s[i]-'a'];
      pos[s[i]-'a'] = i;
    }
    //for (int i = 0; i < n; i++){
    //  cout << nxt[i] << " ";
    //}
    //cout << endl;
    cout << solve(0) << endl;
  }
  return 0;
}
