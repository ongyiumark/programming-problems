/*
  dp[i] = max(1+dp[prv[i]-1], dp[i-1])
    whether to include the ith element as a segment boundary or not

  My implementation to trace the segments themselves is kinda wack.
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

const int N = 3e5+5;
int a[N];
int dp[N];
int prv[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  map<int,int> track;
  // Point to previous occurence of a[i].
  for (int i = 0; i < n; i++) {
    if (track.find(a[i]) == track.end()) prv[i] = -1;
    else prv[i] = track[a[i]];
    track[a[i]] = i;
  }
  memset(dp, -1, sizeof dp);

  dp[0] = 0;
  vector<int> ans;
  ans.push_back(0);
  for (int i = 1; i < n; i++) {
    int inc = 0;
    // Include ith element.
    if (prv[i] != -1) {
      inc = 1;
      if (prv[i] > 0) inc += dp[prv[i]-1];
    } 
    // Exclude ith element.
    int exc = dp[i-1];
    dp[i] = max(inc, exc);

    // If include, push new start and end.
    if (inc > exc && inc > 0) {
      ans.pop_back();
      ans.push_back(prv[i]-1);
      ans.push_back(i); 
    }
    // If exclude, extend end.
    else {
      ans.pop_back();
      ans.push_back(i);
    }
  }

  if (dp[n-1] == 0) {
    cout << -1 << endl;
    return 0;
  }
  ans[0] = -1;
  cout << (int)ans.size()-1 << endl;
  for (int i = 0; i+1 < ans.size(); i++) {
    cout << ans[i]+2 << " " << ans[i+1]+1 << endl;
  }
  return 0;
}
