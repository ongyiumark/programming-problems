/*
  Compress the string by collapsing adjacent letters that are the same. Keep track of how many are in that segment.
  Look for JOI sequence and check if it's compatible.
    It's compatible if min(J, O, I) = O.
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

string s;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s;
  vector<pair<char,int>> arr;
  int n = s.size();
  int cnt = 1;
  for (int i = 1; i < n; i++){
    if (s[i] != s[i-1]){
      arr.push_back({s[i-1], cnt});
      cnt = 1;
    }
    else cnt++;
  }
  arr.push_back({s[n-1], cnt});

  string t = "JOI";
  int ans = 0;
  for (int i = 0; i+2 < (int)arr.size(); i++){
    bool found = 1;
    for (int j = 0; j < 3; j++){
      if (t[j] != arr[i+j].first) found = 0;
    }
    if (found && arr[i+1].second == min({arr[i].second, arr[i+1].second, arr[i+2].second})) 
      ans = max(ans, arr[i+1].second);
  }
  cout << ans << endl;
  return 0;
}
