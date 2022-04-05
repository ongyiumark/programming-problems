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

bool valid (string t) {
  int one, two, ans;
  char op;
  int n = t.size();
  
  int idx = 0;
  string tmp = "";
  if (t[idx] == '-') tmp.append(1, t[idx++]);
  while(idx < n && '0' <= t[idx] && t[idx] <= '9') tmp.append(1, t[idx++]);
  //cout << tmp << endl;
  if (tmp[0] == '0' && tmp.size() > 1) return false;
  if (tmp[0] == '-' && tmp[1] == '0') return false;
  one = stoi(tmp);
  tmp = "";

  op = t[idx++];

  if (t[idx] == '-') tmp.append(1, t[idx++]);
  while(idx < n && '0' <= t[idx] && t[idx] <= '9') tmp.append(1, t[idx++]);
  //cout << tmp << endl;
  if (tmp[0] == '0' && tmp.size() > 1) return false;
  if (tmp[0] == '-' && tmp[1] == '0') return false;
  two = stoi(tmp);

  idx++;
  tmp = t.substr(idx);
  if (tmp[0] == '0' && tmp.size() > 1) return false;
  if (tmp[0] == '-' && tmp[1] == '0') return false;
  //cout << tmp << endl;
  ans = stoi(tmp);

  if (op == '+') return one + two == ans;
  else if (op == '-') return one - two == ans;
  else return one*two == ans;
}

void testcase() {
  string s; cin >> s;
  vector<bool> vis(10,0);

  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      vis[s[i]-'0'] = 1;
    }
  }

  for (int i = 0; i < 10; i++) {
    if (vis[i]) continue;
    string t = "";
    for (int j = 0; j < n; j++) {
      if (s[j] == '?') t.append(1, '0'+i);
      else t.append(1,s[j]);
    }
    //cout << "test: " << t << endl;
    if (valid(t)) {
      cout << i << endl;
      return;
    }
  }
  cout << -1 << endl;
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
