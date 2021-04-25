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

const int N = 1e5;
int A[N];
int diff[N];
int par[N];
void testcase(){
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];
  for (int i = 1; i < n; i++){
    diff[i] = A[i]-A[i-1];
  }
  int cnt = 1;
  int l = 1;
  int ans = 0;
  vector<pair<int,int>> cnts;
  par[1] = 1;
  for (int i = 2; i < n; i++){
    if (diff[i] != diff[i-1]){
      cnts.push_back({l, cnt});
      ans = max(ans, cnt+1);
      l = i;
      cnt = 1;
    }
    else cnt++;
    par[i] = l;
  }
  cnts.push_back({l, cnt});
  ans = max(ans, cnt+1);
  int m = cnts.size();
  for (int i = 0; i < m; i++){
    par[cnts[i].first] = -cnt;
  }

  if (cnts[0].second == 1 && m > 1){
    ans = max(ans, cnts[1].second+2);
  }
  if (cnts[m-1].second == 1 && m > 1){
    ans = max(ans, cnts[m-2].second+2);
  }

  for (int i = 2; i < n; i++){
    if ((diff[i]+diff[i-1])%2 == 1) continue;
    if (diff[i] == diff[i-1]) continue;
    int ndiff = (diff[i]+diff[i-1])/2;
    int tans = 3;
    if (i+1 < n && ndiff == diff[i+1]){
      tans += -par[i+1];
    }
    if (i-2 > 0 && ndiff == diff[i-2]){
      tans += -par[i-2]-1;
    }

    ans = max(ans, tans);
  }
  /*
  for (int i = 1; i < n; i++){
    cout << diff[i] << " ";
  }
  cout << endl;
  */
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  for (int x = 1; x <= t; x++){
    cout << "Case #" << x << ": ";
    testcase();
  }
  return 0;
}
