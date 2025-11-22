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

struct state {
  int len, link;
  map<char, int> next;
  state() : len(0), link(-1) {}
};

struct SuffixAutomaton {
  vector<state> st;
  int last;
  SuffixAutomaton(string &s) : last(0), st({state()}) {
    for (char c : s) extend(c);
  }

  void extend(char c) {
    int cur = st.size(), p = last;
    st.push_back(state());
    st[cur].len = st[last].len+1;
    while (p != -1 && !st[p].next.count(c)) {
      st[p].next[c] = cur;
      p = st[p].link;
    }

    last = cur;
    if (p == -1) {
      st[cur].link = 0; return;
    }

    int q = st[p].next[c];
    if (st[p].len+1 == st[q].len) {
      st[cur].link = q; return;
    }

    int clone = st.size();
    st.push_back(st[q]);
    st[clone].len = st[p].len+1;
    while (p != -1 && st[p].next[c] == q) {
      st[p].next[c] = clone;
      p = st[p].link;
    }
    st[cur].link = st[q].link = clone;
  }
};


int main(){
  cin.tie(0)->sync_with_stdio(false);

  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    SuffixAutomaton sa(s);
    vector<int> memo(s.size()*2, -1);
    function<int(int)> dfs = [&](int u) -> int {
      if (memo[u] != -1) return memo[u];
      int &win = memo[u];
      win = 1;
      for (pair<char,int> nxt : sa.st[u].next) {
        int res = dfs(nxt.second);
        if(res) win = 0;
      }
      return win;
    };
    int bob_wins = dfs(0);

    cout << (bob_wins == 1 ? "Bob\n" : "Alice\n");
  }


  return 0;
}
