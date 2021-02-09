/*
  We can binary search for the answer.
  Let m = n(n+1)/2 or the number of pairs (l,r).
  The median of medians is the largest number x such that cnt(> x) >= ceil(m/2).
    That is, a number y is the median of a list of numbers 
    only if the number of elements greater than y is at least ceil(m/2).
    
    y is largest number that satisfies this condition. 

  So, we need to count the number of subarrays whose median is >= x.
  Let a be the number of elements greater than x. Let b be the number of elements less than x.
  The median is >= x if a >= b.

  If the number is greater than x, we turn it to 1. Otherwise, we turn it to -1.
  a >= b if the prefix sum is positive.
  So, we want to count how many i < j such that pref[i] <= pref[j]. This is a counting inversions problem.
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
using ordered_set = __gnu_pbds::tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5;
int a[N], tmp[N];
ll n;

bool valid(int x){
  for (int i = 0; i < n; i++){
    tmp[i] = (a[i] >= x ? 1 : -1);
    if (i > 0) tmp[i] += tmp[i-1];
  }
  ll m = (n*(n+1)/2 + 1)/2;
  ll total = 0;
  ordered_set<int> cnt;
  cnt.insert(0);
  for (int i = 0; i < n; i++){
    total += cnt.order_of_key(tmp[i]+1);
    cnt.insert(tmp[i]);
  }
  return total >= m;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int lo = 1;
  int hi = 1e9;
  int ans = -1;
  while(lo <= hi){
    int mid = hi-(hi-lo)/2;
    if (valid(mid)){
      ans = mid;
      lo = mid+1;
    }
    else hi = mid-1;
  }
  cout << ans << endl;
  return 0;
}
