/*
  Modified longest increasing subsequence.
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
using ordered_set = __gnu_pbds::tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5+5;
int book[N];
int dp[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  int cnt = 0;
  vector<int> arr;
  for (int i = 0; i < n; i++){
    cin >> book[i];
    book[i]-=i;
  }
  
  arr.push_back(book[0]);
  for (int i = 1; i < n; i++){
    if (arr.back() <= book[i]) arr.push_back(book[i]);
    else {
      int lo = 0;
      int hi = (int)arr.size()-1;
      int ans = -1;
      while(lo <= hi){
        int mid = hi - (hi-lo)/2;
        if (arr[mid] > book[i]) {
          ans = mid;
          hi = mid-1;
        }
        else lo = mid+1;
      }
      arr[ans] = book[i];
    }
  }
  cout << n - (int)arr.size() << endl;

  return 0;
}
