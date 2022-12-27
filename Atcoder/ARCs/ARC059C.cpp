/*
  The number that minimizes the squared distances is the mean of the set.
  Since we can only try integer numbers, try the closest integer above and below the mean.
    Get the minimum.
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
  int a[n];
  int total = 0;
  for (int i = 0; i < n; i++){
    cin >> a[i];
    total += a[i];
  }

  int ans1 = total/n;
  int ans2 =  ans1+1;
  int res1, res2;
  res1 = res2 = 0;
  for (int i = 0; i < n; i++){
    res1 += (a[i]-ans1)*(a[i]-ans1);
    res2 += (a[i]-ans2)*(a[i]-ans2);
  }

  cout << min(res1,res2) << endl;
  return 0;
}
