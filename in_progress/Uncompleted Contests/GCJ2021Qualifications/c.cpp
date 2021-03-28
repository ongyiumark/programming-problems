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

int c, n;
const int N = 100;
int seq[N];

void rev(int i, int j){
  for (int x = 0; x < j-i+1; x++){
    if (i+x >= j-x) break;
    swap(seq[i+x], seq[j-x]);
  }
}

void testcase(){
  cin >> n >> c;
  // minimum is n-1 (perfectly sorted)
  // uppperbound: n(n+1)/2 - 1
  if (c < n-1 || c > n*(n+1)/2-1) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  c -= n-1;
  vector<int> need;
  for (int i = n; i >= 2; i--){
    if (c-i+1 >= 0) {
      c -= i-1;
      need.push_back(n-i);
    }
  }
  reverse(need.begin(), need.end());
  iota(seq, seq+n, 1);

  for (auto idx : need){
    rev(idx, n-1);
  }
  
  for (int i = 0; i < n; i++){
    cout << seq[i];
    if (i != n-1) cout << " "; 
  }
  cout << endl;
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
