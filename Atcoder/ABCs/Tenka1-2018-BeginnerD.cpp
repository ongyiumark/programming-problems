/*
  I stumbled upon a construction for triangle numbers, and it worked.
    Pick a length of the subsets.
    Construct S_i by taking 1 element from S_1 to S_{i-1} that hasn't been repeated yet.
    Then, fill the rest new numbers. Continue this until all numbers have been repeated. 
    This will generate a tuple of subsets for some triangle number N.
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

  ll n; cin >> n;
  ll lo = 1;
  ll hi = 1e5;
  ll ans = -1;
  while (lo <= hi){
    ll mid = hi-(hi-lo)/2;
    if (mid*(mid+1) >= 2*n){
      ans = mid;
      hi = mid-1;
    }
    else lo = mid+1;
  }
  //cout << ans << endl;

  if (ans*(ans+1)/2 != n){
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  cout << ans+1 << endl;

  int vals[ans+1][ans];
  int next = 1;
  int idx = -1;
  for (int i = 0; i < ans+1; i++){
    for (int j = 0; j < i; j++){
      vals[i][j] = vals[j][idx];
    }
    for (int j = i; j < ans; j++){
      vals[i][j] = next;
      next++;
    }
    idx++;
  }

  for (int i = 0; i < ans+1; i++){
    cout << ans << " ";
    for (int j = 0; j < ans; j++){
      cout << vals[i][j];
      cout << (j == ans-1 ? "\n" : " ");
    }
  }

  
  return 0;
}
