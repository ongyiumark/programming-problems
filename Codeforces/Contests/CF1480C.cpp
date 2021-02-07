/*
  Peak finding with binary search.
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

int query(int i){
  cout << "? " << i << endl;
  int a; cin >> a;
  return a; 
}

void answer(int k){
  cout << "! " << k << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  if (n == 1){
    answer(1);
    return 0;
  }

  if (query(1) < query(2)) {
    answer(1);
    return 0;
  }

  if (query(n) < query(n-1)){
    answer(n);
    return 0;
  }

  int lo = 2;
  int hi = n-1;
  while(lo <= hi){
    int mid = hi-(hi-lo)/2;
    int a = query(mid-1);
    int b = query(mid);
    int c = query(mid+1);

    if (b < min(a,c)) {
      answer(mid);
      return 0;
    }

    if (a < b && b < c) hi = mid-1;
    else if (a > b && b > c) lo = mid+1;
    else lo = mid+1;
  }
  return 0;
}
