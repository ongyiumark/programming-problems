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

const int MAXN = 1e6+5;
vector<int> z(MAXN);
void z_algo(const string &s) {
  int n = s.length();
  z.assign(n, 0);
  for (int i = 1, L = 0, R = 0; i < n; i++) {
    if (i <= R) z[i] = min(R-i+1, z[i-L]);
    while (i+z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;
    if (i+z[i]-1 > R) L=i, R=i+z[i]-1;
  }
  z[0] = n;
}

int main(){
  cin.tie(0)->sync_with_stdio(false);
  
  int t; cin >> t;
  while(t--) {
    string A, B; cin >> A >> B;
    string BAA = B+A+A;
    z_algo(BAA);
    int a_sz = A.length();
    int b_sz = B.length();
    int ans = -1;
    for (int i = 0; i < a_sz; i++) {
      if (z[b_sz+i] >= b_sz) {
        ans = i;
        break;
      }
    }
    cout << ans << "\n";
  }
  
  return 0;
}
