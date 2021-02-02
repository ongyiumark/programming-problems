/*
  Just add starting from the second element to the second to the last element.
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
  int n; cin >> n;
  int total = 0;
  for (int i = 1; i <= n; i++){
    int e; cin >> e;
    if (i != 1 && i != n) total += e;
  }
  cout << total << endl;
  return 0;
}
