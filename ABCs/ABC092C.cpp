/*
  Get the total cost.
  For each spot i, subtract the cost(i-1,i) and cost(i, i+1), and add cost(i-1,i+1). 
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

const int N = 1e5+5;
int a[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  memset(a, 0, sizeof a);
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  ll total = 0;
  for (int i = 1; i <= n+1; i++){
    total += abs(a[i]-a[i-1]);
  }

  for (int i = 1; i <= n; i++){
    cout << total-abs(a[i]-a[i-1])-abs(a[i]-a[i+1])+abs(a[i-1]-a[i+1]) << endl;
  }
  return 0;
}
