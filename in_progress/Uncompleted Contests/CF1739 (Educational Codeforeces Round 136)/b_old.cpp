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

int d[105];
int n;
ii nxt[105][10005];
int memo[105][10005];

bool solve(int i, int curr) {
  if (curr < 0) return false; 
  int &ans = memo[i][curr];
  if (ans != -1) return ans;
  if (i == n-1) return (ans = (true));

  bool val1 = solve(i+1, curr+d[i+1]);
  bool val2 = solve(i+1, curr-d[i+1]);
  if (val1) nxt[i][curr] = {i+1, curr+d[i+1]};
  else if (val2) nxt[i][curr] = {i+1, curr-d[i+1]};

  if (val1 && val2 && d[i+1] != 0) {
    return (ans = (false));
  }
  return (ans = (val1|val2));
}

void testcase() {
  cin >> n;
  
  for (int i = 0; i < n; i++) cin >> d[i];
  memset(memo, -1, sizeof memo);
  bool ans = solve(0, d[0]);
  if (!ans) {
    cout << -1 << "\n";
    return;
  }
  int a[n];
  ii state = {0, d[0]};
  while (state.first != n-1) {
    a[state.first] = state.second;
    state = nxt[state.first][state.second];
  }
  a[state.first] = state.second;

  for (int i = 0; i < n; i++) {
    cout << a[i];
    if (i < n-1) cout << " ";
    else cout << "\n";
  }

  
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--) testcase();
  return 0;
}
