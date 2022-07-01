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


int c2val(int i, int j, int n){
  return 0;
}
int dist(int i, int j, int n) {
  return abs(i-n/2)+abs(j-n/2);
}

void solve(int val, int n, int k){
  int curr = 0;
  int m = n;
  int ci = 0, cj = 0;
  if (curr+4*m-4 < val){
    curr += 4*m-4;
    ci++;
    cj++;
    m -= 2;
  }
  curr++;
  //cout << ci << " " << cj << " " << curr << endl;
  bool found = 0;
  while(curr < val || dist(ci, cj, n) != k) {
    // right
    for (int i = 0; i < m-1; i++) {
      curr++, cj++;
      if (curr >= val && dist(ci, cj, n) == k) found = 1;
    }
    if (found) break;
    // down
    for (int i = 0; i < m-1; i++) {
      curr++; ci++;
      if (curr >= val && dist(ci, cj, n) == k) found = 1;
    } 
    if (found) break;
    // left
    for (int i = 0; i < m-1; i++) {
      curr++; cj--;
      if (curr >= val && dist(ci, cj, n) == k) found = 1;
    }
    if (found) break;
    // up
    for (int i = 0; i < m-2; i++) {
      curr++; ci--;
      if (curr >= val && dist(ci, cj, n) == k) found = 1;
    }
    if (found) break;

    curr++; cj++;
  }

  // top left
  vector<int> tmp;
  tmp.push_back(curr);
  while(ci != n/2 || cj != n/2) {
    int di = (n/2-ci)/abs(ci-n/2);
    int dj = (n/2-cj)/abs(cj-n/2);
    ci += di;
    cj += dj;
    curr = 0;
  }


  if (ci < n/2) {
    while (ci == )
    if (cj < n/2) {
    
    }
    else if (cj > n/2) {

    }
    else {

    }
  }
  
  cout << ci << " " << cj << " -- " << curr << endl;
}

void testcase() {
  int n, k; cin >> n >> k;
  if (k < n-1) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  if (k%2 == 1) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  int curr = 1;
  int adv = k-(n-1);
  curr += adv;
  k -= adv;

  solve(curr, n, k);
}
  

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  for (int x = 1; x <= t; x++) {
    cout << "Case #" << x << ": ";
    testcase();
  }
  
  return 0;
}
