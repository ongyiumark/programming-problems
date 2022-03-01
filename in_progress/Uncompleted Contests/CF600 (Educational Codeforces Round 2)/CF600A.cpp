/*
  I'm just bad at coding.
  Just do it.
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

vector<string> split(string s){
  vector<string> ans;
  string word = "";
  for (char ch : s) {
    if (ch == ';' || ch == ',') {
      ans.push_back(word);
      word = "";
      continue;
    }
    word.append(1, ch);
  }
  ans.push_back(word);
  return ans;
}

bool is_num(string s){
  if (s.size() == 0) return false;
  for (char ch : s){
    if (ch < '0' || '9' < ch) {
      return false;
    }
  }

  if (s[0] == '0') return ((int)s.size() == 1);
  return true;
} 

string build_string(vector<string>& words){
  string ans = "\"";
  int n = words.size();
  if (n == 0) return "-";
  for (int i = 0; i < n; i++) {
    ans += words[i];
    if (i == n-1) ans += "\"";
    else ans += ",";
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s; cin >> s;
  vector<string> words = split(s);

  vector<string> a, b;
  for (string ss: words) {
    if (is_num(ss)) a.push_back(ss);
    else b.push_back(ss);
  }
  
  string a_out = build_string(a);
  string b_out = build_string(b);
  
  cout << a_out << endl;
  cout << b_out << endl;

  return 0;
}
