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

void testcase() {
  int n; cin >> n;
  queue<char> ballots[n];
  bool is[26];
  memset(is, 0, sizeof is);
  
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    for (char ch : s) {
      ballots[i].push(ch);
      is[ch-'A'] = 1;
    }
  }
  bool elim[26];
  memset(elim, 0, sizeof elim);

  vector<string> ans;
  while(true){
    int cnt[26];
    memset(cnt, 0, sizeof cnt);
    int total = 0;
    for (int i = 0; i < n; i++) {
      while(!ballots[i].empty() && elim[ballots[i].front()-'A']){
        ballots[i].pop();
      }
      if (ballots[i].empty()) continue;
      //cout << ballots[i].front() << endl;
      cnt[ballots[i].front()-'A']++;
      total++;
    }

    bool valid = 0;
    for (int i = 0; i < n; i++) {
      valid |= !ballots[i].empty();
    }
    if (!valid) {
      ans.push_back("no winner");
      break;
    }

    int hi = 0;
    int lo = n+1;

    for (int i = 0; i < 26; i++) {
      if (!is[i]) continue;
      if (elim[i]) continue;
      hi = max(hi, cnt[i]);
      lo = min(lo, cnt[i]);
    }

    //cout << hi << " " << n << endl;
    if (2*hi > total) {
      string tmp = "";
      for (int i = 0; i < 26; i++) {
        if (!is[i]) continue;
        if (elim[i]) continue;
        if (cnt[i] == hi) tmp.append(1, 'A'+i);
      }
      ans.push_back(tmp);
      break;
    }
    else {
      string tmp = "";
      for (int i = 0; i < 26; i++) {
        if (!is[i]) continue;
        if (elim[i]) continue;
        if (cnt[i] == lo) tmp.append(1, 'A'+i);
      }
      ans.push_back(tmp);
      for (char ch : tmp) {
        elim[ch-'A'] = 1;
      }
    }
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i+1 == ans.size()) cout << endl;
    else cout << " -> ";
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while (t--) {
    testcase();
  }
  return 0;
}
