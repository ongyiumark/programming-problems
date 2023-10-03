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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<vector<int>> costs(10, vector<int>(10));
  string s; cin >> s;
  int n = s.size();
  for (int i = 0; i < n-1; i++) {
    costs[s[i]-'0'][s[i+1]-'0'] += 1;
  }

  vector<int> perm(10);
  for (int i = 0; i < 10; i++) perm[i] = i;
  ll ans = 1e18;

  do {
    costs[perm[0]][s[0]-'0']++;
    ll tmp = 0;
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        tmp += costs[perm[i]][perm[j]]*abs(j-i);
      }
    }
  
    ans = min(ans, tmp);
    costs[perm[0]][s[0]-'0']--;
  } while(next_permutation(perm.begin(), perm.end()));
  
  cout << ans+n << "\n";
  return 0;
}
