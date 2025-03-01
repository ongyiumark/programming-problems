/*
  O(n^2) Solution: Just simulate it starting from i for every i.
  
  Suppose your current time is x. Simply look for the smallest k >= 0 that satisfies this inequality.
    x <= s[j] + kf[j]
  That's the time the next station will arrive.
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

const int N = 501;
int c[N], s[N], f[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < n-1; i++){
    cin >> c[i] >> s[i] >> f[i];
  }

  for (int i = 0; i < n; i++){
    int ans = 0;
    int ctime = 0;
    for (int j = i; j < n-1; j++){
      int ntime;
      if (ctime <= s[j]) ntime = s[j]+c[j];
      else ntime = s[j]+(ctime-s[j]+f[j]-1)/f[j]*f[j] + c[j];
      ans += ntime-ctime;
      ctime = ntime;
    }
    cout << ans << endl;
  }
  return 0;
}
