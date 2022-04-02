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

string a, b;
int stored[10];
int rep;
int n, m;

bool valid(int num){
  if (num == 0) return true;
  int curr[10];
  memset(curr, 0, sizeof curr);
  if (rep*(num-1)+n > m) return false;
  for (int i = 0; i < num-1; i++){
    for (int j = 0; j < rep; j++) {
      if (stored[b[j]-'0'] == curr[b[j]-'0']) return false;
      curr[b[j]-'0']++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (stored[b[i]-'0'] == curr[b[i]-'0']) return false;
    curr[b[i]-'0']++;
  }
  return true;
}

void testcase(){
  cin >> a >> b;
  memset(stored, 0, sizeof stored);

  for (char ch : a){
    stored[ch-'0']++;
  } 

  n = b.size();
  m = a.size();
  rep = n;
  for (int i = 1; i < n; i++) {
    bool ans = true;
    for (int j = 0; i+j < n; j++) {
      ans &= (b[j] == b[i+j]);
    }
    if (ans) {
      rep = i;
      break;
    }
  }
  //cout << rep << " ";

  int lo = 0;
  int hi = 1e5;
  ll ans = -1;
  while(lo <= hi){
    int mid = hi - (hi-lo)/2;
    if (valid(mid)) {
      ans = mid;
      lo = mid+1;
    }
    else hi = mid-1;
  }
  cout << ans << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    testcase();
  }
  return 0;
}
