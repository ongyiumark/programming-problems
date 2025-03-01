/*
  Precompute the lengths of the towers.
  Tower b is the (b-a)-th tower.
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
  
  int a, b; cin >> a >> b;
  int arr[1000];
  for (int i = 0; i < 1000; i++){
    arr[i] = i;
    if (i > 0) arr[i] += arr[i-1];
  }

  cout << arr[b-a]-b << endl;
  return 0;
}
