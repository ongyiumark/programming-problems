#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

char solve(string t) {
  int m = t.size();
  for (int i = 0; i < 26; i++) {
    bool found = 0;
    for (int j = 0; j < m; j++) {
      if (t[j] - 'a' == i) found = 1;
      if (found) break;
    }
    if (!found) return i+'a';
  }
  return 0;
}

void testcase() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  int cnt[26];
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; i++) {
    cnt[s[i]-'a']++;
  }

  int books[k];
  string res[k];
  for (int i = 0; i < k; i++) books[i] = n/k;
  for (int i = 0; i < 26; i++) {
    if (cnt[i] == 0) continue;
    for (int j = 0; j < k; j++) {
      if (books[j] == 0) break;
      if (cnt[i] == 0) break;
      books[j]--;
      res[j].push_back(i+'a');
      cnt[i]--;
    }
  }
  
  string mex;
  for (int i = 0; i < k; i++) {
    mex.push_back(solve(res[i]));
  }
  cout << mex << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--) testcase();
  
  return 0;
}
