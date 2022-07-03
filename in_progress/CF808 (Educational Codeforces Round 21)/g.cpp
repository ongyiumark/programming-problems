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

const int N = 2e5+5;
int p[N];
int Z[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s, t; cin >> s >> t;
  string st = t+"#"+s;
  int n = st.size();
  int L = 0, R = 0, z[0];
  for (int i = 0; i < n; i++) {
    if (i <= R) z[i] = min(R-i+1, z[i-L]);
    while (i+z[i] < n && st[z[i]] == st[i+z[i]]) z[i]++;
    if (i+z[i]-1 > R) L = i, R = i+z[i]-1;
  }
  
  return 0;
}
