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
void testcase(){
  cin >> s;
  int n = s.size();
  int cnt[n+1][26];
  memset(cnt, 0, sizeof cnt);
  for (int j = 0; j < 26; j++) cnt[n][j] = 0;
  for (int i = n-1; i >= 0; i--) {
    for (int j = 0; j < 26; j++) cnt[i][j] += cnt[i+1][j];
    cnt[i][s[i]-'a']++;
  }

  int idx = 0;
  //cout << cnt[idx][s[idx]-'a'] << endl;
  while(idx < n && cnt[idx+1][s[idx]-'a'] > 0){
    //cout << s[idx] << " " << cnt[idx+1][s[idx]-'a'] << endl;
    idx++;
  }

  cout << s.substr(idx) << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--){
    testcase();
  }
  return 0;
}
