/*
  Count the number of names that begin with each letter.
  Try all combinations of 3 from "MARCH".

  You can get all combinations of three with some recursion.
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

const string whole = "MARCH";
vector<string> starts;
void get_comb(int i, string curr){
  if (i >= 5){
    if (curr.size() == 3){
      starts.push_back(curr);
    }
    return;
  }
  get_comb(i+1, curr);
  get_comb(i+1, curr+whole[i]);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll cnt[26];
  memset(cnt, 0, sizeof cnt);
  int n; cin >> n;
  for (int i = 0; i < n; i++){
    string s; cin >> s;
    cnt[s[0]-'A']++;
  }

  get_comb(0, "");
  ll ans = 0;
  for (string s : starts){
    ans += cnt[s[0]-'A']*cnt[s[1]-'A']*cnt[s[2]-'A'];
  }
  cout << ans << endl;
  return 0;
}
