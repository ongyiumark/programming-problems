/*
  Count the frequency of each letter.
  We just need to make them all as even as possible.
  We make the result lexicographically least by changing the "biggest" letter into the "smallest" letter.
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
  
  int cnt[26];
  memset(cnt, 0, sizeof cnt);

  cin >> s;
  int n = s.size();

  for (char ch : s) {
    cnt[ch-'a']++;
  }

  deque<char> odds;
  for (int i = 0; i < 26; i++) {
    if (cnt[i]&1) odds.push_back(i+'a');
  }

  while(!odds.empty()) {
    if(n%2 == 1 && odds.size() == 1) break;

    char r = odds.back();
    char l = odds.front();
    odds.pop_back();
    odds.pop_front();
    cnt[r-'a']--;
    cnt[l-'a']++;
  }

  string ans = "";
  for (int i = 0; i < 26; i++){
    ans.append(cnt[i]/2,i+'a');
  }
  for (int i = 0; i < 26; i++){
    if (cnt[i]%2 == 1) ans.append(1, i+'a');
  }
  for (int i = 25; i >= 0; i--){
    ans.append(cnt[i]/2,i+'a');
  }
  cout << ans << endl;
  return 0;
}
