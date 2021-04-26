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

const int N = 20+1;
int U[N];
void testcase(){
  int n, a, b; cin >> n >> a >> b;
  int hi = 1;
  for (int i = 1; i <= n; i++){
    cin >> U[i];
    if (U[i] > 0) hi = i;
  }
  if (a != 1 || b != 2) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  for (int x = hi+1; x < 100; x++){
    multiset<int> nums;
    for (int i = 1; i <= n; i++){
      for (int j = 0; j < U[i]; j++){
        nums.insert(i);
      }
    }

    multiset<int,greater<int>> curr;
    curr.insert(x);
    while(curr.size() > 0 && nums.size() > 0){
      int c = *curr.begin();
      if (nums.find(c) != nums.end()){
        nums.erase(nums.find(c));
        curr.erase(curr.find(c));
      }
      else {
        curr.erase(curr.find(c));
        if (c-1 > 0) curr.insert(c-1);
        if (c-2 > 0) curr.insert(c-2);
      }
    }
    if (nums.size() == 0){
      cout << x << endl;
      return;
    }
  }

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
