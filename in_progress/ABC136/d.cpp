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

struct res {
  ll a, b;
  res() : a(0), b(0) {}
  res(ll a, ll b) : a(a), b(b) {}

  res operator+(const res& other) const {
    return res(a+other.a, b+other.b);
  }

  res flip() {
    return res(b, a);
  }
};

void dfs(int u, int p, vector<vector<int>> &adj, vector<res> &ans) {
  ans[u] = res(1, 0);
  for (int &v : adj[u]) {
    if (v == p) continue;
    dfs(v, u, adj, ans);
    ans[u] = ans[u] + ans[v].flip();
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s; cin >> s;
  int n = s.size();
  vector<vector<int>> adj(n);
  int idx = n;

  for (int i = 0; i < n; i++) {
    if (s[i] == 'R') adj[i+1].push_back(i);
    if (s[i] == 'L') adj[i-1].push_back(i);
  }

  vector<res> ans(n);

  vector<int> result(n);
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R' and s[i+1] == 'L') {
      dfs(i, -1, adj, ans);
      result[i] = ans[i].a;

      dfs(i+1, -1, adj, ans);
      result[i+1] = ans[i+1].a;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << result[i];

    if (i < n-1) cout << " ";
    else cout << "\n";
  }

  return 0;
}
