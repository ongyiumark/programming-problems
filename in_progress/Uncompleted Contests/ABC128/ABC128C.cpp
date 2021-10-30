/*
  Try all 2^n combinations of switches and for each one, check if all bulbs are on.
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;

  vector<int> switches[n];
  for (int i = 0; i < m; i++){
    int k; cin >> k;
    for (int j = 0; j < k; j++){
      int tmp; cin >> tmp;
      tmp--;
      switches[tmp].push_back(i);
    }
  }  
  int p[m];
  for (int i = 0; i < m; i++){
    cin >> p[i];
  }

  int cnt = 0;
  int curr[m];
  for (int mask = 0; mask < (1<<n); mask++){
    memset(curr, 0, sizeof curr);
    for (int i = 0; i < n; i++){
      if (mask&(1<<i)){
        for (int x : switches[i]){
          curr[x]++;
        }
      }
    }

    bool valid = true;
    for (int i = 0; i < m; i++) {
      curr[i] += p[i];
      if (curr[i]%2 == 1) {
        valid = false;
        break;
      } 
    }
    cnt += valid;
  }
  cout << cnt << endl;
  return 0;
}
