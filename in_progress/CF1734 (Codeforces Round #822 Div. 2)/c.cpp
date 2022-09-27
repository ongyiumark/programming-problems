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

const int N = 1e6+5;
string s;
vector<bool> a(N), b(N);
void testcase() {
  int n; cin >> n;
  cin >> s;
  for (int i = 1; i <= n; i++) {
    a[i] = (s[i-1]=='1');
    b[i] = 0;
  }

  ll cost = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i]) continue;
    for (int j = 1; j*i <= n; j++) {
      if (a[j*i]) break;
      if (b[j*i]) continue;
      b[j*i] = 1;
      cost += i; 
    }
  }

  cout << cost << "\n";


}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--) testcase();
  return 0;
}
