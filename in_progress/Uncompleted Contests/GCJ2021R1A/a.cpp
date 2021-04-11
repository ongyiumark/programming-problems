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

const int N = 100;
string X[N];

int compare(string a, string b){
  // a < b
  int n = a.size();
  int m = b.size();
  if (n == m){
    for (int i = 0; i < n; i++){
      if (a[i] < b[i]) return -1;
      if (a[i] > b[i]) return 1;
    }
    return 0;
  }
  else if (n < m) return -1;
  else return 1;
}
void testcase(){
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> X[i];
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    int cmp = compare(X[i-1], X[i]);
    if (cmp == -1) continue;
    if (cmp == 0) {
      X[i] += '0';
      cnt++;
    }
    else {
      int m = X[i].size();
      int n = X[i-1].size();
      int cmp1 = compare(X[i-1].substr(0,m), X[i]);
      if (cmp1 == -1) {
        X[i].append(n-m,'0');
        cnt += n-m;
      }
      else if (cmp1 == 1) {
        X[i].append(n-m+1,'0');
        cnt += n-m+1;
      }
      else {
        bool all9 = 1;
        for (int j = m; j < n; j++){
          if (X[i-1][j] != '9') all9 = 0;
          X[i] += X[i-1][j];
        }
        if (all9) {
          X[i] = X[i].substr(0,m);
          X[i].append(n-m+1, '0');
          cnt += n-m+1;
        }
        else {
          int sz = X[i].size();
          for (int j = sz-1; j >= m; j--){
            if (X[i][j] == '9') {
              X[i][j] = '0';
              continue;
            }
            X[i][j]++;
            break;
          }
          cnt += n-m;
        }
      }
    }
  }
  cout << cnt << endl;
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
