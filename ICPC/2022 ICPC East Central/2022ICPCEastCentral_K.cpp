#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void process(string &s, vector<vector<int>> &adj) {
  stack<int> st;

  string curr_str;
  for (char ch : s) {
    if (ch == ' ') continue;
    if (ch == '(' || ch == ')') {
      if (!curr_str.empty()) {
        st.push(stoi(curr_str));
        curr_str = "";
      }
    }
    if (ch == ')') {
      int v = st.top();
      st.pop();
      int u = st.top();
      adj[u].push_back(v);
    }

    if (ch != '(' && ch != ')') curr_str.push_back(ch);
  }
  if (!curr_str.empty()) {
    adj[stoi(curr_str)].push_back(-1);
  }
}

const int N = 1e6+5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  
  vector adj1(N, vector<int>());
  vector adj2(N, vector<int>());
  process(s1, adj1);   
  process(s2, adj2);
  
  for (int i = 0; i < N; i++) {
    sort(adj1[i].begin(), adj1[i].end());
    sort(adj2[i].begin(), adj2[i].end());
  }

  bool same = true;
  for (int i = 0; i < N; i++) {
    same &= (adj1[i] == adj2[i]);
  }
  cout << (same ? "Yes" : "No") << "\n";

  return 0;
}