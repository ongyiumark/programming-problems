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
int L[N];

void rev(int i, int j){
  for (int x = 0; x < j-i+1; x++){
    if (i+x >= j-x) break;
    swap(L[i+x], L[j-x]);
  }
}

void testcase(){
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> L[i];
  int ans = 0;
  for (int i = 0; i < n-1; i++){
    int minidx = i;
    int hi = 1000;
    for (int j = i; j < n; j++){
      if (hi > L[j]){
        hi = L[j];
        minidx = j;
      }
    }

    ans += minidx-i+1;
    rev(i, minidx);
  }
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
