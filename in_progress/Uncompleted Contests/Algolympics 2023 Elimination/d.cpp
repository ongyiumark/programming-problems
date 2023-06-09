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

struct test {
  string nums[3];
  string op;
  unordered_map<char, int> ch_to_int;
  vector<char> keys;
};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t; cin >> t;
  vector<pair<int, string>> tests;
  for (int i = 0; i < t; i++) {
    ll c; cin >> c;
    string s; cin >> s;

    tests.push_back({c, s});    
  }
  vector<test> parsed(t);
  for (int tt = 0; tt < t; tt++) {
    test curr_test;

    string s = tests[tt].second;
    ll c = tests[tt].first;

    int idx = 0;
    for (char ch : s) {
      if ('A' <= ch && ch <= 'Z') {
        curr_test.nums[idx].append(1, ch);
        if (curr_test.ch_to_int.find(ch) == curr_test.ch_to_int.end()) {
          curr_test.keys.push_back(ch);
          curr_test.ch_to_int[ch] = 0;
        }
      }
      else {
        idx++;
        if (idx == 1) curr_test.op.append(1, ch);
      }
    }

    sort(curr_test.keys.begin(), curr_test.keys.end());

    parsed[tt] = curr_test;
  }


  vector<int> mask(10, 0);
  for (int i = 0; i < 10; i++) mask[i] = i;

  vector<vector<pair<char, int>>> res(t);
  
  vector<bool> found(t);
  do {
    for (int tt = 0; tt < t; tt++) {
      if (found[tt]) continue;
      auto [c, s] = tests[tt];

      test &curr_test = parsed[tt];

      for (int i = 0; i < c; i++) {
        curr_test.ch_to_int[curr_test.keys[i]] = mask[i];
      }

      ll ans[3];
      for (int i = 0; i < 3; i++) {
        string tmp = curr_test.nums[i];

        for (int j = 0; j < (int)(curr_test.nums[i].size()); j++) {
          tmp[j] = (char)('0'+curr_test.ch_to_int[curr_test.nums[i][j]]);
        }
        ans[i] = stoll(tmp);
      }
      if (ans[0] == 0 || ans[1] == 0 || ans[2] == 0) continue;

      bool val = 0;
      if (curr_test.op == "+") val = (ans[0]+ans[1]==ans[2]);
      else if (curr_test.op == "-") val = (ans[0]-ans[1]==ans[2]);
      else if (curr_test.op == "*") {
        if (ans[2] % ans[1] != 0 || ans[2] % ans[0] != 0) val = 0;
        else val = (ans[0]*ans[1]==ans[2]);
      }
      else if (curr_test.op == "/") val = (ans[0]/ans[1]==ans[2]);

      if (val) {
        for (int i = 0; i < c; i++) {
          res[tt].push_back({curr_test.keys[i], curr_test.ch_to_int[curr_test.keys[i]]});
        }
        found[tt] = true;
      }

    }
  } while (next_permutation(mask.begin(), mask.end()));

  for (auto v : res) {
    for (auto [ch, d] : v) {
      cout << ch << " " << d << "\n";
    }
  }
  
  return 0;
}
