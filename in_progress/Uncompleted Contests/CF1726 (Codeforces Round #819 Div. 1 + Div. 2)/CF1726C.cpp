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


int n;
string s;
const int N = 2e5+5;
int last[N];
int prv[N], nxt[N];


int solve(int l, int r) {
  if (l >= r) return 0;
  vector<int> ls, rs;
  int i = l;
  while(i <= r) {
    ls.push_back(i);
    rs.push_back(nxt[i]);
    i = nxt[i]+1;
  }

  int ans = 1;
  for (int k = 0; k < ls.size(); k++) {
    ans += solve(ls[k]+1, rs[k]-1);
  }
  return ans;
}

void testcase() {
  cin >> n;
  cin >> s;

  for (int i = 0; i < 2*n+5; i++) {
    last[i] = prv[i] = nxt[i] = -1;
  }
  int curr = 0;
  last[curr] = 0;
  for (int i = 0; i < 2*n; i++) {
    if (s[i] == '(') {
      curr++;
      last[curr] = i;
    }
    else {
      curr--;
      prv[i] = last[curr+1];
      nxt[last[curr+1]] = i;
    }
  }

  cout << solve(0, 2*n-1) << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--) {
    testcase();
  }
  
  return 0;
}
