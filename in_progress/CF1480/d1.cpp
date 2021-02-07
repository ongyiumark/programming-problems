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

const int N  = 1e5;
int a[N];
int sig[N];
bool poisoned[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  int curr = -1;
  int cnt = 0;
  memset(sig, 0, sizeof sig);
  memset(poisoned, 0, sizeof poisoned);
  for (int i = 0; i < n; i++){
    if (curr != a[i]) cnt = 1;
    else cnt++;
    
    if (cnt <= 2) sig[i] = 1;
    if (cnt == 2) sig[i] = sig[i-1] = 2;
    curr = a[i];
  }
  
  int ans = 0;
  int i = 0;
  while(i < n){
    if (sig[i] == 0) {
      i++;
      continue;
    }
    if (i >= 2 && sig[i] == 2 && a[i] == a[i-2] && (poisoned[i-2] || sig[i-2] == 2)){
      i += sig[i];
      ans++;
      continue;
    }
    if (i >= 2 && (poisoned[i-2] || sig[i-2]==2) && a[i] == a[i-2]) poisoned[i] = 1;
    ans += sig[i];
    i += sig[i];
  }
  cout << ans << endl;


  return 0;
}
