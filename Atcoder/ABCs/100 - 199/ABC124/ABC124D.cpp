/*
  It only makes sense to flip consecutive zeroes.
  So, it's optimal to flip k consecutive groups of consecutive zeros.

  We can count the resulting number of ones by getting the starting point of the first consecutive zero
    and the ending point of the last consecutive zero (also keeping in mind the 1's in before and after).
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

const int N = 1e5+5;
int n, k;
string s;
vector<pair<int,int>> zeros;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k >> s;

  int l, r;
  l = r = -1;
  for (int i = 0; i < n; i++){
    if (s[i] == '0') {
      if (l == -1) l = i;
      r = i;
    }
    if (s[i] == '1' && l != -1) {
      zeros.push_back({l,r});
      l = r = -1;
    }
  }
  if (l != -1) zeros.push_back({l,r});
  if (zeros.size() <= k){
    cout << n << endl;
    return 0;
  }

  int ans = 0;
  int m = zeros.size();
  for (int i = 0; i+k-1 < m; i++){
    int r = (i+k < m ? zeros[i+k].first : n); 
    int l = (i-1 >= 0 ? zeros[i-1].second+1 : 0);
    ans = max(ans, r-l);
  }
  cout << ans << endl;
  return 0;
}
